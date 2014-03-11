/**
 * @file    urosMsgTypes.c
 * @author  TODO
 *
 * @brief   TCPROS message and service descriptor functions.
 */

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include "urosMsgTypes.h"

/*===========================================================================*/
/* MESSAGE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_msg_consts */
/** @{ */

/* There are no message constants.*/

/** @} */

/*===========================================================================*/
/* SERVICE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_srv_consts */
/** @{ */

/* There are no service constants.*/

/** @} */

/*===========================================================================*/
/* MESSAGE FUNCTIONS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_msg_funcs */
/** @{ */

/*~~~ MESSAGE: std_msgs/String ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>std_msgs/String</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>std_msgs/String</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__String</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__std_msgs__String(
  struct msg__std_msgs__String *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(uint32_t) + objp->data.length;

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>std_msgs/String</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__std_msgs__String</code> object.
 * @return
 *          Error code.
 */
void init_msg__std_msgs__String(
  struct msg__std_msgs__String *objp
) {
  urosAssert(objp != NULL);

  urosStringObjectInit(&objp->data);
}

/**
 * @brief   Cleans a TCPROS <tt>std_msgs/String</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__String</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__std_msgs__String(
  struct msg__std_msgs__String *objp
) {
  if (objp == NULL) { return; }

  urosStringClean(&objp->data);
}

/**
 * @brief   Receives a TCPROS <tt>std_msgs/String</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__String</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__std_msgs__String(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__String *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvString(tcpstp, &objp->data); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__std_msgs__String(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>std_msgs/String</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__String</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__std_msgs__String(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__String *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendString(tcpstp, &objp->data); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: heartbeat/Heartbeat ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>heartbeat/Heartbeat</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>heartbeat/Heartbeat</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__Heartbeat</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__heartbeat__Heartbeat(
  struct msg__heartbeat__Heartbeat *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__std_msgs__String(&objp->node_name);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>heartbeat/Heartbeat</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__heartbeat__Heartbeat</code> object.
 * @return
 *          Error code.
 */
void init_msg__heartbeat__Heartbeat(
  struct msg__heartbeat__Heartbeat *objp
) {
  urosAssert(objp != NULL);

  init_msg__std_msgs__String(&objp->node_name);
}

/**
 * @brief   Cleans a TCPROS <tt>heartbeat/Heartbeat</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__Heartbeat</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__heartbeat__Heartbeat(
  struct msg__heartbeat__Heartbeat *objp
) {
  if (objp == NULL) { return; }

  clean_msg__std_msgs__String(&objp->node_name);
}

/**
 * @brief   Receives a TCPROS <tt>heartbeat/Heartbeat</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__Heartbeat</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__heartbeat__Heartbeat(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__Heartbeat *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__std_msgs__String(tcpstp, &objp->node_name); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__heartbeat__Heartbeat(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>heartbeat/Heartbeat</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__Heartbeat</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__heartbeat__Heartbeat(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__Heartbeat *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__std_msgs__String(tcpstp, &objp->node_name); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: roamros_msgs/SingleTrackAckermannOdometry ~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>roamros_msgs/SingleTrackAckermannOdometry</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>roamros_msgs/SingleTrackAckermannOdometry</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__roamros_msgs__SingleTrackAckermannOdometry</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__roamros_msgs__SingleTrackAckermannOdometry(
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(double);
  length += sizeof(double);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>roamros_msgs/SingleTrackAckermannOdometry</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__roamros_msgs__SingleTrackAckermannOdometry</code> object.
 * @return
 *          Error code.
 */
void init_msg__roamros_msgs__SingleTrackAckermannOdometry(
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>roamros_msgs/SingleTrackAckermannOdometry</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__roamros_msgs__SingleTrackAckermannOdometry</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__roamros_msgs__SingleTrackAckermannOdometry(
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>roamros_msgs/SingleTrackAckermannOdometry</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__roamros_msgs__SingleTrackAckermannOdometry</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__roamros_msgs__SingleTrackAckermannOdometry(
  UrosTcpRosStatus *tcpstp,
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->speed); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->steer); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__roamros_msgs__SingleTrackAckermannOdometry(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>roamros_msgs/SingleTrackAckermannOdometry</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__roamros_msgs__SingleTrackAckermannOdometry</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__roamros_msgs__SingleTrackAckermannOdometry(
  UrosTcpRosStatus *tcpstp,
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->speed); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->steer); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: quadrivio_msgs/SetPoint ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>quadrivio_msgs/SetPoint</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>quadrivio_msgs/SetPoint</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__quadrivio_msgs__SetPoint</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__quadrivio_msgs__SetPoint(
  struct msg__quadrivio_msgs__SetPoint *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(double);
  length += sizeof(double);
  length += sizeof(double);
  length += sizeof(uint8_t);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>quadrivio_msgs/SetPoint</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__quadrivio_msgs__SetPoint</code> object.
 * @return
 *          Error code.
 */
void init_msg__quadrivio_msgs__SetPoint(
  struct msg__quadrivio_msgs__SetPoint *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>quadrivio_msgs/SetPoint</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__quadrivio_msgs__SetPoint</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__quadrivio_msgs__SetPoint(
  struct msg__quadrivio_msgs__SetPoint *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>quadrivio_msgs/SetPoint</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__quadrivio_msgs__SetPoint</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__quadrivio_msgs__SetPoint(
  UrosTcpRosStatus *tcpstp,
  struct msg__quadrivio_msgs__SetPoint *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->speed); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->steer); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->brake); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->source); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__quadrivio_msgs__SetPoint(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>quadrivio_msgs/SetPoint</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__quadrivio_msgs__SetPoint</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__quadrivio_msgs__SetPoint(
  UrosTcpRosStatus *tcpstp,
  struct msg__quadrivio_msgs__SetPoint *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->speed); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->steer); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->brake); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->source); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: heartbeat/State ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>heartbeat/State</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>heartbeat/State</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__State</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__heartbeat__State(
  struct msg__heartbeat__State *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(uint8_t);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>heartbeat/State</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__heartbeat__State</code> object.
 * @return
 *          Error code.
 */
void init_msg__heartbeat__State(
  struct msg__heartbeat__State *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>heartbeat/State</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__State</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__heartbeat__State(
  struct msg__heartbeat__State *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>heartbeat/State</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__State</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__heartbeat__State(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__State *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->value); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__heartbeat__State(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>heartbeat/State</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__heartbeat__State</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__heartbeat__State(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__State *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->value); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/** @} */

/*===========================================================================*/
/* SERVICE FUNCTIONS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_srv_funcs */
/** @{ */

/* There are no service types.*/

/** @} */

/*===========================================================================*/
/* GLOBAL FUNCTIONS                                                          */
/*===========================================================================*/

/** @addtogroup tcpros_funcs */
/** @{ */

/**
 * @brief   Static TCPROS types registration.
 * @details Statically registers all the TCPROS message and service types used
 *          within this source file.
 * @note    Should be called by @p urosUserRegisterStaticMsgTypes().
 * @see     urosUserRegisterStaticMsgTypes()
 */
void urosMsgTypesRegStaticTypes(void) {

  /* MESSAGE TYPES */

  /* heartbeat/Heartbeat */
  urosRegisterStaticMsgTypeSZ("heartbeat/Heartbeat",
                              NULL, "cd38a069af211501ce9a41a4b1793b53");

  /* heartbeat/State */
  urosRegisterStaticMsgTypeSZ("heartbeat/State",
                              NULL, "8894b727e9ea5dc912a2ffdad059695b");

  /* quadrivio_msgs/SetPoint */
  urosRegisterStaticMsgTypeSZ("quadrivio_msgs/SetPoint",
                              NULL, "8bd90c78c2a3e2624e4cb35d1fc6370f");

  /* roamros_msgs/SingleTrackAckermannOdometry */
  urosRegisterStaticMsgTypeSZ("roamros_msgs/SingleTrackAckermannOdometry",
                              NULL, "64a28906316460b1514f030ee73f69e5");

  /* std_msgs/String */
  urosRegisterStaticMsgTypeSZ("std_msgs/String",
                              NULL, "992ce8a1687cec8c8bd883ec73ca41d1");
}

/** @} */

