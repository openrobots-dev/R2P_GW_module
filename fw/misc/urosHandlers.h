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

/*~~~ PUBLISHED TOPIC: /tiltone/led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t pub_tpc__tiltone__led(UrosTcpRosStatus *tcpstp);

/*===========================================================================*/
/* SUBSCRIBED TOPIC PROTOTYPES                                               */
/*===========================================================================*/

/*~~~ SUBSCRIBED TOPIC: /tiltone/led ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

uros_err_t sub_tpc__tiltone__led(UrosTcpRosStatus *tcpstp);

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

