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

/*~~~ MESSAGE: std_msgs/String ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>std_msgs/String</tt> message descriptor.
 * @details MD5 sum: <tt>992ce8a1687cec8c8bd883ec73ca41d1</tt>.
 */
struct msg__std_msgs__String {
  UrosString    data;
};

/*~~~ MESSAGE: heartbeat/Heartbeat ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>heartbeat/Heartbeat</tt> message descriptor.
 * @details MD5 sum: <tt>cd38a069af211501ce9a41a4b1793b53</tt>.
 */
struct msg__heartbeat__Heartbeat {
  struct msg__std_msgs__String  node_name;
};

/*~~~ MESSAGE: roamros_msgs/SingleTrackAckermannOdometry ~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>roamros_msgs/SingleTrackAckermannOdometry</tt> message descriptor.
 * @details MD5 sum: <tt>64a28906316460b1514f030ee73f69e5</tt>.
 */
struct msg__roamros_msgs__SingleTrackAckermannOdometry {
  double    speed;
  double    steer;
};

/*~~~ MESSAGE: quadrivio_msgs/SetPoint ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>quadrivio_msgs/SetPoint</tt> message descriptor.
 * @details MD5 sum: <tt>8bd90c78c2a3e2624e4cb35d1fc6370f</tt>.
 */
struct msg__quadrivio_msgs__SetPoint {
  double    speed;
  double    steer;
  double    brake;
  uint8_t   source;
};

/*~~~ MESSAGE: heartbeat/State ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/**
 * @brief   TCPROS <tt>heartbeat/State</tt> message descriptor.
 * @details MD5 sum: <tt>8894b727e9ea5dc912a2ffdad059695b</tt>.
 */
struct msg__heartbeat__State {
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

/*~~~ MESSAGE: quadrivio_msgs/SetPoint ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>quadrivio_msgs/SetPoint</tt> */
/** @{ */

#define msg__quadrivio_msgs__SetPoint__AUTO         ((uint8_t)0)
#define msg__quadrivio_msgs__SetPoint__JOYPAD       ((uint8_t)1)

/** @} */

/*~~~ MESSAGE: heartbeat/State ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** @name Message <tt>heartbeat/State</tt> */
/** @{ */

#define msg__heartbeat__State__HALT         ((uint8_t)0)
#define msg__heartbeat__State__MANUAL       ((uint8_t)1)
#define msg__heartbeat__State__SAFE         ((uint8_t)2)
#define msg__heartbeat__State__ASSISTED     ((uint8_t)3)
#define msg__heartbeat__State__AUTO         ((uint8_t)4)

/** @} */

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

/*~~~ MESSAGE: std_msgs/String ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__std_msgs__String(
  struct msg__std_msgs__String *objp
);
void init_msg__std_msgs__String(
  struct msg__std_msgs__String *objp
);
void clean_msg__std_msgs__String(
  struct msg__std_msgs__String *objp
);
uros_err_t recv_msg__std_msgs__String(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__String *objp
);
uros_err_t send_msg__std_msgs__String(
  UrosTcpRosStatus *tcpstp,
  struct msg__std_msgs__String *objp
);

/*~~~ MESSAGE: heartbeat/Heartbeat ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__heartbeat__Heartbeat(
  struct msg__heartbeat__Heartbeat *objp
);
void init_msg__heartbeat__Heartbeat(
  struct msg__heartbeat__Heartbeat *objp
);
void clean_msg__heartbeat__Heartbeat(
  struct msg__heartbeat__Heartbeat *objp
);
uros_err_t recv_msg__heartbeat__Heartbeat(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__Heartbeat *objp
);
uros_err_t send_msg__heartbeat__Heartbeat(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__Heartbeat *objp
);

/*~~~ MESSAGE: roamros_msgs/SingleTrackAckermannOdometry ~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__roamros_msgs__SingleTrackAckermannOdometry(
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
);
void init_msg__roamros_msgs__SingleTrackAckermannOdometry(
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
);
void clean_msg__roamros_msgs__SingleTrackAckermannOdometry(
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
);
uros_err_t recv_msg__roamros_msgs__SingleTrackAckermannOdometry(
  UrosTcpRosStatus *tcpstp,
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
);
uros_err_t send_msg__roamros_msgs__SingleTrackAckermannOdometry(
  UrosTcpRosStatus *tcpstp,
  struct msg__roamros_msgs__SingleTrackAckermannOdometry *objp
);

/*~~~ MESSAGE: quadrivio_msgs/SetPoint ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__quadrivio_msgs__SetPoint(
  struct msg__quadrivio_msgs__SetPoint *objp
);
void init_msg__quadrivio_msgs__SetPoint(
  struct msg__quadrivio_msgs__SetPoint *objp
);
void clean_msg__quadrivio_msgs__SetPoint(
  struct msg__quadrivio_msgs__SetPoint *objp
);
uros_err_t recv_msg__quadrivio_msgs__SetPoint(
  UrosTcpRosStatus *tcpstp,
  struct msg__quadrivio_msgs__SetPoint *objp
);
uros_err_t send_msg__quadrivio_msgs__SetPoint(
  UrosTcpRosStatus *tcpstp,
  struct msg__quadrivio_msgs__SetPoint *objp
);

/*~~~ MESSAGE: heartbeat/State ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t length_msg__heartbeat__State(
  struct msg__heartbeat__State *objp
);
void init_msg__heartbeat__State(
  struct msg__heartbeat__State *objp
);
void clean_msg__heartbeat__State(
  struct msg__heartbeat__State *objp
);
uros_err_t recv_msg__heartbeat__State(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__State *objp
);
uros_err_t send_msg__heartbeat__State(
  UrosTcpRosStatus *tcpstp,
  struct msg__heartbeat__State *objp
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

