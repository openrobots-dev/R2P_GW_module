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

/*~~~ PUBLISHED TOPIC: /tiltone/led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/tiltone/led</tt> publisher */
/** @{ */

/**
 * @brief   TCPROS <tt>/tiltone/led</tt> published topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t pub_tpc__tiltone__led(UrosTcpRosStatus *tcpstp) {

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

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__tiltone__Tilt);

  /* Published messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* TODO: Generate the contents of the message.*/
    urosThreadSleepSec(1); continue; /* TODO: Remove this dummy line.*/

    /* Send the message.*/
    UROS_MSG_SEND_LENGTH(&msg, msg__tiltone__Tilt);
    UROS_MSG_SEND_BODY(&msg, msg__tiltone__Tilt);

    /* Dispose the contents of the message.*/
    clean_msg__tiltone__Tilt(&msg);
  }
  tcpstp->err = UROS_OK;

_finally:
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

/*~~~ SUBSCRIBED TOPIC: /tiltone/led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Topic <tt>/tiltone/led</tt> subscriber */
/** @{ */

/**
 * @brief   TCPROS <tt>/tiltone/led</tt> subscribed topic handler.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @return
 *          Error code.
 */
uros_err_t sub_tpc__tiltone__led(UrosTcpRosStatus *tcpstp) {

  /* Message allocation and initialization.*/
  UROS_TPC_INIT_S(msg__r2p__Led);

  /* Subscribed messages loop.*/
  while (!urosTcpRosStatusCheckExit(tcpstp)) {
    /* Receive the next message.*/
    UROS_MSG_RECV_LENGTH();
    UROS_MSG_RECV_BODY(&msg, msg__r2p__Led);

    /* TODO: Process the received message.*/

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

  /* /tiltone/led */
  urosNodePublishTopicSZ(
    "/tiltone/led",
    "r2p/Led",
    (uros_proc_f)pub_tpc__tiltone__led,
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

  /* /tiltone/led */
  urosNodeUnpublishTopicSZ(
    "/tiltone/led"
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

  /* /tiltone/led */
  urosNodeSubscribeTopicSZ(
    "/tiltone/led",
    "r2p/Led",
    (uros_proc_f)sub_tpc__tiltone__led,
    uros_nulltopicflags
  );

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

  /* /tiltone/led */
  urosNodeUnsubscribeTopicSZ(
    "/tiltone/led"
  );

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

