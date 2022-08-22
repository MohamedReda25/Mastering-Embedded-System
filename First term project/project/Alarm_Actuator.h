/*
 * Alarm_Actuator.h
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_
#include "State.h"


void Act_init();



void (* Act_STATE) ();

STATE_define(Waiting);
STATE_define(Alarm_OFF);
STATE_define(Alarm_ON);


#endif /* ALARM_ACTUATOR_H_ */
