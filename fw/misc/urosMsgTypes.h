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

/*~~~ MESSAGE: std_msgs/Float32 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>std_msgs/Float32</tt> message descriptor.
 * @details MD5 sum: <tt>73fcbf46b49191e672908e50842a83d4</tt>.
 */
struct msg__std_msgs__Float32 {
  float data;
};

/*~~~ MESSAGE: r2p/Led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/Led</tt> message descriptor.
 * @details MD5 sum: <tt>21a32d72a04d37c1add2e9d9fe9b645e</tt>.
 */
struct msg__r2p__Led {
  uint8_t   led;
  uint8_t   value;
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

/*~~~ MESSAGE: std_msgs/Float32 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__std_msgs__Float32(
  struct msg__std_msgs__Float32 *objp
);
void init_msg__std_msgs__Float32(
  struct msg__std_msgs__Float32 *objp
);
void clean_msg__std_msgs__Float32(
  struct msg__std_msgs__Float32 *objp
);
uros_err_t recv_msg__std_msgs__Float32(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Float32 *objp
);
uros_err_t send_msg__std_msgs__Float32(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Float32 *objp
);

/*~~~ MESSAGE: r2p/Led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__Led(
  struct msg__r2p__Led *objp
);
void init_msg__r2p__Led(
  struct msg__r2p__Led *objp
);
void clean_msg__r2p__Led(
  struct msg__r2p__Led *objp
);
uros_err_t recv_msg__r2p__Led(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Led *objp
);
uros_err_t send_msg__r2p__Led(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Led *objp
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

