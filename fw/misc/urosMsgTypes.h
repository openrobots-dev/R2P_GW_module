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

/*~~~ MESSAGE: r2p/Vector3_32 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/Vector3_32</tt> message descriptor.
 * @details MD5 sum: <tt>cc153912f1453b708d221682bc23d9ac</tt>.
 */
struct msg__r2p__Vector3_32 {
  float x;
  float y;
  float z;
};

/*~~~ MESSAGE: std_msgs/Header ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>std_msgs/Header</tt> message descriptor.
 * @details MD5 sum: <tt>2176decaecbce78abc3b96ef049fabed</tt>.
 */
struct msg__std_msgs__Header {
  uint32_t      seq;
  uros_time_t   stamp;
  UrosString    frame_id;
};

/*~~~ MESSAGE: r2p/Encoder ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/Encoder</tt> message descriptor.
 * @details MD5 sum: <tt>b808a22d9acab1efdc64ddcf9bf82dfc</tt>.
 */
struct msg__r2p__Encoder {
  float delta;
};

/*~~~ MESSAGE: r2p/Imu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/Imu</tt> message descriptor.
 * @details MD5 sum: <tt>038fa76b07790b50cb414643eae47fb9</tt>.
 */
struct msg__r2p__Imu {
  struct msg__r2p__Vector3_32   angular_velocity;
  struct msg__r2p__Vector3_32   linear_acceleration;
  struct msg__r2p__Vector3_32   magnetic_field;
};

/*~~~ MESSAGE: r2p/EncoderStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/EncoderStamped</tt> message descriptor.
 * @details MD5 sum: <tt>6d28db09933fa8a280e44044a6edf9c1</tt>.
 */
struct msg__r2p__EncoderStamped {
  struct msg__std_msgs__Header  header;
  struct msg__r2p__Encoder      encoder;
};

/*~~~ MESSAGE: r2p/ImuStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/ImuStamped</tt> message descriptor.
 * @details MD5 sum: <tt>d6823896cc6d75a6a5a20427e3fde1a0</tt>.
 */
struct msg__r2p__ImuStamped {
  struct msg__std_msgs__Header  header;
  struct msg__r2p__Imu          imu;
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

/*~~~ MESSAGE: r2p/Vector3_32 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__Vector3_32(
  struct msg__r2p__Vector3_32 *objp
);
void init_msg__r2p__Vector3_32(
  struct msg__r2p__Vector3_32 *objp
);
void clean_msg__r2p__Vector3_32(
  struct msg__r2p__Vector3_32 *objp
);
uros_err_t recv_msg__r2p__Vector3_32(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Vector3_32 *objp
);
uros_err_t send_msg__r2p__Vector3_32(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Vector3_32 *objp
);

/*~~~ MESSAGE: std_msgs/Header ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
);
void init_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
);
void clean_msg__std_msgs__Header(
  struct msg__std_msgs__Header *objp
);
uros_err_t recv_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
);
uros_err_t send_msg__std_msgs__Header(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__Header *objp
);

/*~~~ MESSAGE: r2p/Encoder ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__Encoder(
  struct msg__r2p__Encoder *objp
);
void init_msg__r2p__Encoder(
  struct msg__r2p__Encoder *objp
);
void clean_msg__r2p__Encoder(
  struct msg__r2p__Encoder *objp
);
uros_err_t recv_msg__r2p__Encoder(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder *objp
);
uros_err_t send_msg__r2p__Encoder(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder *objp
);

/*~~~ MESSAGE: r2p/Imu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__Imu(
  struct msg__r2p__Imu *objp
);
void init_msg__r2p__Imu(
  struct msg__r2p__Imu *objp
);
void clean_msg__r2p__Imu(
  struct msg__r2p__Imu *objp
);
uros_err_t recv_msg__r2p__Imu(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Imu *objp
);
uros_err_t send_msg__r2p__Imu(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Imu *objp
);

/*~~~ MESSAGE: r2p/EncoderStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__EncoderStamped(
  struct msg__r2p__EncoderStamped *objp
);
void init_msg__r2p__EncoderStamped(
  struct msg__r2p__EncoderStamped *objp
);
void clean_msg__r2p__EncoderStamped(
  struct msg__r2p__EncoderStamped *objp
);
uros_err_t recv_msg__r2p__EncoderStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__EncoderStamped *objp
);
uros_err_t send_msg__r2p__EncoderStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__EncoderStamped *objp
);

/*~~~ MESSAGE: r2p/ImuStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__ImuStamped(
  struct msg__r2p__ImuStamped *objp
);
void init_msg__r2p__ImuStamped(
  struct msg__r2p__ImuStamped *objp
);
void clean_msg__r2p__ImuStamped(
  struct msg__r2p__ImuStamped *objp
);
uros_err_t recv_msg__r2p__ImuStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__ImuStamped *objp
);
uros_err_t send_msg__r2p__ImuStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__ImuStamped *objp
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

