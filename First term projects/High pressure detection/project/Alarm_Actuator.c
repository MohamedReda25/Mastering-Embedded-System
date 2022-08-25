/*
 * Alarm_Actuator.c
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */
#include "Alarm_Actuator.h"
#include "State.h"
extern int Alarm_Flag;

void Act_init(){
	GPIO_INITIALIZATION();
}

void Start_alarm (){
	Set_Alarm_actuator(0);
}


void Stop_alarm (){
	Set_Alarm_actuator(1);
}



STATE_define(Waiting){

	if(Alarm_Flag == 0){
		Stop_alarm();
	}
	if (Alarm_Flag == 1)
	{
		Start_alarm();
	}

}



STATE_define(Alarm_OFF){

	Act_STATE = STATE(Waiting);

}

STATE_define(Alarm_ON){

	Act_STATE = STATE(Waiting);
}
