#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"
#include "lwipthread.h"

#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"

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
				(uint32_t) (tp->p_refs - 1), states[tp->p_state],
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
 * TCP connection handler thread.
 */
static msg_t conn_thread(void *arg) {
	struct netconn * conn = (struct netconn *) arg;
	struct netbuf *inbuf;
	char *buf;
	u16_t buflen;
	err_t err;

	chRegSetThreadName("conn");

	while (TRUE) {
		err = netconn_recv(conn, &inbuf);

		if (err == ERR_OK) {
			netbuf_data(inbuf, (void **) &buf, &buflen);
//			netconn_write(conn, &buf, buflen, NETCONN_NOCOPY);
			netconn_write(conn, "hello world!", sizeof("hello world!") - 1, NETCONN_NOCOPY);
			netbuf_delete(inbuf);
		}
	}

	netconn_close(conn);
	netconn_delete(conn);


	return RDY_OK;
}

/*
 * TCP server thread.
 */
static msg_t server_thread(void *arg) {
	uint16_t port = *((uint16_t *) arg);
	struct netconn *conn, *newconn;
	Thread *conntp = NULL;
	err_t err;

	chRegSetThreadName("server");

	/* Create a new TCP connection handle */
	conn = netconn_new(NETCONN_TCP);
	LWIP_ERROR("TCP server: invalid conn", (conn != NULL), return RDY_RESET;);

	/* Bind to port 80 (HTTP) with default IP address */
	netconn_bind(conn, NULL, port);

	/* Put the connection into LISTEN state */
	netconn_listen(conn);

	while (TRUE) {
		err = netconn_accept(conn, &newconn);
		if (err != ERR_OK)
			continue;

		if (!(conntp = chThdCreateFromHeap(NULL, 8192, NORMALPRIO, conn_thread,
				newconn))) {
			chprintf((BaseSequentialStream *) &SERIAL_DRIVER,
					"conn_thread()\r\n");
		}

		chThdWait(conntp);
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
	chThdCreateStatic(wa_lwip_thread, THD_WA_SIZE(LWIP_THREAD_STACK_SIZE),
			NORMALPRIO + 1, lwip_thread, NULL);

	/*
	 * Creates the server thread.
	 */
	uint16_t port = 80;
	chThdCreateFromHeap(NULL, 1024, NORMALPRIO, server_thread, &port);

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
