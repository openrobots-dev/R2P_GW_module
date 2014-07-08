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
#include <r2p/msg/motor.hpp>
#include <r2p/msg/imu.hpp>

/*===========================================================================*/
/* GLOBAL VARIABLES                                                          */
/*===========================================================================*/
/*
 * Proximity measurement message definition.
 */
struct ProximityMsg: public r2p::Message {
	float distance;
}R2P_PACKED;

r2p::Node irsub_node("uirsub", false);
r2p::Subscriber<ProximityMsg, 2> ir_sub;

r2p::Node led2sub_node("uled2sub", false);
r2p::Subscriber<r2p::LedMsg, 2> led2_sub;

r2p::Node sonarsub_node("usonarsub", false);
r2p::Subscriber<ProximityMsg, 2> sonar_sub;

r2p::Node led3pub_node("uled3pub", false);
r2p::Publisher<r2p::LedMsg> led3_pub;

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /r2p/ir ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/ir</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/ir</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__ir(UrosTcpRosStatus *tcpstp) {
	ProximityMsg *msgp;

	irsub_node.subscribe(ir_sub, "ir");
	irsub_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__std_msgs__Float32);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (irsub_node.spin(r2p::Time::ms(1000))) {
			while (ir_sub.fetch(msgp)) {
				msg.data = msgp->distance;
				ir_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__std_msgs__Float32);
				UROS_MSG_SEND_BODY(&msg, msg__std_msgs__Float32);

				/* Dispose the contents of the message.*/
				clean_msg__std_msgs__Float32(&msg);

			}
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	irsub_node.set_enabled(false);
	while (ir_sub.fetch(msgp)) {
		ir_sub.release(*msgp);
	}

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__std_msgs__Float32);
	return tcpstp->err;
}

/** @} */

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

	led2sub_node.subscribe(led2_sub, "led2");
	led2sub_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Led);

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

/*~~~ PUBLISHED TOPIC: /r2p/sonar ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/sonar</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/sonar</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__sonar(UrosTcpRosStatus *tcpstp) {
	ProximityMsg *msgp;

	sonarsub_node.subscribe(sonar_sub, "sonar");
	sonarsub_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__std_msgs__Float32);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (sonarsub_node.spin(r2p::Time::ms(1000))) {
			while (sonar_sub.fetch(msgp)) {
				msg.data = msgp->distance;
				sonar_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__std_msgs__Float32);
				UROS_MSG_SEND_BODY(&msg, msg__std_msgs__Float32);

				/* Dispose the contents of the message.*/
				clean_msg__std_msgs__Float32(&msg);

			}
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	sonarsub_node.set_enabled(false);
	while (sonar_sub.fetch(msgp)) {
		sonar_sub.release(*msgp);
	}

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__std_msgs__Float32);
	return tcpstp->err;
}

/** @} */

/** @} */

/*===========================================================================*/
/* SUBSCRIBED TOPIC FUNCTIONS                                                */
/*===========================================================================*/

/** @addtogroup tcpros_subtopic_funcs */
/** @{ */

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

	led3pub_node.advertise(led3_pub, "led3");
	led3pub_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Led);

	/* Subscribed messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		/* Receive the next message.*/
		UROS_MSG_RECV_LENGTH()
		;
		UROS_MSG_RECV_BODY(&msg, msg__r2p__Led);

		if (led3_pub.alloc(msgp)) {
			msgp->led = msg.led;
			msgp->value = msg.value;
		}

		led3_pub.publish(*msgp);

		/* Dispose the contents of the message.*/
		clean_msg__r2p__Led(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally: led3pub_node.set_enabled(false);
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

	/* /r2p/ir */
	urosNodePublishTopicSZ("/r2p/ir", "std_msgs/Float32", (uros_proc_f) pub_tpc__r2p__ir, uros_nulltopicflags);

	/* /r2p/led2 */
	urosNodePublishTopicSZ("/r2p/led2", "r2p/Led", (uros_proc_f) pub_tpc__r2p__led2, uros_nulltopicflags);

	/* /r2p/sonar */
	urosNodePublishTopicSZ("/r2p/sonar", "std_msgs/Float32", (uros_proc_f) pub_tpc__r2p__sonar, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

	/* /r2p/ir */
	urosNodeUnpublishTopicSZ("/r2p/ir");

	/* /r2p/led2 */
	urosNodeUnpublishTopicSZ("/r2p/led2");

	/* /r2p/sonar */
	urosNodeUnpublishTopicSZ("/r2p/sonar");
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

	/* /r2p/led3 */
	urosNodeSubscribeTopicSZ("/r2p/led3", "r2p/Led", (uros_proc_f) sub_tpc__r2p__led3, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

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

