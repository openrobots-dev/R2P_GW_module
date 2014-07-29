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

/*~~~ MESSAGE: geometry_msgs/Vector3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>geometry_msgs/Vector3</tt> message descriptor.
 * @details MD5 sum: <tt>4a842b65f413084dc2b10fb484ea7f17</tt>.
 */
struct msg__geometry_msgs__Vector3 {
  double    x;
  double    y;
  double    z;
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

/*~~~ MESSAGE: geometry_msgs/Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>geometry_msgs/Point</tt> message descriptor.
 * @details MD5 sum: <tt>4a842b65f413084dc2b10fb484ea7f17</tt>.
 */
struct msg__geometry_msgs__Point {
  double    x;
  double    y;
  double    z;
};

/*~~~ MESSAGE: geometry_msgs/Quaternion ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>geometry_msgs/Quaternion</tt> message descriptor.
 * @details MD5 sum: <tt>a779879fadf0160734f906b8c19c7004</tt>.
 */
struct msg__geometry_msgs__Quaternion {
  double    x;
  double    y;
  double    z;
  double    w;
};

/*~~~ MESSAGE: geometry_msgs/Twist ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>geometry_msgs/Twist</tt> message descriptor.
 * @details MD5 sum: <tt>9f195f881246fdfa2798d1d3eebca84a</tt>.
 */
struct msg__geometry_msgs__Twist {
  struct msg__geometry_msgs__Vector3    linear;
  struct msg__geometry_msgs__Vector3    angular;
};

/*~~~ MESSAGE: geometry_msgs/Pose ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>geometry_msgs/Pose</tt> message descriptor.
 * @details MD5 sum: <tt>e45d45a5a1ce597b249e23fb30fc871f</tt>.
 */
struct msg__geometry_msgs__Pose {
  struct msg__geometry_msgs__Point      position;
  struct msg__geometry_msgs__Quaternion orientation;
};

/*~~~ MESSAGE: geometry_msgs/TwistStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>geometry_msgs/TwistStamped</tt> message descriptor.
 * @details MD5 sum: <tt>98d34b0043a2093cf9d9345ab6eef12e</tt>.
 */
struct msg__geometry_msgs__TwistStamped {
  struct msg__std_msgs__Header      header;
  struct msg__geometry_msgs__Twist  twist;
};

/*~~~ MESSAGE: geometry_msgs/PoseStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>geometry_msgs/PoseStamped</tt> message descriptor.
 * @details MD5 sum: <tt>d3812c3cbc69362b77dc0b19b345f8f5</tt>.
 */
struct msg__geometry_msgs__PoseStamped {
  struct msg__std_msgs__Header      header;
  struct msg__geometry_msgs__Pose   pose;
};

/*~~~ MESSAGE: r2p/Encoder ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/Encoder</tt> message descriptor.
 * @details MD5 sum: <tt>b808a22d9acab1efdc64ddcf9bf82dfc</tt>.
 */
struct msg__r2p__Encoder {
  float delta;
};

/*~~~ MESSAGE: r2p/Encoder2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>r2p/Encoder2</tt> message descriptor.
 * @details MD5 sum: <tt>4acf5cfc85b53b1f9357f2a7f535ca66</tt>.
 */
struct msg__r2p__Encoder2 {
  float left_delta;
  float right_delta;
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

/*~~~ MESSAGE: geometry_msgs/Vector3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__geometry_msgs__Vector3(
  struct msg__geometry_msgs__Vector3 *objp
);
void init_msg__geometry_msgs__Vector3(
  struct msg__geometry_msgs__Vector3 *objp
);
void clean_msg__geometry_msgs__Vector3(
  struct msg__geometry_msgs__Vector3 *objp
);
uros_err_t recv_msg__geometry_msgs__Vector3(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Vector3 *objp
);
uros_err_t send_msg__geometry_msgs__Vector3(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Vector3 *objp
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

/*~~~ MESSAGE: geometry_msgs/Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__geometry_msgs__Point(
  struct msg__geometry_msgs__Point *objp
);
void init_msg__geometry_msgs__Point(
  struct msg__geometry_msgs__Point *objp
);
void clean_msg__geometry_msgs__Point(
  struct msg__geometry_msgs__Point *objp
);
uros_err_t recv_msg__geometry_msgs__Point(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Point *objp
);
uros_err_t send_msg__geometry_msgs__Point(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Point *objp
);

/*~~~ MESSAGE: geometry_msgs/Quaternion ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__geometry_msgs__Quaternion(
  struct msg__geometry_msgs__Quaternion *objp
);
void init_msg__geometry_msgs__Quaternion(
  struct msg__geometry_msgs__Quaternion *objp
);
void clean_msg__geometry_msgs__Quaternion(
  struct msg__geometry_msgs__Quaternion *objp
);
uros_err_t recv_msg__geometry_msgs__Quaternion(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Quaternion *objp
);
uros_err_t send_msg__geometry_msgs__Quaternion(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Quaternion *objp
);

/*~~~ MESSAGE: geometry_msgs/Twist ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__geometry_msgs__Twist(
  struct msg__geometry_msgs__Twist *objp
);
void init_msg__geometry_msgs__Twist(
  struct msg__geometry_msgs__Twist *objp
);
void clean_msg__geometry_msgs__Twist(
  struct msg__geometry_msgs__Twist *objp
);
uros_err_t recv_msg__geometry_msgs__Twist(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Twist *objp
);
uros_err_t send_msg__geometry_msgs__Twist(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Twist *objp
);

/*~~~ MESSAGE: geometry_msgs/Pose ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__geometry_msgs__Pose(
  struct msg__geometry_msgs__Pose *objp
);
void init_msg__geometry_msgs__Pose(
  struct msg__geometry_msgs__Pose *objp
);
void clean_msg__geometry_msgs__Pose(
  struct msg__geometry_msgs__Pose *objp
);
uros_err_t recv_msg__geometry_msgs__Pose(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Pose *objp
);
uros_err_t send_msg__geometry_msgs__Pose(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__Pose *objp
);

/*~~~ MESSAGE: geometry_msgs/TwistStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__geometry_msgs__TwistStamped(
  struct msg__geometry_msgs__TwistStamped *objp
);
void init_msg__geometry_msgs__TwistStamped(
  struct msg__geometry_msgs__TwistStamped *objp
);
void clean_msg__geometry_msgs__TwistStamped(
  struct msg__geometry_msgs__TwistStamped *objp
);
uros_err_t recv_msg__geometry_msgs__TwistStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__TwistStamped *objp
);
uros_err_t send_msg__geometry_msgs__TwistStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__TwistStamped *objp
);

/*~~~ MESSAGE: geometry_msgs/PoseStamped ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__geometry_msgs__PoseStamped(
  struct msg__geometry_msgs__PoseStamped *objp
);
void init_msg__geometry_msgs__PoseStamped(
  struct msg__geometry_msgs__PoseStamped *objp
);
void clean_msg__geometry_msgs__PoseStamped(
  struct msg__geometry_msgs__PoseStamped *objp
);
uros_err_t recv_msg__geometry_msgs__PoseStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__PoseStamped *objp
);
uros_err_t send_msg__geometry_msgs__PoseStamped(
  UrosTcpRosStatus *tcpstp,
  struct msg__geometry_msgs__PoseStamped *objp
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

/*~~~ MESSAGE: r2p/Encoder2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__r2p__Encoder2(
  struct msg__r2p__Encoder2 *objp
);
void init_msg__r2p__Encoder2(
  struct msg__r2p__Encoder2 *objp
);
void clean_msg__r2p__Encoder2(
  struct msg__r2p__Encoder2 *objp
);
uros_err_t recv_msg__r2p__Encoder2(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder2 *objp
);
uros_err_t send_msg__r2p__Encoder2(
  UrosTcpRosStatus *tcpstp,
  struct msg__r2p__Encoder2 *objp
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

