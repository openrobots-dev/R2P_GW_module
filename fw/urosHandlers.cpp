/**
 * @file    urosHandlers.c
 * @author  TODO
 *
 * @brief   TCPROS topic and service handlers.
 */

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include <math.h>

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

r2p::Node uodo_vel_node("uodovel", false);
r2p::Subscriber<r2p::tVelocity3Msg, 5> odo_vel_sub;

r2p::Node uodo_diff_node("uododiff", false);
r2p::Subscriber<r2p::tPose3Msg, 5> odo_diff_sub;

r2p::Node uodo_ack_node("uodoack", false);
r2p::Subscriber<r2p::tPose3Msg, 5> odo_ack_sub;

r2p::Node uvel_node("uvel", false);
r2p::Publisher<r2p::Velocity3Msg> vel_pub;

extern int activity;

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /r2p/odometry_ackermann ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/odometry_ackermann</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/odometry_ackermann</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__odometry_ackermann(UrosTcpRosStatus *tcpstp) {
	r2p::tPose3Msg *msgp;
	static bool first_time = true;
	static uint32_t seq = 0;

	if (first_time) {
		uodo_ack_node.subscribe(odo_ack_sub, "delta_pose_ack");
		first_time = false;
	}

	uodo_ack_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__geometry_msgs__PoseStamped);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		uodo_ack_node.spin(r2p::Time::ms(1000));
		while (odo_ack_sub.fetch(msgp)) {
			msg.header.seq = seq++;
			msg.header.stamp.sec = msgp->timestamp.sec;
			msg.header.stamp.nsec = msgp->timestamp.nsec;
			msg.pose.position.x = msgp->x;
			msg.pose.position.y = msgp->y;
			msg.pose.position.z = 0;
			msg.pose.orientation.x = msgp->w;
			msg.pose.orientation.y = 0;
			msg.pose.orientation.z = sin(msgp->w / 2.0f);
			msg.pose.orientation.w = cos(msgp->w / 2.0f);
			odo_ack_sub.release(*msgp);

			/* Send the message.*/
			UROS_MSG_SEND_LENGTH(&msg, msg__geometry_msgs__PoseStamped);
			UROS_MSG_SEND_BODY(&msg, msg__geometry_msgs__PoseStamped);

			/* Dispose the contents of the message.*/
			clean_msg__geometry_msgs__PoseStamped(&msg);
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	uodo_ack_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__geometry_msgs__PoseStamped);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /r2p/odometry_differential ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/odometry_differential</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/odometry_differential</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__odometry_differential(UrosTcpRosStatus *tcpstp) {
	r2p::tPose3Msg *msgp;
	static bool first_time = true;
	static uint32_t seq = 0;

	if (first_time) {
		uodo_diff_node.subscribe(odo_diff_sub, "delta_pose_diff");
		first_time = false;
	}

	uodo_diff_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__geometry_msgs__PoseStamped);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		uodo_diff_node.spin(r2p::Time::ms(1000));
		while (odo_diff_sub.fetch(msgp)) {
			msg.header.seq = seq++;
			msg.header.stamp.sec = msgp->timestamp.sec;
			msg.header.stamp.nsec = msgp->timestamp.nsec;
			msg.pose.position.x = msgp->x;
			msg.pose.position.y = msgp->y;
			msg.pose.position.z = 0;
			msg.pose.orientation.x = msgp->w;
			msg.pose.orientation.y = 0;
			msg.pose.orientation.z = sin(msgp->w / 2.0f);
			msg.pose.orientation.w = cos(msgp->w / 2.0f);
			odo_diff_sub.release(*msgp);

			/* Send the message.*/
			UROS_MSG_SEND_LENGTH(&msg, msg__geometry_msgs__PoseStamped);
			UROS_MSG_SEND_BODY(&msg, msg__geometry_msgs__PoseStamped);

			/* Dispose the contents of the message.*/
			clean_msg__geometry_msgs__PoseStamped(&msg);
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	uodo_diff_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__geometry_msgs__PoseStamped);
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

/*~~~ PUBLISHED TOPIC: /r2p/velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/r2p/velocity</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/r2p/velocity</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__r2p__velocity(UrosTcpRosStatus *tcpstp) {
	r2p::tVelocity3Msg *msgp;
	static bool first_time = true;
	static uint32_t seq = 0;

	if (first_time) {
		uodo_vel_node.subscribe(odo_vel_sub, "velocity");
		first_time = false;
	}

	uodo_vel_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__geometry_msgs__TwistStamped);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		uodo_vel_node.spin(r2p::Time::ms(1000));
		while (odo_vel_sub.fetch(msgp)) {
			msg.header.seq = seq++;
			msg.header.stamp.sec = msgp->timestamp.sec;
			msg.header.stamp.nsec = msgp->timestamp.nsec;
			msg.twist.linear.x = msgp->x;
			msg.twist.linear.y = 0;
			msg.twist.linear.z = 0;
			msg.twist.angular.x = 0;
			msg.twist.angular.y = 0;
			msg.twist.angular.z = msgp->w;
			odo_vel_sub.release(*msgp);

			/* Send the message.*/
			UROS_MSG_SEND_LENGTH(&msg, msg__geometry_msgs__TwistStamped);
			UROS_MSG_SEND_BODY(&msg, msg__geometry_msgs__TwistStamped);

			/* Dispose the contents of the message.*/
			clean_msg__geometry_msgs__TwistStamped(&msg);
		}

	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	uodo_vel_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__geometry_msgs__TwistStamped);
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

	/* /r2p/odometry_ackermann */
	urosNodePublishTopicSZ("/r2p/odometry_ackermann",
			"geometry_msgs/PoseStamped",
			(uros_proc_f) pub_tpc__r2p__odometry_ackermann,
			uros_nulltopicflags);

	/* /r2p/odometry_differential */
	urosNodePublishTopicSZ("/r2p/odometry_differential",
			"geometry_msgs/PoseStamped",
			(uros_proc_f) pub_tpc__r2p__odometry_differential,
			uros_nulltopicflags);

	/* /r2p/steer_encoder */
	urosNodePublishTopicSZ("/r2p/steer_encoder", "r2p/Encoder",
			(uros_proc_f) pub_tpc__r2p__steer_encoder, uros_nulltopicflags);

	/* /r2p/velocity */
	urosNodePublishTopicSZ("/r2p/velocity", "geometry_msgs/TwistStamped",
			(uros_proc_f) pub_tpc__r2p__velocity, uros_nulltopicflags);

	/* /r2p/wheel_encoders */
	urosNodePublishTopicSZ("/r2p/wheel_encoders", "r2p/Encoder2",
			(uros_proc_f) pub_tpc__r2p__wheel_encoders, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

	/* /r2p/odometry_ackermann */
	urosNodeUnpublishTopicSZ("/r2p/odometry_ackermann");

	/* /r2p/odometry_differential */
	urosNodeUnpublishTopicSZ("/r2p/odometry_differential");

	/* /r2p/steer_encoder */
	urosNodeUnpublishTopicSZ("/r2p/steer_encoder");

	/* /r2p/velocity */
	urosNodeUnpublishTopicSZ("/r2p/velocity");

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

