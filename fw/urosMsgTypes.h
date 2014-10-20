/**
 * @file    urosMsgTypes.h
 * @author  TODO
 *
 * @brief   TCPROS message and service descriptors.
 */

#ifndef _UROSMSGTYPES_H_
#define _UROSMSGTYPES_H_

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include <urosTcpRos.h>

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================*/
/*  MESSAGE TYPES                                                            */
/*===========================================================================*/

/** @addtogroup tcpros_msg_types */
/** @{ */

/*~~~ MESSAGE: tiltone/Tilt ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>tiltone/Tilt</tt> message descriptor.
 * @details MD5 sum: <tt>2d11dcdbe5a6f73dd324353dc52315ab</tt>.
 */
struct msg__tiltone__Tilt {
  float angle;
};

/*~~~ MESSAGE: r2p/Velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/Velocity</tt> message descriptor.
 * @details MD5 sum: <tt>fc16a6b45aaa44f2dd9023be467748ee</tt>.
 */
struct msg__r2p__Velocity {
  float x;
  float y;
  float w;
};

/** @} */

/*===========================================================================*/
/* SERVICE TYPES                                                             */
/*===========================================================================*/

/** @addtogroup tcpros_srv_types */
/** @{ */

/* There are no service types.*/

/** @} */

/*===========================================================================*/
/* MESSAGE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_msg_consts */
/** @{ */

/* There are no message costants.*/

/** @} */

/*===========================================================================*/
/* SERVICE CONSTANTS                                                         */
/*===========================================================================*/

/** @addtogroup tcpros_srv_consts */
/** @{ */

/* There are no service costants.*/

/** @} */

/*===========================================================================*/
/* MESSAGE PROTOTYPES                                                        */
/*===========================================================================*/

/*~~~ MESSAGE: tiltone/Tilt ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__tiltone__Tilt(
  struct msg__tiltone__Tilt *objp
);
void init_msg__tiltone__Tilt(
  struct msg__tiltone__Tilt *objp
);
void clean_msg__tiltone__Tilt(
  struct msg__tiltone__Tilt *objp
);
uros_err_t recv_msg__tiltone__Tilt(
  UrosTcpRosStatus *tcpstp,
  struct msg__tiltone__Tilt *objp
);
uros_err_t send_msg__tiltone__Tilt(
  UrosTcpRosStatus *tcpstp,
  struct msg__tiltone__Tilt *objp
);

/*~~~ MESSAGE: r2p/Velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__Velocity(
  struct msg__r2p__Velocity *objp
);
void init_msg__r2p__Velocity(
  struct msg__r2p__Velocity *objp
);
void clean_msg__r2p__Velocity(
  struct msg__r2p__Velocity *objp
);
uros_err_t recv_msg__r2p__Velocity(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Velocity *objp
);
uros_err_t send_msg__r2p__Velocity(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Velocity *objp
);

/*===========================================================================*/
/* SERVICE PROTOTYPES                                                        */
/*===========================================================================*/

/* There are no service types.*/

/*===========================================================================*/
/* GLOBAL PROTOTYPES                                                         */
/*===========================================================================*/

void urosMsgTypesRegStaticTypes(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _UROSMSGTYPES_H_ */

