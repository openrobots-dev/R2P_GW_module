#include "ch.h"
#include "hal.h"
#include "rtcan.h"

//#include "shell.h"
//#include "netstream.h"

#include <urosconf.h>
#include <urosBase.h>
#include <urosUser.h>
#include <urosNode.h>
#include <lwipthread.h>

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

#include "r2p/node/led.hpp"

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

// RTCAN transport
static r2p::RTCANTransport rtcantra(RTCAND1);

RTCANConfig rtcan_config = { 1000000, 100, 60 };

int activity = 0;

/*===========================================================================*/
/* Application threads.                                                      */
/*===========================================================================*/

/*
 * Application entry point.
 */
int main(void) {

	/*
	 * System initializations.
	 * - HAL initialization, this also initializes the configured device drivers
	 *   and performs the board-specific initializations.
	 * - Kernel initialization, the main() function becomes a thread and the
	 *   RTOS is active.
	 */
	halInit();
	chSysInit();

	palClearPad(LED1_GPIO, LED1);
	palClearPad(LED2_GPIO, LED2);
	palClearPad(LED3_GPIO, LED3);
	palClearPad(LED4_GPIO, LED4);
	chThdSleepMilliseconds(500);
	palSetPad(LED1_GPIO, LED1);
	palSetPad(LED2_GPIO, LED2);
	palSetPad(LED3_GPIO, LED3);
	palSetPad(LED4_GPIO, LED4);

	/*
	 * Activates the serial driver 1 using the driver default configuration.
	 */
	sdStart(&SERIAL_DRIVER, NULL);

	r2p::Middleware::instance.initialize(wa_info, sizeof(wa_info), r2p::Thread::LOWEST);
	rtcantra.initialize(rtcan_config);
	r2p::Middleware::instance.start();

	/* Make the PHY wake up.*/
	palSetPad(GPIOC, GPIOC_ETH_NOT_PWRDN);

	/* Creates the LWIP thread (it changes priority internally).*/
	chThdCreateStatic(wa_lwip_thread, THD_WA_SIZE(LWIP_THREAD_STACK_SIZE), NORMALPRIO + 5, lwip_thread, NULL);

	chThdSleepMilliseconds(100);

	int led = 1;
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(512), NORMALPRIO + 1, r2p::ledpub_node, &led);
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(512), NORMALPRIO + 1, r2p::ledsub_node, NULL);

//	urosInit();
//	urosNodeCreateThread();

	/*
	 * Normal main() thread activity, in this demo it does nothing except
	 * sleeping in a loop and check the button state.
	 */
	while (TRUE) {
		r2p::Thread::sleep(r2p::Time::s(20));
		continue;
		if (activity == 0) {
			NVIC_SystemReset();
		}
		activity = 0;
	}
}
