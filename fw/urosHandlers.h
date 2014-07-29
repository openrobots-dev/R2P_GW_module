/**
 * @file    urosHandlers.h
 * @author  TODO
 *
 * @brief   TCPROS topic and service handlers.
 */

#ifndef _UROSHANDLERS_H_
#define _UROSHANDLERS_H_

/*===========================================================================*/
/* HEADER FILES                                                              */
/*===========================================================================*/

#include "urosMsgTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================*/
/* PUBLISHED TOPIC PROTOTYPES                                                */
/*===========================================================================*/

/*~~~ PUBLISHED TOPIC: /r2p/odometry_ackermann ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__r2p__odometry_ackermann(UrosTcpRosStatus *tcpstp);

/*~~~ PUBLISHED TOPIC: /r2p/odometry_differential ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__r2p__odometry_differential(UrosTcpRosStatus *tcpstp);

/*~~~ PUBLISHED TOPIC: /r2p/steer_encoder ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__r2p__steer_encoder(UrosTcpRosStatus *tcpstp);

/*~~~ PUBLISHED TOPIC: /r2p/velocity ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__r2p__velocity(UrosTcpRosStatus *tcpstp);

/*~~~ PUBLISHED TOPIC: /r2p/wheel_encoders ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__r2p__wheel_encoders(UrosTcpRosStatus *tcpstp);

/*===========================================================================*/
/* SUBSCRIBED TOPIC PROTOTYPES                                               */
/*===========================================================================*/

/*~~~ SUBSCRIBED TOPIC: /cmd_vel ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t sub_tpc__cmd_vel(UrosTcpRosStatus *tcpstp);

/*===========================================================================*/
/* PUBLISHED SERVICE PROTOTYPES                                              */
/*===========================================================================*/

/* There are no published services.*/

/*===========================================================================*/
/* CALLED SERVICE PROTOTYPES                                                 */
/*===========================================================================*/

/* There are no called services.*/

/*===========================================================================*/
/* GLOBAL PROTOTYPES                                                         */
/*===========================================================================*/

void urosHandlersPublishTopics(void);
void urosHandlersUnpublishTopics(void);

void urosHandlersSubscribeTopics(void);
void urosHandlersUnsubscribeTopics(void);

void urosHandlersPublishServices(void);
void urosHandlersUnpublishServices(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _UROSHANDLERS_H_ */

