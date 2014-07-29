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

/*~~~ MESSAGE: geometry_msgs/Vector3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>geometry_msgs/Vector3</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>geometry_msgs/Vector3</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Vector3</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__geometry_msgs__Vector3(
  struct msg__geometry_msgs__Vector3 *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(double);
  length += sizeof(double);
  length += sizeof(double);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>geometry_msgs/Vector3</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__geometry_msgs__Vector3</code> object.
 * @return
 *          Error code.
 */
void init_msg__geometry_msgs__Vector3(
  struct msg__geometry_msgs__Vector3 *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>geometry_msgs/Vector3</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Vector3</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__geometry_msgs__Vector3(
  struct msg__geometry_msgs__Vector3 *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>geometry_msgs/Vector3</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Vector3</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__geometry_msgs__Vector3(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Vector3 *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->z); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__geometry_msgs__Vector3(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>geometry_msgs/Vector3</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Vector3</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__geometry_msgs__Vector3(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Vector3 *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->z); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: std_msgs/Header ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>std_msgs/Header</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(uint32_t);
  length += sizeof(uros_time_t);
  length += sizeof(uint32_t) + objp->frame_id.length;

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Error code.
 */
void init_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
) {
  urosAssert(objp != NULL);

  urosStringObjectInit(&objp->frame_id);
}

/**
 * @brief   Cleans a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
) {
  if (objp == NULL) { return; }

  urosStringClean(&objp->frame_id);
}

/**
 * @brief   Receives a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->seq); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->stamp); _CHKOK
  urosTcpRosRecvString(tcpstp, &objp->frame_id); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__std_msgs__Header(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>std_msgs/Header</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Header</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->seq); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->stamp); _CHKOK
  urosTcpRosSendString(tcpstp, &objp->frame_id); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: geometry_msgs/Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>geometry_msgs/Point</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>geometry_msgs/Point</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Point</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__geometry_msgs__Point(
  struct msg__geometry_msgs__Point *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(double);
  length += sizeof(double);
  length += sizeof(double);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>geometry_msgs/Point</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__geometry_msgs__Point</code> object.
 * @return
 *          Error code.
 */
void init_msg__geometry_msgs__Point(
  struct msg__geometry_msgs__Point *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>geometry_msgs/Point</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Point</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__geometry_msgs__Point(
  struct msg__geometry_msgs__Point *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>geometry_msgs/Point</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Point</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__geometry_msgs__Point(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Point *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->z); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__geometry_msgs__Point(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>geometry_msgs/Point</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Point</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__geometry_msgs__Point(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Point *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->z); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: geometry_msgs/Quaternion ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>geometry_msgs/Quaternion</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>geometry_msgs/Quaternion</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Quaternion</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__geometry_msgs__Quaternion(
  struct msg__geometry_msgs__Quaternion *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(double);
  length += sizeof(double);
  length += sizeof(double);
  length += sizeof(double);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>geometry_msgs/Quaternion</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__geometry_msgs__Quaternion</code> object.
 * @return
 *          Error code.
 */
void init_msg__geometry_msgs__Quaternion(
  struct msg__geometry_msgs__Quaternion *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>geometry_msgs/Quaternion</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Quaternion</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__geometry_msgs__Quaternion(
  struct msg__geometry_msgs__Quaternion *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>geometry_msgs/Quaternion</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Quaternion</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__geometry_msgs__Quaternion(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Quaternion *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->z); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->w); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__geometry_msgs__Quaternion(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>geometry_msgs/Quaternion</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Quaternion</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__geometry_msgs__Quaternion(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Quaternion *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->z); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->w); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: geometry_msgs/Twist ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>geometry_msgs/Twist</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>geometry_msgs/Twist</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Twist</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__geometry_msgs__Twist(
  struct msg__geometry_msgs__Twist *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__geometry_msgs__Vector3(&objp->linear);
  length += length_msg__geometry_msgs__Vector3(&objp->angular);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>geometry_msgs/Twist</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__geometry_msgs__Twist</code> object.
 * @return
 *          Error code.
 */
void init_msg__geometry_msgs__Twist(
  struct msg__geometry_msgs__Twist *objp
) {
  urosAssert(objp != NULL);

  init_msg__geometry_msgs__Vector3(&objp->linear);
  init_msg__geometry_msgs__Vector3(&objp->angular);
}

/**
 * @brief   Cleans a TCPROS <tt>geometry_msgs/Twist</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Twist</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__geometry_msgs__Twist(
  struct msg__geometry_msgs__Twist *objp
) {
  if (objp == NULL) { return; }

  clean_msg__geometry_msgs__Vector3(&objp->linear);
  clean_msg__geometry_msgs__Vector3(&objp->angular);
}

/**
 * @brief   Receives a TCPROS <tt>geometry_msgs/Twist</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Twist</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__geometry_msgs__Twist(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Twist *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__geometry_msgs__Vector3(tcpstp, &objp->linear); _CHKOK
  recv_msg__geometry_msgs__Vector3(tcpstp, &objp->angular); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__geometry_msgs__Twist(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>geometry_msgs/Twist</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Twist</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__geometry_msgs__Twist(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Twist *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__geometry_msgs__Vector3(tcpstp, &objp->linear); _CHKOK
  send_msg__geometry_msgs__Vector3(tcpstp, &objp->angular); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: geometry_msgs/Pose ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>geometry_msgs/Pose</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>geometry_msgs/Pose</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Pose</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__geometry_msgs__Pose(
  struct msg__geometry_msgs__Pose *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__geometry_msgs__Point(&objp->position);
  length += length_msg__geometry_msgs__Quaternion(&objp->orientation);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>geometry_msgs/Pose</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__geometry_msgs__Pose</code> object.
 * @return
 *          Error code.
 */
void init_msg__geometry_msgs__Pose(
  struct msg__geometry_msgs__Pose *objp
) {
  urosAssert(objp != NULL);

  init_msg__geometry_msgs__Point(&objp->position);
  init_msg__geometry_msgs__Quaternion(&objp->orientation);
}

/**
 * @brief   Cleans a TCPROS <tt>geometry_msgs/Pose</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Pose</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__geometry_msgs__Pose(
  struct msg__geometry_msgs__Pose *objp
) {
  if (objp == NULL) { return; }

  clean_msg__geometry_msgs__Point(&objp->position);
  clean_msg__geometry_msgs__Quaternion(&objp->orientation);
}

/**
 * @brief   Receives a TCPROS <tt>geometry_msgs/Pose</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Pose</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__geometry_msgs__Pose(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Pose *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__geometry_msgs__Point(tcpstp, &objp->position); _CHKOK
  recv_msg__geometry_msgs__Quaternion(tcpstp, &objp->orientation); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__geometry_msgs__Pose(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>geometry_msgs/Pose</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__Pose</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__geometry_msgs__Pose(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Pose *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__geometry_msgs__Point(tcpstp, &objp->position); _CHKOK
  send_msg__geometry_msgs__Quaternion(tcpstp, &objp->orientation); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: geometry_msgs/TwistStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>geometry_msgs/TwistStamped</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>geometry_msgs/TwistStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__TwistStamped</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__geometry_msgs__TwistStamped(
  struct msg__geometry_msgs__TwistStamped *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__std_msgs__Header(&objp->header);
  length += length_msg__geometry_msgs__Twist(&objp->twist);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>geometry_msgs/TwistStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__geometry_msgs__TwistStamped</code> object.
 * @return
 *          Error code.
 */
void init_msg__geometry_msgs__TwistStamped(
  struct msg__geometry_msgs__TwistStamped *objp
) {
  urosAssert(objp != NULL);

  init_msg__std_msgs__Header(&objp->header);
  init_msg__geometry_msgs__Twist(&objp->twist);
}

/**
 * @brief   Cleans a TCPROS <tt>geometry_msgs/TwistStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__TwistStamped</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__geometry_msgs__TwistStamped(
  struct msg__geometry_msgs__TwistStamped *objp
) {
  if (objp == NULL) { return; }

  clean_msg__std_msgs__Header(&objp->header);
  clean_msg__geometry_msgs__Twist(&objp->twist);
}

/**
 * @brief   Receives a TCPROS <tt>geometry_msgs/TwistStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__TwistStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__geometry_msgs__TwistStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__TwistStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  recv_msg__geometry_msgs__Twist(tcpstp, &objp->twist); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__geometry_msgs__TwistStamped(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>geometry_msgs/TwistStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__TwistStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__geometry_msgs__TwistStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__TwistStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  send_msg__geometry_msgs__Twist(tcpstp, &objp->twist); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: geometry_msgs/PoseStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>geometry_msgs/PoseStamped</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>geometry_msgs/PoseStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__PoseStamped</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__geometry_msgs__PoseStamped(
  struct msg__geometry_msgs__PoseStamped *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__std_msgs__Header(&objp->header);
  length += length_msg__geometry_msgs__Pose(&objp->pose);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>geometry_msgs/PoseStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__geometry_msgs__PoseStamped</code> object.
 * @return
 *          Error code.
 */
void init_msg__geometry_msgs__PoseStamped(
  struct msg__geometry_msgs__PoseStamped *objp
) {
  urosAssert(objp != NULL);

  init_msg__std_msgs__Header(&objp->header);
  init_msg__geometry_msgs__Pose(&objp->pose);
}

/**
 * @brief   Cleans a TCPROS <tt>geometry_msgs/PoseStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__PoseStamped</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__geometry_msgs__PoseStamped(
  struct msg__geometry_msgs__PoseStamped *objp
) {
  if (objp == NULL) { return; }

  clean_msg__std_msgs__Header(&objp->header);
  clean_msg__geometry_msgs__Pose(&objp->pose);
}

/**
 * @brief   Receives a TCPROS <tt>geometry_msgs/PoseStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__PoseStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__geometry_msgs__PoseStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__PoseStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  recv_msg__geometry_msgs__Pose(tcpstp, &objp->pose); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__geometry_msgs__PoseStamped(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>geometry_msgs/PoseStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__geometry_msgs__PoseStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__geometry_msgs__PoseStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__PoseStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  send_msg__geometry_msgs__Pose(tcpstp, &objp->pose); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: r2p/Encoder ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/Encoder</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/Encoder</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__Encoder(
  struct msg__r2p__Encoder *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(float);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/Encoder</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__Encoder</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__Encoder(
  struct msg__r2p__Encoder *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/Encoder</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__Encoder(
  struct msg__r2p__Encoder *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>r2p/Encoder</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__Encoder(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->delta); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__r2p__Encoder(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/Encoder</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__Encoder(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->delta); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: r2p/Encoder2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/Encoder2</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/Encoder2</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder2</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__Encoder2(
  struct msg__r2p__Encoder2 *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(float);
  length += sizeof(float);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/Encoder2</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__Encoder2</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__Encoder2(
  struct msg__r2p__Encoder2 *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/Encoder2</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder2</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__Encoder2(
  struct msg__r2p__Encoder2 *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>r2p/Encoder2</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder2</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__Encoder2(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder2 *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->left_delta); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->right_delta); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__r2p__Encoder2(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/Encoder2</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__Encoder2</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__Encoder2(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder2 *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->left_delta); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->right_delta); _CHKOK

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

  /* geometry_msgs/Point */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/Point",
                              NULL, "4a842b65f413084dc2b10fb484ea7f17");

  /* geometry_msgs/Pose */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/Pose",
                              NULL, "e45d45a5a1ce597b249e23fb30fc871f");

  /* geometry_msgs/PoseStamped */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/PoseStamped",
                              NULL, "d3812c3cbc69362b77dc0b19b345f8f5");

  /* geometry_msgs/Quaternion */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/Quaternion",
                              NULL, "a779879fadf0160734f906b8c19c7004");

  /* geometry_msgs/Twist */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/Twist",
                              NULL, "9f195f881246fdfa2798d1d3eebca84a");

  /* geometry_msgs/TwistStamped */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/TwistStamped",
                              NULL, "98d34b0043a2093cf9d9345ab6eef12e");

  /* geometry_msgs/Vector3 */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/Vector3",
                              NULL, "4a842b65f413084dc2b10fb484ea7f17");

  /* r2p/Encoder */
  urosRegisterStaticMsgTypeSZ("r2p/Encoder",
                              NULL, "b808a22d9acab1efdc64ddcf9bf82dfc");

  /* r2p/Encoder2 */
  urosRegisterStaticMsgTypeSZ("r2p/Encoder2",
                              NULL, "4acf5cfc85b53b1f9357f2a7f535ca66");

  /* std_msgs/Header */
  urosRegisterStaticMsgTypeSZ("std_msgs/Header",
                              NULL, "2176decaecbce78abc3b96ef049fabed");
}

/** @} */

