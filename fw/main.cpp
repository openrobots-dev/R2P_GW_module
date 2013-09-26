#include "ch.h"
#include "hal.h"

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

struct LedMsg: public r2p::Message {
	uint32_t led;
	uint32_t value;
	uint32_t cnt;
} R2P_PACKED;

void *__dso_handle;

extern "C" void __cxa_pure_virtual() {
}

static WORKING_AREA(wa_info, 1024);

r2p::Middleware r2p::Middleware::instance("IMU_0", "BOOT_IMU_0");

static WORKING_AREA(wa1, 1024);
static WORKING_AREA(wa2, 1024);
static WORKING_AREA(wa3, 1024);

static char dbgtra_namebuf[64];

// Debug transport

static r2p::DebugTransport dbgtra(reinterpret_cast<BaseChannel *>(&SD1), dbgtra_namebuf);
//static r2p::DebugTransport dbgtra(reinterpret_cast<BaseSequentialStream *>(&SD1), dbgtra_namebuf);

static WORKING_AREA(wa_rx_dbgtra, 1024);
static WORKING_AREA(wa_tx_dbgtra, 1024);

/*===========================================================================*/
/* Command line related.                                                     */
/*===========================================================================*/

#define SHELL_WA_SIZE   THD_WA_SIZE(4096)
#define TEST_WA_SIZE    THD_WA_SIZE(1024)

static void cmd_mem(BaseSequentialStream *chp, int argc, char *argv[]) {
	size_t n, size;

	(void) argv;
	if (argc > 0) {
		chprintf(chp, "Usage: mem\r\n");
		return;
	}
	n = chHeapStatus(NULL, &size);
	chprintf(chp, "core free memory : %u bytes\r\n", chCoreStatus());
	chprintf(chp, "heap fragments   : %u\r\n", n);
	chprintf(chp, "heap free total  : %u bytes\r\n", size);
}

static void cmd_threads(BaseSequentialStream *chp, int argc, char *argv[]) {
	static const char *states[] = { THD_STATE_NAMES };
	Thread *tp;

	(void) argv;
	if (argc > 0) {
		chprintf(chp, "Usage: threads\r\n");
		return;
	}
	chprintf(chp, "    addr    stack prio refs     state time\r\n");
	tp = chRegFirstThread();
	do {
		chprintf(chp, "%.8lx %.8lx %4lu %4lu %9s %lu\r\n", (uint32_t) tp,
				(uint32_t) tp->p_ctx.r13, (uint32_t) tp->p_prio,
				(uint32_t)(tp->p_refs - 1), states[tp->p_state],
				(uint32_t) tp->p_time);
		tp = chRegNextThread(tp);
	} while (tp != NULL);
}

static const ShellCommand commands[] = { { "mem", cmd_mem }, { "threads",
		cmd_threads }, { NULL, NULL } };

static const ShellConfig shell_cfg = { (BaseSequentialStream *) &SERIAL_DRIVER,
		commands };

/*===========================================================================*/
/* Application threads.                                                      */
/*===========================================================================*/

/*
 * Red LED blinker thread, times are in milliseconds.
 */
static WORKING_AREA(waThread1, 128);
static msg_t Thread1(void *arg) {

	(void) arg;

	chRegSetThreadName("blinker");
	while (TRUE) {
		palTogglePad(LED_GPIO, LED1);
		chThdSleepMilliseconds(500);
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
		ShellConfig * shell_cfgp = (ShellConfig *) chHeapAlloc(NULL,
				sizeof(ShellConfig));

		if (nsp && shell_cfgp) {
			nsObjectInit(nsp);
			nsStart(nsp, newconn);

			// Debug transport
//			static r2p::DebugTransport dbgtra(
//					reinterpret_cast<BaseSequentialStream *>(nsp), dbgtra_namebuf);

			r2p::Thread::set_priority(r2p::Thread::HIGHEST);

			dbgtra.initialize(wa_rx_dbgtra, sizeof(wa_rx_dbgtra),
					r2p::Thread::LOWEST + 11, wa_tx_dbgtra,
					sizeof(wa_tx_dbgtra), r2p::Thread::LOWEST + 10);

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
	 * Shell manager initialization.
	 */
	shellInit();

	/*
	 * Creates the blinker thread.
	 */
	chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

	/* Make the PHY wake up.*/
	palSetPad(GPIOC, GPIOC_ETH_NOT_PWRDN);

	/* Creates the LWIP thread (it changes priority internally).*/
//	chThdCreateStatic(wa_lwip_thread, THD_WA_SIZE(LWIP_THREAD_STACK_SIZE),
//			NORMALPRIO + 1, lwip_thread, NULL);

	/*
	 * Creates the server thread.
	 */
	uint16_t port = 23;
//	chThdCreateFromHeap(NULL, 1024, NORMALPRIO, server_thread, &port);

	r2p::Thread::set_priority(r2p::Thread::HIGHEST);
	r2p::Middleware::instance.initialize(wa_info, sizeof(wa_info),
			r2p::Thread::IDLE);

//	 dbgtra.initialize(wa_rx_dbgtra, sizeof(wa_rx_dbgtra),
//	 r2p::Thread::LOWEST + 11, wa_tx_dbgtra, sizeof(wa_tx_dbgtra),
//	 r2p::Thread::LOWEST + 10);

	r2p::Thread::set_priority(r2p::Thread::NORMAL);

	/*
	 * Normal main() thread activity, in this demo it does nothing except
	 * sleeping in a loop and check the button state.
	 */
	while (TRUE) {

		if (!shelltp)
			shelltp = shellCreate(&shell_cfg, SHELL_WA_SIZE, NORMALPRIO - 1);
		else if (chThdTerminated(shelltp)) {
			chThdRelease(shelltp);
			shelltp = NULL;
		}
		chThdSleepMilliseconds(500);
	}
}
