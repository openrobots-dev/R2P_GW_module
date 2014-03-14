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

#include <ch.h>
#include <hal.h>

#include <r2p/common.hpp>
#include <r2p/Middleware.hpp>
#include <r2p/Node.hpp>
#include <r2p/Publisher.hpp>
#include <r2p/Subscriber.hpp>

#include <r2p/msg/motor.hpp>

/*===========================================================================*/
/* GLOBAL VARIABLES                                                          */
/*===========================================================================*/
r2p::Node uvel_node("uvel", false);
r2p::Publisher<r2p::Velocity3Msg> vel_pub;

r2p::Node uodo_node("uodo", false);
r2p::Subscriber<r2p::EncoderMsg, 5> speed_sub;
r2p::Subscriber<r2p::AbsoluteEncoder, 5> steer_sub;

extern int activity;

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /ackermann_odometry ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/ackermann_odometry</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/ackermann_odometry</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__ackermann_odometry(UrosTcpRosStatus *tcpstp) {
	r2p::EncoderMsg *speed_msgp;
	r2p::AbsoluteEncoder *steer_msgp;
	static bool first_time = true;
	float steer_position = 0.0f;

	if (first_time) {
		uodo_node.subscribe(steer_sub, "steer_encoder");
		chThdSleepMilliseconds(100);
		uodo_node.subscribe(speed_sub, "encoder1");
		first_time = false;
	}

	uodo_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__roamros_msgs__SingleTrackAckermannOdometry);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		uodo_node.spin(r2p::Time::ms(1000));

		while (steer_sub.fetch(steer_msgp)) {
			steer_position = steer_msgp->position;
			steer_sub.release(*steer_msgp);
		}

		while (speed_sub.fetch(speed_msgp)) {
			msg.speed = speed_msgp->delta;
			msg.steer = steer_position;
			speed_sub.release(*speed_msgp);

			/* Send the message.*/
			UROS_MSG_SEND_LENGTH(&msg, msg__roamros_msgs__SingleTrackAckermannOdometry);
			UROS_MSG_SEND_BODY(&msg, msg__roamros_msgs__SingleTrackAckermannOdometry);
		}

		/* Dispose the contents of the message.*/
		clean_msg__roamros_msgs__SingleTrackAckermannOdometry(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__roamros_msgs__SingleTrackAckermannOdometry);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /heartbeat ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/heartbeat</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/heartbeat</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__heartbeat(UrosTcpRosStatus *tcpstp) {

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__heartbeat__Heartbeat);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		/* TODO: Generate the contents of the message.*/
		urosThreadSleepSec(1);
		continue; /* TODO: Remove this dummy line.*/

		/* Send the message.*/
		UROS_MSG_SEND_LENGTH(&msg, msg__heartbeat__Heartbeat);
		UROS_MSG_SEND_BODY(&msg, msg__heartbeat__Heartbeat);

		/* Dispose the contents of the message.*/
		clean_msg__heartbeat__Heartbeat(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__heartbeat__Heartbeat);
	return tcpstp->err;
}

/** @} */

/** @} */

/*===========================================================================*/
/* SUBSCRIBED TOPIC FUNCTIONS                                                */
/*===========================================================================*/

/** @addtogroup tcpros_subtopic_funcs */
/** @{ */

/*~~~ SUBSCRIBED TOPIC: /setpoint ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/setpoint</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/setpoint</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__setpoint(UrosTcpRosStatus *tcpstp) {
	r2p::Velocity3Msg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__quadrivio_msgs__SetPoint);

	if (first_time) {
		uvel_node.advertise(vel_pub, "vel_cmd", r2p::Time::INFINITE);
		first_time = false;
	}

	uvel_node.set_enabled(true);

	/* Subscribed messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		/* Receive the next message.*/
		UROS_MSG_RECV_LENGTH()
		;
		UROS_MSG_RECV_BODY(&msg, msg__quadrivio_msgs__SetPoint);

		palTogglePad(LED2_GPIO, LED2);
		activity = 1;

		if (vel_pub.alloc(msgp)) {
			msgp->x = msg.speed;
			msgp->w = msg.steer;
			vel_pub.publish(*msgp);
		}

		/* Dispose the contents of the message.*/
		clean_msg__quadrivio_msgs__SetPoint(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	uvel_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__quadrivio_msgs__SetPoint);
	return tcpstp->err;
}

/** @} */

/*~~~ SUBSCRIBED TOPIC: /state ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/state</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/state</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__state(UrosTcpRosStatus *tcpstp) {

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__heartbeat__State);

	/* Subscribed messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		/* Receive the next message.*/
		UROS_MSG_RECV_LENGTH()
		;
		UROS_MSG_RECV_BODY(&msg, msg__heartbeat__State);

		/* TODO: Process the received message.*/

		/* Dispose the contents of the message.*/
		clean_msg__heartbeat__State(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__heartbeat__State);
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

	/* /ackermann_odometry */
	urosNodePublishTopicSZ("/ackermann_odometry", "roamros_msgs/SingleTrackAckermannOdometry",
			(uros_proc_f) pub_tpc__ackermann_odometry, uros_nulltopicflags);

	/* /heartbeat */
	urosNodePublishTopicSZ("/heartbeat", "heartbeat/Heartbeat", (uros_proc_f) pub_tpc__heartbeat, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

	/* /ackermann_odometry */
	urosNodeUnpublishTopicSZ("/ackermann_odometry");

	/* /heartbeat */
	urosNodeUnpublishTopicSZ("/heartbeat");
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

	/* /setpoint */
	urosNodeSubscribeTopicSZ("/setpoint", "quadrivio_msgs/SetPoint", (uros_proc_f) sub_tpc__setpoint,
			uros_nulltopicflags);

	/* /state */
	urosNodeSubscribeTopicSZ("/state", "heartbeat/State", (uros_proc_f) sub_tpc__state, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

	/* /setpoint */
	urosNodeUnsubscribeTopicSZ("/setpoint");

	/* /state */
	urosNodeUnsubscribeTopicSZ("/state");
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

