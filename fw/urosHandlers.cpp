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

#include <r2p/msg/std_msgs.hpp>
#include <r2p/msg/motor.hpp>

/*===========================================================================*/
/* GLOBAL VARIABLES                                                          */
/*===========================================================================*/
r2p::Node usteer_node("usteer", false);
r2p::Subscriber<r2p::EncoderMsg, 5> steer_sub;

r2p::Node uwheel_node("uwheel", false);
r2p::Subscriber<r2p::Encoder2Msg, 5> wheel_sub;

r2p::Node uodo_node("uodo", false);
r2p::Subscriber<r2p::Velocity3Msg, 5> odo_sub;

r2p::Node uvel_node("uvel", false);
r2p::Publisher<r2p::Velocity3Msg> vel_pub;

extern int activity;

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /r2p/odometry ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/odometry</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/odometry</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__odometry(UrosTcpRosStatus *tcpstp) {
	r2p::Velocity3Msg *msgp;
	static bool first_time = true;

	if (first_time) {
		uodo_node.subscribe(odo_sub, "odometry");
		first_time = false;
	}

	uodo_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__geometry_msgs__Twist);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		uodo_node.spin(r2p::Time::ms(1000));
		while (odo_sub.fetch(msgp)) {
			msg.linear.x = msgp->x;
			msg.linear.y = 0;
			msg.linear.z = 0;
			msg.angular.x = 0;
			msg.angular.y = 0;
			msg.angular.z = msgp->w;
			odo_sub.release(*msgp);

			/* Send the message.*/
			UROS_MSG_SEND_LENGTH(&msg, msg__geometry_msgs__Twist);
			UROS_MSG_SEND_BODY(&msg, msg__geometry_msgs__Twist);

			/* Dispose the contents of the message.*/
			clean_msg__geometry_msgs__Twist(&msg);
		}

	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	uodo_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__geometry_msgs__Twist);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /r2p/steer_encoder ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/steer_encoder</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/steer_encoder</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__steer_encoder(UrosTcpRosStatus *tcpstp) {
	r2p::EncoderMsg *msgp;
	static bool first_time = true;

	if (first_time) {
		usteer_node.subscribe(steer_sub, "steer_encoder");
		first_time = false;
	}

	usteer_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Encoder);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		usteer_node.spin(r2p::Time::ms(1000));
		while (steer_sub.fetch(msgp)) {
			msg.delta = msgp->delta;
			steer_sub.release(*msgp);

			/* Send the message.*/
			UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Encoder);
			UROS_MSG_SEND_BODY(&msg, msg__r2p__Encoder);

			/* Dispose the contents of the message.*/
			clean_msg__r2p__Encoder(&msg);
		}
	}

	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	usteer_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__Encoder);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /r2p/wheel_encoders ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/wheel_encoders</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/wheel_encoders</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__wheel_encoders(UrosTcpRosStatus *tcpstp) {
	r2p::Encoder2Msg *msgp;
	static bool first_time = true;

	if (first_time) {
		uwheel_node.subscribe(wheel_sub, "wheel_encoders");
		first_time = false;
	}

	uwheel_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Encoder2);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		uwheel_node.spin(r2p::Time::ms(1000));
		while (wheel_sub.fetch(msgp)) {
			msg.left_delta = msgp->left_delta;
			msg.right_delta = msgp->right_delta;
			wheel_sub.release(*msgp);

			/* Send the message.*/
			UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Encoder2);
			UROS_MSG_SEND_BODY(&msg, msg__r2p__Encoder2);

			/* Dispose the contents of the message.*/
			clean_msg__r2p__Encoder2(&msg);
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	uwheel_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__Encoder2);
	return tcpstp->err;
}

/** @} */

/** @} */

/*===========================================================================*/
/* SUBSCRIBED TOPIC FUNCTIONS                                                */
/*===========================================================================*/

/** @addtogroup tcpros_subtopic_funcs */
/** @{ */

/*~~~ SUBSCRIBED TOPIC: /cmd_vel ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/cmd_vel</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/cmd_vel</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__cmd_vel(UrosTcpRosStatus *tcpstp) {
	r2p::Velocity3Msg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__geometry_msgs__Twist);

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
		UROS_MSG_RECV_BODY(&msg, msg__geometry_msgs__Twist);

		palTogglePad(LED2_GPIO, LED2);
		if (vel_pub.alloc(msgp)) {
			msgp->x = msg.linear.x;
			msgp->w = msg.angular.z;
			vel_pub.publish(*msgp);
		}

		activity = 1;

		/* Dispose the contents of the message.*/
		clean_msg__geometry_msgs__Twist(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	uvel_node.set_enabled(false);
	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__geometry_msgs__Twist);
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

	/* /r2p/odometry */
	urosNodePublishTopicSZ("/r2p/odometry", "geometry_msgs/Twist",
			(uros_proc_f) pub_tpc__r2p__odometry, uros_nulltopicflags);

	/* /r2p/steer_encoder */
	urosNodePublishTopicSZ("/r2p/steer_encoder", "r2p/Encoder",
			(uros_proc_f) pub_tpc__r2p__steer_encoder, uros_nulltopicflags);

	/* /r2p/wheel_encoders */
	urosNodePublishTopicSZ("/r2p/wheel_encoders", "r2p/Encoder2",
			(uros_proc_f) pub_tpc__r2p__wheel_encoders, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

	/* /r2p/odometry */
	urosNodeUnpublishTopicSZ("/r2p/odometry");

	/* /r2p/steer_encoder */
	urosNodeUnpublishTopicSZ("/r2p/steer_encoder");

	/* /r2p/wheel_encoders */
	urosNodeUnpublishTopicSZ("/r2p/wheel_encoders");
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

	/* /cmd_vel */
	urosNodeSubscribeTopicSZ("/cmd_vel", "geometry_msgs/Twist",
			(uros_proc_f) sub_tpc__cmd_vel, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

	/* /cmd_vel */
	urosNodeUnsubscribeTopicSZ("/cmd_vel");
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

