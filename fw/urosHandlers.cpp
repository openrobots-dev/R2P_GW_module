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
r2p::Node sub_node("uled", false);
r2p::Subscriber<r2p::LedMsg, 2> led_sub;

r2p::Node enc1_node("uenc1", false);
r2p::Subscriber<r2p::tEncoderMsg, 5> enc1_sub;

r2p::Node enc2_node("uenc2", false);
r2p::Subscriber<r2p::tEncoderMsg, 5> enc2_sub;

r2p::Node enc3_node("uenc3", false);
r2p::Subscriber<r2p::tEncoderMsg, 5> enc3_sub;

r2p::Node imu_node("uimu", false);
r2p::Subscriber<r2p::tIMURaw9, 5> imu_sub;

r2p::Node vel_node("uvel", false);
r2p::Publisher<r2p::Speed3Msg> vel_pub;

extern int activity;

/*===========================================================================*/
/* LOCAL FUNCTIONS                                                           */
/*===========================================================================*/

template<typename T> static inline T clamp(T min, T value, T max) {
	return (value < min) ? min : ((value > max) ? max : value);
}

/*
 *  //_______________________\\
 * //            x            \\
 *   \  2        ^        1  /
 *    \          |          /
 *     \         |         /
 *       \ y<----@       /
 *        \      z      /
 *         \           /
 *           \       /
 *            \  3  /
 *             \___/
 *             =====
 *
 * Body frame velocity to wheel angular velocity:
 * R * dth1 = cos(60°) * dx - cos(30°) * dy - L * dgamma
 * R * dth2 = cos(60°) * dx + cos(30°) * dy - L * dgamma
 * R * dth3 =           -dx                 - L * dgamma
 *
 * Name mapping and units:
 * dx     = strafe     [m/s]
 * dy     = forward    [m/s]
 * dgamma = angular    [rad/s]
 * dth{1,2,3}          [rad/s]
 */

// Robot parameters
#define _L        0.300f    // Wheel distance [m]
#define _R        0.050f    // Wheel radius [m]
#define _MAX_DTH  26.0f     // Maximum wheel angular speed [rad/s]

#define _m1_R     (-1.0f / _R)
#define _mL_R     (-_L / _R)
#define _C60_R    (0.500000000f / _R)   // cos(60°) / R
#define _C30_R    (0.866025404f / _R)   // cos(30°) / R

#define _TICKS 2000.0f
#define _RATIO 14.0f
#define _PI 3.14159265359f

#define R2T(r) (_TICKS * _RATIO)/(r * 2 * _PI)
#define T2R(t) (t / R2T)

#define M2T(m) (m * _TICKS * _RATIO)/(2 * _PI * _R)
#define T2M(t) (t / _M2TICK)

static
void velocity_to_setpoints(const struct msg__r2p__Velocity &velocity, r2p::Speed3Msg &setpoints) {

	  // Wheel angular speeds
	  const float dthz123 = _mL_R * velocity.w;
	  const float dx12 = _C60_R * velocity.y;
	  const float dy12 = _C30_R * velocity.x;

	  float dth1 = dx12 - dy12 + dthz123;
	  float dth2 = dx12 + dy12 + dthz123;
	  float dth3 = _m1_R * velocity.y + dthz123;

	  // Motor setpoints
	  setpoints.value[0] = (int16_t)clamp(-_MAX_DTH, dth1, _MAX_DTH);
	  setpoints.value[1] = -(int16_t)clamp(-_MAX_DTH, dth2, _MAX_DTH);
	  setpoints.value[2] = -(int16_t)clamp(-_MAX_DTH, dth3, _MAX_DTH);
}

static void imuraw_to_si(const r2p::tIMURaw9 &imuraw, struct msg__r2p__ImuStamped &imu) {

	/* Angular velocity. */
	imu.imu.angular_velocity.x = ((float) imuraw.gyro_x) * 0.0175 * _PI / 180;
	imu.imu.angular_velocity.y = ((float) imuraw.gyro_y) * 0.0175 * _PI / 180;
	imu.imu.angular_velocity.z = ((float) imuraw.gyro_z) * 0.0175 * _PI / 180;

	/* Linear acceleration. */
	imu.imu.linear_acceleration.x = ((float) imuraw.acc_x) / 1000.0;
	imu.imu.linear_acceleration.y = ((float) imuraw.acc_y) / 1000.0;
	imu.imu.linear_acceleration.z = ((float) imuraw.acc_z) / 1000.0;

	/* Magnetic field. */
	imu.imu.magnetic_field.x = ((float) imuraw.mag_x) / 1100.0;
	imu.imu.magnetic_field.y = ((float) imuraw.mag_y) / 1100.0;
	imu.imu.magnetic_field.z = ((float) imuraw.mag_z) / 980.0;
}

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /triskar/encoder1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/triskar/encoder1</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/triskar/encoder1</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__triskar__encoder1(UrosTcpRosStatus *tcpstp) {
	r2p::tEncoderMsg *msgp;
	static bool first_time = true;
	static uint32_t seq = 0;

	if (first_time) {
		enc1_node.subscribe(enc1_sub, "encoder1");
		first_time = false;
	}

	enc1_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__EncoderStamped);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (enc1_node.spin(r2p::Time::ms(1000))) {
			while (enc1_sub.fetch(msgp)) {
				msg.header.seq = seq++;
				msg.header.stamp.sec = msgp->timestamp.sec;
				msg.header.stamp.nsec = msgp->timestamp.nsec;
				msg.header.frame_id.length = 0;
				msg.header.frame_id.datap = NULL;
				msg.encoder.delta = msgp->delta;
				enc1_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__r2p__EncoderStamped);
				UROS_MSG_SEND_BODY(&msg, msg__r2p__EncoderStamped);

				/* Dispose the contents of the message.*/
				clean_msg__r2p__EncoderStamped(&msg);

			}
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	enc1_node.set_enabled(false);
	while (enc1_sub.fetch(msgp)) {
		enc1_sub.release(*msgp);
	}

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__EncoderStamped);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /triskar/encoder2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/triskar/encoder2</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/triskar/encoder2</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__triskar__encoder2(UrosTcpRosStatus *tcpstp) {
	r2p::tEncoderMsg *msgp;
	static bool first_time = true;
	static uint32_t seq = 0;

	if (first_time) {
		enc2_node.subscribe(enc2_sub, "encoder2");
		first_time = false;
	}

	enc2_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__EncoderStamped);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (enc2_node.spin(r2p::Time::ms(1000))) {
			while (enc2_sub.fetch(msgp)) {
				msg.header.seq = seq++;
				msg.header.stamp.sec = msgp->timestamp.sec;
				msg.header.stamp.nsec = msgp->timestamp.nsec;
				msg.header.frame_id.length = 0;
				msg.header.frame_id.datap = NULL;
				msg.encoder.delta = msgp->delta;
				enc2_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__r2p__EncoderStamped);
				UROS_MSG_SEND_BODY(&msg, msg__r2p__EncoderStamped);

				/* Dispose the contents of the message.*/
				clean_msg__r2p__EncoderStamped(&msg);

			}
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	enc2_node.set_enabled(false);
	while (enc2_sub.fetch(msgp)) {
		enc2_sub.release(*msgp);
	}

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__EncoderStamped);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /triskar/encoder3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/triskar/encoder3</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/triskar/encoder3</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__triskar__encoder3(UrosTcpRosStatus *tcpstp) {
	r2p::tEncoderMsg *msgp;
	static bool first_time = true;
	static uint32_t seq = 0;

	if (first_time) {
		enc3_node.subscribe(enc3_sub, "encoder3");
		first_time = false;
	}

	enc3_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__EncoderStamped);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (enc3_node.spin(r2p::Time::ms(1000))) {
			while (enc3_sub.fetch(msgp)) {
				msg.header.seq = seq++;
				msg.header.stamp.sec = msgp->timestamp.sec;
				msg.header.stamp.nsec = msgp->timestamp.nsec;
				msg.header.frame_id.length = 0;
				msg.header.frame_id.datap = NULL;
				msg.encoder.delta = msgp->delta;
				enc3_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__r2p__EncoderStamped);
				UROS_MSG_SEND_BODY(&msg, msg__r2p__EncoderStamped);

				/* Dispose the contents of the message.*/
				clean_msg__r2p__EncoderStamped(&msg);

			}
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	enc3_node.set_enabled(false);
	while (enc3_sub.fetch(msgp)) {
		enc3_sub.release(*msgp);
	}

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__EncoderStamped);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /triskar/imu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/triskar/imu</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/triskar/imu</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__triskar__imu(UrosTcpRosStatus *tcpstp) {
	r2p::tIMURaw9 *msgp;
	static bool first_time = true;
	static uint32_t seq = 0;

	if (first_time) {
		imu_node.subscribe(imu_sub, "imuraw");
		first_time = false;
	}

	imu_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__ImuStamped);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (sub_node.spin(r2p::Time::ms(1000))) {
			while (imu_sub.fetch(msgp)) {
				/* Header. */
				msg.header.seq = seq++;
				msg.header.stamp.sec = msgp->timestamp.sec;
				msg.header.stamp.nsec = msgp->timestamp.nsec;
				msg.header.frame_id.length = 0;
				msg.header.frame_id.datap = NULL;

				imuraw_to_si(*msgp, msg);
				imu_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__r2p__ImuStamped);
				UROS_MSG_SEND_BODY(&msg, msg__r2p__ImuStamped);

				/* Dispose the contents of the message.*/
				clean_msg__r2p__ImuStamped(&msg);
			}
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	imu_node.set_enabled(false);
	while (imu_sub.fetch(msgp)) {
		imu_sub.release(*msgp);
	}

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__ImuStamped);
	return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /triskar/led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/triskar/led</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/triskar/led</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__triskar__led(UrosTcpRosStatus *tcpstp) {
	r2p::LedMsg *msgp;
	static bool first_time = true;

	if (first_time) {
		sub_node.subscribe(led_sub, "leds");
		first_time = false;
	}

	sub_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Led);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (sub_node.spin(r2p::Time::ms(1000))) {
			while (led_sub.fetch(msgp)) {
				msg.led = msgp->led;
				msg.value = msgp->value;
				led_sub.release(*msgp);

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
	sub_node.set_enabled(false);
	while (led_sub.fetch(msgp)) {
		led_sub.release(*msgp);
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

/*~~~ SUBSCRIBED TOPIC: /triskar/velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/triskar/velocity</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/triskar/velocity</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__triskar__velocity(UrosTcpRosStatus *tcpstp) {
	r2p::Speed3Msg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Velocity);

	if (first_time) {
		vel_node.advertise(vel_pub, "speed3", r2p::Time::INFINITE);
		first_time = false;
	}

	vel_node.set_enabled(true);

	/* Subscribed messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		/* Receive the next message.*/
		UROS_MSG_RECV_LENGTH()
		;
		UROS_MSG_RECV_BODY(&msg, msg__r2p__Velocity);

		if (vel_pub.alloc(msgp)) {
			velocity_to_setpoints(msg, *msgp);
			vel_pub.publish(*msgp);
		}

		activity = 1;

		/* Dispose the contents of the message.*/
		clean_msg__r2p__Velocity(&msg);
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Disable r2p node. */
	vel_node.set_enabled(false);

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__r2p__Velocity);
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

	/* /triskar/encoder1 */
	urosNodePublishTopicSZ("/triskar/encoder1", "r2p/EncoderStamped", (uros_proc_f) pub_tpc__triskar__encoder1,
			uros_nulltopicflags);

	/* /triskar/encoder2 */
	urosNodePublishTopicSZ("/triskar/encoder2", "r2p/EncoderStamped", (uros_proc_f) pub_tpc__triskar__encoder2,
			uros_nulltopicflags);

	/* /triskar/encoder3 */
	urosNodePublishTopicSZ("/triskar/encoder3", "r2p/EncoderStamped", (uros_proc_f) pub_tpc__triskar__encoder3,
			uros_nulltopicflags);

	/* /triskar/imu */
	urosNodePublishTopicSZ("/triskar/imu", "r2p/ImuStamped", (uros_proc_f) pub_tpc__triskar__imu, uros_nulltopicflags);

	/* /triskar/led */
	urosNodePublishTopicSZ("/triskar/led", "r2p/Led", (uros_proc_f) pub_tpc__triskar__led, uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

	/* /triskar/encoder1 */
	urosNodeUnpublishTopicSZ("/triskar/encoder1");

	/* /triskar/encoder2 */
	urosNodeUnpublishTopicSZ("/triskar/encoder2");

	/* /triskar/encoder3 */
	urosNodeUnpublishTopicSZ("/triskar/encoder3");

	/* /triskar/imu */
	urosNodeUnpublishTopicSZ("/triskar/imu");

	/* /triskar/led */
	urosNodeUnpublishTopicSZ("/triskar/led");
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

	/* /triskar/velocity */
	urosNodeSubscribeTopicSZ("/triskar/velocity", "r2p/Velocity", (uros_proc_f) sub_tpc__triskar__velocity,
			uros_nulltopicflags);
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

	/* /triskar/velocity */
	urosNodeUnsubscribeTopicSZ("/triskar/velocity");
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

