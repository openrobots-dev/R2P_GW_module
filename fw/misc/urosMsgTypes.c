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

  /* geometry_msgs/Twist */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/Twist",
                              NULL, "9f195f881246fdfa2798d1d3eebca84a");

  /* geometry_msgs/Vector3 */
  urosRegisterStaticMsgTypeSZ("geometry_msgs/Vector3",
                              NULL, "4a842b65f413084dc2b10fb484ea7f17");

  /* r2p/Encoder */
  urosRegisterStaticMsgTypeSZ("r2p/Encoder",
                              NULL, "b808a22d9acab1efdc64ddcf9bf82dfc");

  /* r2p/Encoder2 */
  urosRegisterStaticMsgTypeSZ("r2p/Encoder2",
                              NULL, "4acf5cfc85b53b1f9357f2a7f535ca66");
}

/** @} */

