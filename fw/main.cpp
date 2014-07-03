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

#include "r2p/node/led.hpp"

#include <urosBase.h>
#include <urosUser.h>
#include <urosNode.h>

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

#ifndef R2P_MODULE_NAME
#define R2P_MODULE_NAME "IR"
#endif

static WORKING_AREA(wa_info, 1024);
static r2p::RTCANTransport rtcantra(RTCAND1);

RTCANConfig rtcan_config = { 1000000, 100, 60 };

r2p::Middleware r2p::Middleware::instance(R2P_MODULE_NAME, "BOOT_"R2P_MODULE_NAME);
/*===========================================================================*/
/* Application threads.                                                      */
/*===========================================================================*/

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

	r2p::Middleware::instance.initialize(wa_info, sizeof(wa_info), r2p::Thread::LOWEST);
	rtcantra.initialize(rtcan_config);
	r2p::Middleware::instance.start();

	/* Make the PHY wake up.*/
	palSetPad(GPIOC, GPIOC_ETH_NOT_PWRDN);

	/* Creates the LWIP thread (it changes priority internally).*/
	chThdCreateStatic(wa_lwip_thread, THD_WA_SIZE(LWIP_THREAD_STACK_SIZE), NORMALPRIO + 5, lwip_thread, NULL);

	chThdSleepMilliseconds(100);
/*
	r2p::ledpub_conf ledpub_conf = {"led2", 2};
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(512), NORMALPRIO + 1, r2p::ledpub_node, (void *) &ledpub_conf, "led2sub");

	r2p::ledsub_conf ledsub_conf = {"led2"};
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(512), NORMALPRIO + 1, r2p::ledsub_node, (void *) &ledsub_conf, "led2pub");

	ledsub_conf.topic = "led3";
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(512), NORMALPRIO + 1, r2p::ledsub_node, (void *) &ledsub_conf, "led3pub");
*/
	urosInit();
	urosNodeCreateThread();

	/*
	 * Normal main() thread activity, in this demo it does nothing except
	 * sleeping in a loop and check the button state.
	 */
	while (TRUE) {
		palTogglePad(LED1_GPIO, LED1);
		r2p::Thread::sleep(r2p::Time::ms(500));
	}
}
