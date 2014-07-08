#include "ch.h"
#include "hal.h"
#include "lwipthread.h"

#include <r2p/Middleware.hpp>
#include "r2p/node/led.hpp"

#include <urosconf.h>
#include <urosBase.h>
#include <urosUser.h>
#include <urosNode.h>

static WORKING_AREA(wa_info, 1024);

r2p::Middleware r2p::Middleware::instance("GW_0", "BOOT_GW_0");

// RTCAN transport
static r2p::RTCANTransport rtcantra(RTCAND1);

RTCANConfig rtcan_config = { 1000000, 100, 60 };

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

	/* Led 2 subscriber. */
	r2p::ledsub_conf ledsub_conf = {"led2"};
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(1024), NORMALPRIO + 1, r2p::ledsub_node, (void *) &ledsub_conf, "led2sub");

	/* Led 3 subscriber. */
	ledsub_conf.topic = "led3";
	r2p::Thread::create_heap(NULL, THD_WA_SIZE(1024), NORMALPRIO + 1, r2p::ledsub_node, (void *) &ledsub_conf, "led3sub");

	urosInit();
	urosNodeCreateThread();

	/*
	 * Normal main() thread activity, in this demo it does nothing except
	 * sleeping in a loop and check the button state.
	 */
	while (TRUE) {
		palTogglePad(LED1_GPIO, LED1);
		r2p::Thread::sleep(r2p::Time::s(1));
	}
}
