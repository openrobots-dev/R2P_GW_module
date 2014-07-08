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

/*~~~ MESSAGE: std_msgs/Float32 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>std_msgs/Float32</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>std_msgs/Float32</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Float32</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__std_msgs__Float32(
  struct msg__std_msgs__Float32 *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(float);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>std_msgs/Float32</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__std_msgs__Float32</code> object.
 * @return
 *          Error code.
 */
void init_msg__std_msgs__Float32(
  struct msg__std_msgs__Float32 *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>std_msgs/Float32</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Float32</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__std_msgs__Float32(
  struct msg__std_msgs__Float32 *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>std_msgs/Float32</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Float32</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__std_msgs__Float32(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Float32 *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->data); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__std_msgs__Float32(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>std_msgs/Float32</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__std_msgs__Float32</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__std_msgs__Float32(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Float32 *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->data); _CHKOK

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

  /* r2p/Led */
  urosRegisterStaticMsgTypeSZ("r2p/Led",
                              NULL, "21a32d72a04d37c1add2e9d9fe9b645e");

  /* std_msgs/Float32 */
  urosRegisterStaticMsgTypeSZ("std_msgs/Float32",
                              NULL, "73fcbf46b49191e672908e50842a83d4");
}

/** @} */

