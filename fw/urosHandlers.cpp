/**
 * @file    urosHandlers.c
 * @author  TODO
 *
 * @brief   TCPROS topic and service handlers.
 */

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include "urosHandlers.h"

#include <urosNode.h>
#include <urosTcpRos.h>
#include <urosUser.h>
#include <r2p/common.hpp>
#include <r2p/Middleware.hpp>
#include <r2p/Node.hpp>
#include <r2p/Publisher.hpp>
#include <r2p/Subscriber.hpp>

#include <r2p/msg/led.hpp>

/*===========================================================================*/
/* GLOBAL VARIABLES                                                          */
/*===========================================================================*/
r2p::Node led2sub_node("uled2sub", false);
r2p::Subscriber<r2p::LedMsg, 2> led2_sub;

r2p::Node led3sub_node("uled3sub", false);
r2p::Subscriber<r2p::LedMsg, 2> led3_sub;

r2p::Node led2pub_node("uled2pub", false);
r2p::Publisher<r2p::LedMsg> led2_pub;

r2p::Node led3pub_node("uled3pub", false);
r2p::Publisher<r2p::LedMsg> led3_pub;

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /r2p/led2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/led2</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/led2</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__led2(UrosTcpRosStatus *tcpstp) {
	r2p::LedMsg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Led);

	if (first_time) {
		led2sub_node.subscribe(led2_sub, "led2");
		led2sub_node.set_enabled(true);
	}


	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (led2sub_node.spin(r2p::Time::ms(1000))) {
			while (led2_sub.fetch(msgp)) {
				msg.led = msgp->led;
				msg.value = msgp->value;
				led2_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Led);
				UROS_MSG_SEND_BODY(&msg, msg__r2p__Led);

				/* Dispose the contents of the message.*/
				clean_msg__r2p__Led(&msg);
			}
		}
	}

	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	led2sub_node.set_enabled(false);
	while (led2_sub.fetch(msgp)) {
		led2_sub.release(*msgp);
	}
	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__Led);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /r2p/led3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/led3</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/led3</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__led3(UrosTcpRosStatus *tcpstp) {
	r2p::LedMsg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Led);

	if (first_time) {
		led3sub_node.subscribe(led3_sub, "led3");
		first_time = false;
	}

	led3sub_node.set_enabled(true);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (led3sub_node.spin(r2p::Time::ms(1000))) {
			while (led3_sub.fetch(msgp)) {
				msg.led = msgp->led;
				msg.value = msgp->value;
				led3_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Led);
				UROS_MSG_SEND_BODY(&msg, msg__r2p__Led);

				/* Dispose the contents of the message.*/
				clean_msg__r2p__Led(&msg);

			}
		}
	}

	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	led3sub_node.set_enabled(false);
	while (led3_sub.fetch(msgp)) {
		led3_sub.release(*msgp);
	}
	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__Led);
	return tcpstp->err;
}

/** @} */

/** @} */

/*===========================================================================*/
/* SUBSCRIBED TOPIC FUNCTIONS                                                */
/*===========================================================================*/

/** @addtogroup tcpros_subtopic_funcs */
/** @{ */

/*~~~ SUBSCRIBED TOPIC: /r2p/led2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/led2</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/led2</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__r2p__led2(UrosTcpRosStatus *tcpstp) {
	r2p::LedMsg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Led);

	if (first_time) {
		led2pub_node.advertise(led2_pub, "led2", r2p::Time::INFINITE);
		led2pub_node.set_enabled(true);
	}

	/* Subscribed messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		/* Receive the next message.*/
		UROS_MSG_RECV_LENGTH()
		;
		UROS_MSG_RECV_BODY(&msg, msg__r2p__Led);

		/* TODO: Process the received message.*/

		if (led2_pub.alloc(msgp)) {
			msgp->led = msg.led;
			msgp->value = msg.value;
		}

		led2_pub.publish(*msgp);

		/* Dispose the contents of the message.*/
		clean_msg__r2p__Led(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	led2pub_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__Led);
	return tcpstp->err;
}

/** @} */

/*~~~ SUBSCRIBED TOPIC: /r2p/led3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/led3</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/led3</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__r2p__led3(UrosTcpRosStatus *tcpstp) {
	r2p::LedMsg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Led);

	if (first_time) {
		led3pub_node.advertise(led3_pub, "led3", r2p::Time::INFINITE);
		led3pub_node.set_enabled(true);
	}

	/* Subscribed messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		/* Receive the next message.*/
		UROS_MSG_RECV_LENGTH()
		;
		UROS_MSG_RECV_BODY(&msg, msg__r2p__Led);

		/* TODO: Process the received message.*/

		if (led3_pub.alloc(msgp)) {
			msgp->led = msg.led;
			msgp->value = msg.value;
		}

		led3_pub.publish(*msgp);

		/* Dispose the contents of the message.*/
		clean_msg__r2p__Led(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	led3pub_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__Led);
	return tcpstp->err;
}

/** @} */

/** @} */

/*===========================================================================*/
/* PUBLISHED SERVICE FUNCTIONS                                               */
/*===========================================================================*/

/** @addtogroup tcpros_pubservice_funcs */
/** @{ */

/* There are no published services.*/

/** @} */

/*===========================================================================*/
/* CALLED SERVICE FUNCTIONS                                                  */
/*===========================================================================*/

/** @addtogroup tcpros_callservice_funcs */
/** @{ */

/* There are no called services.*/

/** @} */

/*===========================================================================*/
/* GLOBAL FUNCTIONS                                                          */
/*===========================================================================*/

/** @addtogroup tcpros_funcs */
/** @{ */

/**
 * @brief   Registers all the published topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersPublishTopics(void) {

	/* /r2p/led2 */
	urosNodePublishTopicSZ("/r2p/led2", "r2p/Led", (uros_proc_f) pub_tpc__r2p__led2, uros_nulltopicflags);

	/* /r2p/led3 */
	urosNodePublishTopicSZ("/r2p/led3", "r2p/Led", (uros_proc_f) pub_tpc__r2p__led3, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

	/* /r2p/led2 */
	urosNodeUnpublishTopicSZ("/r2p/led2");

	/* /r2p/led3 */
	urosNodeUnpublishTopicSZ("/r2p/led3");
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

	/* /r2p/led2 */
	urosNodeSubscribeTopicSZ("/r2p/led2", "r2p/Led", (uros_proc_f) sub_tpc__r2p__led2, uros_nulltopicflags);

	/* /r2p/led3 */
	urosNodeSubscribeTopicSZ("/r2p/led3", "r2p/Led", (uros_proc_f) sub_tpc__r2p__led3, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

	/* /r2p/led2 */
	urosNodeUnsubscribeTopicSZ("/r2p/led2");

	/* /r2p/led3 */
	urosNodeUnsubscribeTopicSZ("/r2p/led3");
}

/**
 * @brief   Registers all the published services to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersPublishServices(void) {

	/* No services to publish.*/
}

/**
 * @brief   Unregisters all the published services to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishServices(void) {

	/* No services to unpublish.*/
}

/** @} */

