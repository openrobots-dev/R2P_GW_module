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

/*~~~ PUBLISHED TOPIC: /robocom/encoder1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/robocom/encoder1</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/robocom/encoder1</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__robocom__encoder1(UrosTcpRosStatus *tcpstp) {

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

/*~~~ PUBLISHED TOPIC: /robocom/encoder2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/robocom/encoder2</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/robocom/encoder2</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__robocom__encoder2(UrosTcpRosStatus *tcpstp) {

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

/*~~~ PUBLISHED TOPIC: /robocom/imu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/robocom/imu</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/robocom/imu</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__robocom__imu(UrosTcpRosStatus *tcpstp) {

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

/*~~~ PUBLISHED TOPIC: /robocom/led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/robocom/led</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/robocom/led</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__robocom__led(UrosTcpRosStatus *tcpstp) {

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

/*~~~ SUBSCRIBED TOPIC: /robocom/velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/robocom/velocity</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/robocom/velocity</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__robocom__velocity(UrosTcpRosStatus *tcpstp) {

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

  /* /robocom/encoder1 */
  urosNodePublishTopicSZ(
    "/robocom/encoder1",
    "r2p/EncoderStamped",
    (uros_proc_f)pub_tpc__robocom__encoder1,
    uros_nulltopicflags
  );

  /* /robocom/encoder2 */
  urosNodePublishTopicSZ(
    "/robocom/encoder2",
    "r2p/EncoderStamped",
    (uros_proc_f)pub_tpc__robocom__encoder2,
    uros_nulltopicflags
  );

  /* /robocom/imu */
  urosNodePublishTopicSZ(
    "/robocom/imu",
    "r2p/ImuStamped",
    (uros_proc_f)pub_tpc__robocom__imu,
    uros_nulltopicflags
  );

  /* /robocom/led */
  urosNodePublishTopicSZ(
    "/robocom/led",
    "r2p/Led",
    (uros_proc_f)pub_tpc__robocom__led,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the published topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnpublishTopics(void) {

  /* /robocom/encoder1 */
  urosNodeUnpublishTopicSZ(
    "/robocom/encoder1"
  );

  /* /robocom/encoder2 */
  urosNodeUnpublishTopicSZ(
    "/robocom/encoder2"
  );

  /* /robocom/imu */
  urosNodeUnpublishTopicSZ(
    "/robocom/imu"
  );

  /* /robocom/led */
  urosNodeUnpublishTopicSZ(
    "/robocom/led"
  );
}

/**
 * @brief   Registers all the subscribed topics to the Master node.
 * @note    Should be called at node initialization.
 */
void urosHandlersSubscribeTopics(void) {

  /* /robocom/velocity */
  urosNodeSubscribeTopicSZ(
    "/robocom/velocity",
    "r2p/Velocity",
    (uros_proc_f)sub_tpc__robocom__velocity,
    uros_nulltopicflags
  );
}

/**
 * @brief   Unregisters all the subscribed topics to the Master node.
 * @note    Should be called at node shutdown.
 */
void urosHandlersUnsubscribeTopics(void) {

  /* /robocom/velocity */
  urosNodeUnsubscribeTopicSZ(
    "/robocom/velocity"
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

