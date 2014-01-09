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

/*~~~ MESSAGE: r2p/Vector3_32 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/Vector3_32</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/Vector3_32</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Vector3_32</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__Vector3_32(
  struct msg__r2p__Vector3_32 *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(float);
  length += sizeof(float);
  length += sizeof(float);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/Vector3_32</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__Vector3_32</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__Vector3_32(
  struct msg__r2p__Vector3_32 *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/Vector3_32</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Vector3_32</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__Vector3_32(
  struct msg__r2p__Vector3_32 *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>r2p/Vector3_32</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Vector3_32</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__Vector3_32(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Vector3_32 *objp
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
  clean_msg__r2p__Vector3_32(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/Vector3_32</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__Vector3_32</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__Vector3_32(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Vector3_32 *objp
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

/*~~~ MESSAGE: r2p/Imu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/Imu</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/Imu</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Imu</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__Imu(
  struct msg__r2p__Imu *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__r2p__Vector3_32(&objp->angular_velocity);
  length += length_msg__r2p__Vector3_32(&objp->linear_acceleration);
  length += length_msg__r2p__Vector3_32(&objp->magnetic_field);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/Imu</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__Imu</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__Imu(
  struct msg__r2p__Imu *objp
) {
  urosAssert(objp != NULL);

  init_msg__r2p__Vector3_32(&objp->angular_velocity);
  init_msg__r2p__Vector3_32(&objp->linear_acceleration);
  init_msg__r2p__Vector3_32(&objp->magnetic_field);
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/Imu</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Imu</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__Imu(
  struct msg__r2p__Imu *objp
) {
  if (objp == NULL) { return; }

  clean_msg__r2p__Vector3_32(&objp->angular_velocity);
  clean_msg__r2p__Vector3_32(&objp->linear_acceleration);
  clean_msg__r2p__Vector3_32(&objp->magnetic_field);
}

/**
 * @brief   Receives a TCPROS <tt>r2p/Imu</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Imu</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__Imu(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Imu *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__r2p__Vector3_32(tcpstp, &objp->angular_velocity); _CHKOK
  recv_msg__r2p__Vector3_32(tcpstp, &objp->linear_acceleration); _CHKOK
  recv_msg__r2p__Vector3_32(tcpstp, &objp->magnetic_field); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__r2p__Imu(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/Imu</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__Imu</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__Imu(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Imu *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__r2p__Vector3_32(tcpstp, &objp->angular_velocity); _CHKOK
  send_msg__r2p__Vector3_32(tcpstp, &objp->linear_acceleration); _CHKOK
  send_msg__r2p__Vector3_32(tcpstp, &objp->magnetic_field); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: r2p/EncoderStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/EncoderStamped</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/EncoderStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__EncoderStamped</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__EncoderStamped(
  struct msg__r2p__EncoderStamped *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__std_msgs__Header(&objp->header);
  length += length_msg__r2p__Encoder(&objp->encoder);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/EncoderStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__EncoderStamped</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__EncoderStamped(
  struct msg__r2p__EncoderStamped *objp
) {
  urosAssert(objp != NULL);

  init_msg__std_msgs__Header(&objp->header);
  init_msg__r2p__Encoder(&objp->encoder);
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/EncoderStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__EncoderStamped</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__EncoderStamped(
  struct msg__r2p__EncoderStamped *objp
) {
  if (objp == NULL) { return; }

  clean_msg__std_msgs__Header(&objp->header);
  clean_msg__r2p__Encoder(&objp->encoder);
}

/**
 * @brief   Receives a TCPROS <tt>r2p/EncoderStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__EncoderStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__EncoderStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__EncoderStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  recv_msg__r2p__Encoder(tcpstp, &objp->encoder); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__r2p__EncoderStamped(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/EncoderStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__EncoderStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__EncoderStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__EncoderStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  send_msg__r2p__Encoder(tcpstp, &objp->encoder); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: r2p/ImuStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/ImuStamped</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/ImuStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__ImuStamped</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__ImuStamped(
  struct msg__r2p__ImuStamped *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += length_msg__std_msgs__Header(&objp->header);
  length += length_msg__r2p__Imu(&objp->imu);

  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/ImuStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__ImuStamped</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__ImuStamped(
  struct msg__r2p__ImuStamped *objp
) {
  urosAssert(objp != NULL);

  init_msg__std_msgs__Header(&objp->header);
  init_msg__r2p__Imu(&objp->imu);
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/ImuStamped</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__ImuStamped</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__ImuStamped(
  struct msg__r2p__ImuStamped *objp
) {
  if (objp == NULL) { return; }

  clean_msg__std_msgs__Header(&objp->header);
  clean_msg__r2p__Imu(&objp->imu);
}

/**
 * @brief   Receives a TCPROS <tt>r2p/ImuStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__ImuStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__ImuStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__ImuStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  recv_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  recv_msg__r2p__Imu(tcpstp, &objp->imu); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__r2p__ImuStamped(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/ImuStamped</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__ImuStamped</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__ImuStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__ImuStamped *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  send_msg__std_msgs__Header(tcpstp, &objp->header); _CHKOK
  send_msg__r2p__Imu(tcpstp, &objp->imu); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: r2p/Led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/Led</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/Led</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Led</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__Led(
  struct msg__r2p__Led *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(uint8_t);
  length += sizeof(uint8_t);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/Led</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__Led</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__Led(
  struct msg__r2p__Led *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/Led</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Led</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__Led(
  struct msg__r2p__Led *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>r2p/Led</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Led</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__Led(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Led *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->led); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->value); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__r2p__Led(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/Led</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__Led</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__Led(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Led *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->led); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->value); _CHKOK

  return tcpstp->err = UROS_OK;
#undef _CHKOK
}

/** @} */

/*~~~ MESSAGE: r2p/Velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>r2p/Velocity</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>r2p/Velocity</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Velocity</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__r2p__Velocity(
  struct msg__r2p__Velocity *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(float);
  length += sizeof(float);
  length += sizeof(float);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>r2p/Velocity</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__r2p__Velocity</code> object.
 * @return
 *          Error code.
 */
void init_msg__r2p__Velocity(
  struct msg__r2p__Velocity *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>r2p/Velocity</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Velocity</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__r2p__Velocity(
  struct msg__r2p__Velocity *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>r2p/Velocity</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__r2p__Velocity</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__r2p__Velocity(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Velocity *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosRecvRaw(tcpstp, objp->w); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__r2p__Velocity(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>r2p/Velocity</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__r2p__Velocity</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__r2p__Velocity(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Velocity *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->x); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->y); _CHKOK
  urosTcpRosSendRaw(tcpstp, objp->w); _CHKOK

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

  /* r2p/Encoder */
  urosRegisterStaticMsgTypeSZ("r2p/Encoder",
                              NULL, "b808a22d9acab1efdc64ddcf9bf82dfc");

  /* r2p/EncoderStamped */
  urosRegisterStaticMsgTypeSZ("r2p/EncoderStamped",
                              NULL, "6d28db09933fa8a280e44044a6edf9c1");

  /* r2p/Imu */
  urosRegisterStaticMsgTypeSZ("r2p/Imu",
                              NULL, "038fa76b07790b50cb414643eae47fb9");

  /* r2p/ImuStamped */
  urosRegisterStaticMsgTypeSZ("r2p/ImuStamped",
                              NULL, "d6823896cc6d75a6a5a20427e3fde1a0");

  /* r2p/Led */
  urosRegisterStaticMsgTypeSZ("r2p/Led",
                              NULL, "21a32d72a04d37c1add2e9d9fe9b645e");

  /* r2p/Vector3_32 */
  urosRegisterStaticMsgTypeSZ("r2p/Vector3_32",
                              NULL, "cc153912f1453b708d221682bc23d9ac");

  /* r2p/Velocity */
  urosRegisterStaticMsgTypeSZ("r2p/Velocity",
                              NULL, "fc16a6b45aaa44f2dd9023be467748ee");

  /* std_msgs/Header */
  urosRegisterStaticMsgTypeSZ("std_msgs/Header",
                              NULL, "2176decaecbce78abc3b96ef049fabed");
}

/** @} */

