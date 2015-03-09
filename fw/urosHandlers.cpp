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

#include <r2p/msg/imu.hpp>
#include <r2p/msg/led.hpp>
#include <r2p/msg/motor.hpp>

/*===========================================================================*/
/* GLOBAL VARIABLES                                                          */
/*===========================================================================*/
r2p::Node odo_node("uodopub", false);
r2p::Subscriber<r2p::Velocity3Msg, 5> odo_sub;

r2p::Node tilt_node("utiltpub", false);
r2p::Subscriber<r2p::TiltMsg, 5> tilt_sub;

r2p::Node vel_node("uvelpub", false);
r2p::Publisher<r2p::Velocity3Msg> vel_pub;

extern int activity;

/*===========================================================================*/
/* PUBLISHED TOPIC FUNCTIONS                                                 */
/*===========================================================================*/

/** @addtogroup tcpros_pubtopic_funcs */
/** @{ */

/*~~~ PUBLISHED TOPIC: /tiltone/odometry ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/tiltone/odometry</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/tiltone/odometry</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__tiltone__odometry(UrosTcpRosStatus *tcpstp) {
	r2p::Velocity3Msg *msgp;
	static bool first_time = true;

	if (first_time) {
		odo_node.subscribe(odo_sub, "odometry");
		first_time = false;
	}

	odo_node.set_enabled(true);
  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__Velocity);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
	  if (odo_node.spin(r2p::Time::ms(1000))) {
	  			while (odo_sub.fetch(msgp)) {
	  				msg.x = msgp->x;
	  				msg.y = msgp->y;
	  				msg.w = msgp->w;
	  				odo_sub.release(*msgp);

	  				/* Send the message.*/
	  				UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Velocity);
	  				UROS_MSG_SEND_BODY(&msg, msg__r2p__Velocity);

	  				/* Dispose the contents of the message.*/
	  				clean_msg__r2p__Velocity(&msg);
	  			}
	  		}
  }
  tcpstp->err = UROS_OK;

_finally:
  /* Message deinitialization and deallocation.*/
  UROS_TPC_UNINIT_S(msg__r2p__Velocity);
  return tcpstp->err;
}

/** @} */

/*~~~ PUBLISHED TOPIC: /tiltone/tilt ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/tiltone/tilt</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/tiltone/tilt</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__tiltone__tilt(UrosTcpRosStatus *tcpstp) {
	r2p::TiltMsg *msgp;
	static bool first_time = true;

	if (first_time) {
		tilt_node.subscribe(tilt_sub, "tilt");
		first_time = false;
	}

	tilt_node.set_enabled(true);

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__tiltone__Tilt);

	/* Published messages loop.*/
	while (!urosTcpRosStatusCheckExit(tcpstp)) {
		if (tilt_node.spin(r2p::Time::ms(1000))) {
			while (tilt_sub.fetch(msgp)) {
				msg.angle = msgp->angle;
				tilt_sub.release(*msgp);

				/* Send the message.*/
				UROS_MSG_SEND_LENGTH(&msg, msg__tiltone__Tilt);
				UROS_MSG_SEND_BODY(&msg, msg__tiltone__Tilt);

				/* Dispose the contents of the message.*/
				clean_msg__tiltone__Tilt(&msg);
			}
		}
	}
	tcpstp->err = UROS_OK;

	_finally:
	/* Fetch pending messages and disable r2p node. */
	tilt_node.set_enabled(false);
	while (tilt_sub.fetch(msgp)) {
		tilt_sub.release(*msgp);
	}

	/* Message deinitialization and deallocation.*/
	UROS_TPC_UNINIT_S(msg__tiltone__Tilt);
	return tcpstp->err;
}

/** @} */

/** @} */

/*===========================================================================*/
/* SUBSCRIBED TOPIC FUNCTIONS                                                */
/*===========================================================================*/

/** @addtogroup tcpros_subtopic_funcs */
/** @{ */

/*~~~ SUBSCRIBED TOPIC: /tiltone/velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/tiltone/velocity</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/tiltone/velocity</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__tiltone__velocity(UrosTcpRosStatus *tcpstp) {
	r2p::Velocity3Msg *msgp;
	static bool first_time = true;

	/* Message allocation and initialization.*/
	UROS_TPC_INIT_S(msg__r2p__Velocity);

	if (first_time) {
		vel_node.advertise(vel_pub, "velocity", r2p::Time::INFINITE);
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
			msgp->w = msg.w;
			msgp->x = msg.x;
			msgp->y = msg.y;
		}

		vel_pub.publish(*msgp);

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

  /* /tiltone/odometry */
  urosNodePublishTopicSZ(
    "/tiltone/odometry",
    "r2p/Velocity",
    (uros_proc_f)pub_tpc__tiltone__odometry,
    uros_nulltopicflags
  );

  /* /tiltone/tilt */
  urosNodePublishTopicSZ(
    "/tiltone/tilt",
    "tiltone/Tilt",
    (uros_proc_f)pub_tpc__tiltone__tilt,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

  /* /tiltone/odometry */
  urosNodeUnpublishTopicSZ(
    "/tiltone/odometry"
  );

  /* /tiltone/tilt */
  urosNodeUnpublishTopicSZ(
    "/tiltone/tilt"
  );
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

  /* /tiltone/velocity */
  urosNodeSubscribeTopicSZ(
    "/tiltone/velocity",
    "r2p/Velocity",
    (uros_proc_f)sub_tpc__tiltone__velocity,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

  /* /tiltone/velocity */
  urosNodeUnsubscribeTopicSZ(
    "/tiltone/velocity"
  );
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

