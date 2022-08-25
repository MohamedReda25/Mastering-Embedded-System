/*
 * Alarm_Manager.h
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */

#ifndef ALARM_MANAGER_H_
#define ALARM_MANAGER_H_
#include "State.h"

enum {
	Stop_Alarm,
	Start_Alarm,
	Alarm_Waiting,
}Alarm_state_id;

void (* Alarm_STATE) ();

STATE_define(Stop_Alarm);
STATE_define(Start_Alarm);
STATE_define(Alarm_Waiting);





#endif /* ALARM_MANAGER_H_ */
