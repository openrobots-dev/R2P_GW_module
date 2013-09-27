#include "ch.h"
#include "hal.h"
#include "rtcan.h"

#include "shell.h"
#include "chprintf.h"
#include "lwipthread.h"

#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"

#include "netstream.h"

#include <r2p/common.hpp>
#include <r2p/Middleware.hpp>
#include <r2p/Node.hpp>
#include <r2p/Topic.hpp>
#include <r2p/Publisher.hpp>
#include <r2p/Subscriber.hpp>
#include <r2p/Mutex.hpp>
#include <r2p/NamingTraits.hpp>
#include "r2p/transport/DebugTransport.hpp"
#include "r2p/transport/RTCANTransport.hpp"

extern "C" {
void *__dso_handle;
void __cxa_pure_virtual() {
	chSysHalt();
}
void _exit(int) {
	chSysHalt();
	for (;;) {
	}
}
int _kill(int, int) {
	chSysHalt();
	return -1;
}
int _getpid() {
	return 1;
}
} // extern "C"

static WORKING_AREA(wa_info, 1024);

r2p::Middleware r2p::Middleware::instance("GW_0", "BOOT_GW_0");

static char dbgtra_namebuf[64];
static char netdbgtra_namebuf[64];

// Debug transport

static r2p::DebugTransport dbgtra("dbg", reinterpret_cast<BaseChannel *>(&SERIAL_DRIVER), dbgtra_namebuf);

static WORKING_AREA(wa_rx_dbgtra, 1024);
static WORKING_AREA(wa_tx_dbgtra, 1024);

static WORKING_AREA(wa_rx_netdbgtra, 1024);
static WORKING_AREA(wa_tx_netdbgtra, 1024);

// RTCAN transport
static r2p::RTCANTransport rtcantra(RTCAND1);

RTCANConfig rtcan_config = { 1000000, 100, 60 };

/*===========================================================================*/
/* Application threads.                                                      */
/*===========================================================================*/

struct LedMsg: public r2p::Message {
	uint32_t led;
	uint32_t value;
	uint32_t cnt;
} R2P_PACKED;

/*
 * Led publisher node
 */
static msg_t ledpub_node(void *arg) {
	r2p::Node node("ledpub");
	r2p::Publisher<LedMsg> led_pub;
	char * tnp = (char *) arg;
	systime_t time = chTimeNow();
	const uint16_t period = 500;
	uint32_t toggle = 0;
	uint32_t cnt = 0;

	(void)arg;

	chRegSetThreadName("ledpub");
	node.advertise(led_pub, tnp);

	for (;;) {
		LedMsg *msgp;
		if (led_pub.alloc(msgp)) {
			msgp->led = 2;
			msgp->value = toggle;
			if (!led_pub.publish(*msgp)) {
				chSysHalt();
			}
			toggle ^= 1;
			cnt++;
		}

		time += MS2ST(period);
		chThdSleepUntil(time);
	}
	return CH_SUCCESS;
}

/*
 * Led subscriber node
 */

bool callback(const LedMsg &msg) {

	palWritePad((GPIO_TypeDef *)led2gpio(msg.led), led2pin(msg.led), msg.value);

	return true;
}

msg_t ledsub_node(void * arg) {
	LedMsg sub_msgbuf[5], *sub_queue[5];
	r2p::Node node("ledpub");
    r2p::Subscriber<LedMsg> sub(sub_queue, 5, callback);
	char * tnp = (char *) arg;

	chRegSetThreadName("ledsub");

	node.subscribe(sub, tnp, sub_msgbuf);

	for (;;) {
		node.spin(1000);
	}
	return CH_SUCCESS;
}

/*
 * RTCAN LED blinker thread, times are in milliseconds.
 */
static WORKING_AREA(waThread1, 128);
static msg_t Thread1(void *arg) {

	(void) arg;

	chRegSetThreadName("blinker");

	while (TRUE) {
		switch (RTCAND1.state) {
			case RTCAN_MASTER:
				palClearPad(LED12_GPIO, LED1);
				chThdSleepMilliseconds(200);
				palSetPad(LED12_GPIO, LED1);
				chThdSleepMilliseconds(100);
				palClearPad(LED12_GPIO, LED1);
				chThdSleepMilliseconds(200);
				palSetPad(LED12_GPIO, LED1);
				chThdSleepMilliseconds(500);
				break;
			case RTCAN_SYNCING:
				palTogglePad(LED12_GPIO, LED1);
				chThdSleepMilliseconds(100);
				break;
			case RTCAN_SLAVE:
				palTogglePad(LED12_GPIO, LED1);
				chThdSleepMilliseconds(500);
				break;
			case RTCAN_ERROR:
				palTogglePad(LED34_GPIO, LED4);
				chThdSleepMilliseconds(200);
				break;
			default:
				chThdSleepMilliseconds(100);
				break;
			}
	}
	return 0;
}
/*
 * TCP server thread.
 */
static msg_t server_thread(void *arg) {
	uint16_t port = *((uint16_t *) arg);
	struct netconn *conn, *newconn;
	err_t err;

	chRegSetThreadName("server");

	/* Create a new TCP connection handle */
	conn = netconn_new(NETCONN_TCP);
	LWIP_ERROR("TCP server: invalid conn", (conn != NULL), return RDY_RESET;);

	/* Bind to a port. */
	netconn_bind(conn, NULL, port);

	/* Listen for connections. */
	netconn_listen(conn);

	while (TRUE) {
		err = netconn_accept(conn, &newconn);
		if (err != ERR_OK)
			continue;

		/* Dynamic allocation to allow multiple shell instances. */
		NetStream * nsp = (NetStream *) chHeapAlloc(NULL, sizeof(NetStream));
		ShellConfig * shell_cfgp = (ShellConfig *) chHeapAlloc(NULL, sizeof(ShellConfig));

		if (nsp && shell_cfgp) {
			nsObjectInit(nsp);
			nsStart(nsp, newconn);

			// Debug transport
			static r2p::DebugTransport netdbgtra("netdbg", reinterpret_cast<BaseChannel *>(nsp), netdbgtra_namebuf);

			r2p::Thread::set_priority(r2p::Thread::HIGHEST);

			netdbgtra.initialize(wa_rx_netdbgtra, sizeof(wa_rx_netdbgtra), r2p::Thread::LOWEST + 11, wa_tx_netdbgtra,
					sizeof(wa_tx_netdbgtra), r2p::Thread::LOWEST + 10);

			r2p::Thread::set_priority(r2p::Thread::NORMAL);

			/*
			 shell_cfgp->sc_channel = (BaseSequentialStream *) nsp;
			 shell_cfgp->sc_commands = commands;

			 shellCreate(shell_cfgp, SHELL_WA_SIZE, NORMALPRIO - 1);
			 */
		}
	}
	return RDY_OK;
}

/*
 * Application entry point.
 */
int main(void) {
	Thread *shelltp = NULL;

	/*
	 * System initializations.
	 * - HAL initialization, this also initializes the configured device drivers
	 *   and performs the board-specific initializations.
	 * - Kernel initialization, the main() function becomes a thread and the
	 *   RTOS is active.
	 */
	halInit();
	chSysInit();

	/*
	 * Activates the serial driver 1 using the driver default configuration.
	 */
	sdStart(&SERIAL_DRIVER, NULL);

	/*
	 * Creates the blinker thread.
	 */
	chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

	/* Make the PHY wake up.*/
	palSetPad(GPIOC, GPIOC_ETH_NOT_PWRDN);

	/* Creates the LWIP thread (it changes priority internally).*/
	chThdCreateStatic(wa_lwip_thread, THD_WA_SIZE(LWIP_THREAD_STACK_SIZE), NORMALPRIO + 1, lwip_thread, NULL);
	/*
	 * Creates the server thread.
	 */
	uint16_t port = 23;
	chThdCreateFromHeap(NULL, 8192, NORMALPRIO, server_thread, &port);

	r2p::Thread::set_priority(r2p::Thread::HIGHEST);
	r2p::Middleware::instance.initialize(wa_info, sizeof(wa_info), r2p::Thread::IDLE);

	dbgtra.initialize(wa_rx_dbgtra, sizeof(wa_rx_dbgtra), r2p::Thread::LOWEST + 11, wa_tx_dbgtra, sizeof(wa_tx_dbgtra),
			r2p::Thread::LOWEST + 10);

	rtcantra.initialize(rtcan_config);

	r2p::Thread::set_priority(r2p::Thread::NORMAL);

	r2p::Thread::create_heap(NULL, THD_WA_SIZE(1024), NORMALPRIO + 2, ledpub_node, (void*) "leds");
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(1024), NORMALPRIO + 1, ledsub_node, (void*) "leds");

	/*
	 * Normal main() thread activity, in this demo it does nothing except
	 * sleeping in a loop and check the button state.
	 */
	while (TRUE) {
		chThdSleepMilliseconds(500);
	}
}
