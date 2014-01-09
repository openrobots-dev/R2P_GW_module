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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__EncoderStamped);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__r2p__EncoderStamped);
    UROS_MSG_SEND_BODY(&msg, msg__r2p__EncoderStamped);

    /* Dispose the contents of the message.*/
    clean_msg__r2p__EncoderStamped(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__EncoderStamped);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__r2p__EncoderStamped);
    UROS_MSG_SEND_BODY(&msg, msg__r2p__EncoderStamped);

    /* Dispose the contents of the message.*/
    clean_msg__r2p__EncoderStamped(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__EncoderStamped);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__r2p__EncoderStamped);
    UROS_MSG_SEND_BODY(&msg, msg__r2p__EncoderStamped);

    /* Dispose the contents of the message.*/
    clean_msg__r2p__EncoderStamped(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__ImuStamped);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__r2p__ImuStamped);
    UROS_MSG_SEND_BODY(&msg, msg__r2p__ImuStamped);

    /* Dispose the contents of the message.*/
    clean_msg__r2p__ImuStamped(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__Led);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__r2p__Led);
    UROS_MSG_SEND_BODY(&msg, msg__r2p__Led);

    /* Dispose the contents of the message.*/
    clean_msg__r2p__Led(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__Velocity);

  /* Subscribed messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* Receive the next message.*/
    UROS_MSG_RECV_LENGTH();
    UROS_MSG_RECV_BODY(&msg, msg__r2p__Velocity);

    /* TODO: Process the received message.*/

    /* Dispose the contents of the message.*/
    clean_msg__r2p__Velocity(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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
  urosNodePublishTopicSZ(
    "/triskar/encoder1",
    "r2p/EncoderStamped",
    (uros_proc_f)pub_tpc__triskar__encoder1,
    uros_nulltopicflags
  );

  /* /triskar/encoder2 */
  urosNodePublishTopicSZ(
    "/triskar/encoder2",
    "r2p/EncoderStamped",
    (uros_proc_f)pub_tpc__triskar__encoder2,
    uros_nulltopicflags
  );

  /* /triskar/encoder3 */
  urosNodePublishTopicSZ(
    "/triskar/encoder3",
    "r2p/EncoderStamped",
    (uros_proc_f)pub_tpc__triskar__encoder3,
    uros_nulltopicflags
  );

  /* /triskar/imu */
  urosNodePublishTopicSZ(
    "/triskar/imu",
    "r2p/ImuStamped",
    (uros_proc_f)pub_tpc__triskar__imu,
    uros_nulltopicflags
  );

  /* /triskar/led */
  urosNodePublishTopicSZ(
    "/triskar/led",
    "r2p/Led",
    (uros_proc_f)pub_tpc__triskar__led,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

  /* /triskar/encoder1 */
  urosNodeUnpublishTopicSZ(
    "/triskar/encoder1"
  );

  /* /triskar/encoder2 */
  urosNodeUnpublishTopicSZ(
    "/triskar/encoder2"
  );

  /* /triskar/encoder3 */
  urosNodeUnpublishTopicSZ(
    "/triskar/encoder3"
  );

  /* /triskar/imu */
  urosNodeUnpublishTopicSZ(
    "/triskar/imu"
  );

  /* /triskar/led */
  urosNodeUnpublishTopicSZ(
    "/triskar/led"
  );
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

  /* /triskar/velocity */
  urosNodeSubscribeTopicSZ(
    "/triskar/velocity",
    "r2p/Velocity",
    (uros_proc_f)sub_tpc__triskar__velocity,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

  /* /triskar/velocity */
  urosNodeUnsubscribeTopicSZ(
    "/triskar/velocity"
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

