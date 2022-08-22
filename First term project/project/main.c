/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */


#include "State.h"
#include "driver.h"
#include "Alarm_Actuator.h"
#include "Alarm_Manager.h"
#include "Main_Algo.h"
#include "PS.h"

void setup() {

	PS_init();
	Act_init();
	Alarm_STATE =  STATE(Stop_Alarm);
	PS_State = STATE(PS_reading);
	Algo_STATE = STATE(Pressure_Detection);
	Stop_alarm();
	Act_STATE = STATE(Waiting);
}

int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		PS_State();
		Algo_STATE();
		Alarm_STATE();
		Act_STATE();
		Delay(10000);
	}
}
