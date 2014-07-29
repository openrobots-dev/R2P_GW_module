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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__geometry_msgs__PoseStamped);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__geometry_msgs__PoseStamped);
    UROS_MSG_SEND_BODY(&msg, msg__geometry_msgs__PoseStamped);

    /* Dispose the contents of the message.*/
    clean_msg__geometry_msgs__PoseStamped(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__geometry_msgs__PoseStamped);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__geometry_msgs__PoseStamped);
    UROS_MSG_SEND_BODY(&msg, msg__geometry_msgs__PoseStamped);

    /* Dispose the contents of the message.*/
    clean_msg__geometry_msgs__PoseStamped(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__Encoder);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Encoder);
    UROS_MSG_SEND_BODY(&msg, msg__r2p__Encoder);

    /* Dispose the contents of the message.*/
    clean_msg__r2p__Encoder(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__geometry_msgs__TwistStamped);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__geometry_msgs__TwistStamped);
    UROS_MSG_SEND_BODY(&msg, msg__geometry_msgs__TwistStamped);

    /* Dispose the contents of the message.*/
    clean_msg__geometry_msgs__TwistStamped(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__Encoder2);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Encoder2);
    UROS_MSG_SEND_BODY(&msg, msg__r2p__Encoder2);

    /* Dispose the contents of the message.*/
    clean_msg__r2p__Encoder2(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__geometry_msgs__Twist);

  /* Subscribed messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* Receive the next message.*/
    UROS_MSG_RECV_LENGTH();
    UROS_MSG_RECV_BODY(&msg, msg__geometry_msgs__Twist);

    /* TODO: Process the received message.*/

    /* Dispose the contents of the message.*/
    clean_msg__geometry_msgs__Twist(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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
  urosNodePublishTopicSZ(
    "/r2p/odometry_ackermann",
    "geometry_msgs/PoseStamped",
    (uros_proc_f)pub_tpc__r2p__odometry_ackermann,
    uros_nulltopicflags
  );

  /* /r2p/odometry_differential */
  urosNodePublishTopicSZ(
    "/r2p/odometry_differential",
    "geometry_msgs/PoseStamped",
    (uros_proc_f)pub_tpc__r2p__odometry_differential,
    uros_nulltopicflags
  );

  /* /r2p/steer_encoder */
  urosNodePublishTopicSZ(
    "/r2p/steer_encoder",
    "r2p/Encoder",
    (uros_proc_f)pub_tpc__r2p__steer_encoder,
    uros_nulltopicflags
  );

  /* /r2p/velocity */
  urosNodePublishTopicSZ(
    "/r2p/velocity",
    "geometry_msgs/TwistStamped",
    (uros_proc_f)pub_tpc__r2p__velocity,
    uros_nulltopicflags
  );

  /* /r2p/wheel_encoders */
  urosNodePublishTopicSZ(
    "/r2p/wheel_encoders",
    "r2p/Encoder2",
    (uros_proc_f)pub_tpc__r2p__wheel_encoders,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

  /* /r2p/odometry_ackermann */
  urosNodeUnpublishTopicSZ(
    "/r2p/odometry_ackermann"
  );

  /* /r2p/odometry_differential */
  urosNodeUnpublishTopicSZ(
    "/r2p/odometry_differential"
  );

  /* /r2p/steer_encoder */
  urosNodeUnpublishTopicSZ(
    "/r2p/steer_encoder"
  );

  /* /r2p/velocity */
  urosNodeUnpublishTopicSZ(
    "/r2p/velocity"
  );

  /* /r2p/wheel_encoders */
  urosNodeUnpublishTopicSZ(
    "/r2p/wheel_encoders"
  );
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

  /* /cmd_vel */
  urosNodeSubscribeTopicSZ(
    "/cmd_vel",
    "geometry_msgs/Twist",
    (uros_proc_f)sub_tpc__cmd_vel,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

  /* /cmd_vel */
  urosNodeUnsubscribeTopicSZ(
    "/cmd_vel"
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

