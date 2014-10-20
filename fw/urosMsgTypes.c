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

/*~~~ MESSAGE: tiltone/Tilt ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>tiltone/Tilt</tt> */
/** @{ */

/**
 * @brief   Content length of a TCPROS <tt>tiltone/Tilt</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__tiltone__Tilt</code> object.
 * @return
 *          Length of the TCPROS message contents, in bytes.
 */
size_t length_msg__tiltone__Tilt(
  struct msg__tiltone__Tilt *objp
) {
  size_t length = 0;

  urosAssert(objp != NULL);

  length += sizeof(float);

  (void)objp;
  return length;
}

/**
 * @brief   Initializes a TCPROS <tt>tiltone/Tilt</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an allocated <code>struct msg__tiltone__Tilt</code> object.
 * @return
 *          Error code.
 */
void init_msg__tiltone__Tilt(
  struct msg__tiltone__Tilt *objp
) {
  urosAssert(objp != NULL);

  /* Nothing to initialize.*/
  (void)objp;
}

/**
 * @brief   Cleans a TCPROS <tt>tiltone/Tilt</tt> message.
 *
 * @param[in,out] objp
 *          Pointer to an initialized <code>struct msg__tiltone__Tilt</code> object, or @p NULL.
 * @return
 *          Error code.
 */
void clean_msg__tiltone__Tilt(
  struct msg__tiltone__Tilt *objp
) {
  /* Nothing to clean.*/
  (void)objp;
}

/**
 * @brief   Receives a TCPROS <tt>tiltone/Tilt</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[out] objp
 *          Pointer to an initialized <code>struct msg__tiltone__Tilt</code> object.
 * @return
 *          Error code.
 */
uros_err_t recv_msg__tiltone__Tilt(
  UrosTcpRosStatus *tcpstp,
  struct msg__tiltone__Tilt *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { goto _error; } }

  urosTcpRosRecvRaw(tcpstp, objp->angle); _CHKOK

  return tcpstp->err = UROS_OK;
_error:
  clean_msg__tiltone__Tilt(objp);
  return tcpstp->err;
#undef _CHKOK
}

/**
 * @brief   Sends a TCPROS <tt>tiltone/Tilt</tt> message.
 *
 * @param[in,out] tcpstp
 *          Pointer to a working @p UrosTcpRosStatus object.
 * @param[in] objp
 *          Pointer to an initialized <code>struct msg__tiltone__Tilt</code> object.
 * @return
 *          Error code.
 */
uros_err_t send_msg__tiltone__Tilt(
  UrosTcpRosStatus *tcpstp,
  struct msg__tiltone__Tilt *objp
) {
  urosAssert(tcpstp != NULL);
  urosAssert(urosConnIsValid(tcpstp->csp));
  urosAssert(objp != NULL);
#define _CHKOK { if (tcpstp->err != UROS_OK) { return tcpstp->err; } }

  urosTcpRosSendRaw(tcpstp, objp->angle); _CHKOK

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

  /* r2p/Velocity */
  urosRegisterStaticMsgTypeSZ("r2p/Velocity",
                              NULL, "fc16a6b45aaa44f2dd9023be467748ee");

  /* tiltone/Tilt */
  urosRegisterStaticMsgTypeSZ("tiltone/Tilt",
                              NULL, "2d11dcdbe5a6f73dd324353dc52315ab");
}

/** @} */

