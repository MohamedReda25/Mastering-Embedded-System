#include "Alarm_Manager.h"
#include "State.h"

int alarm_timer =0;



int Alarm_Flag=0;

void High_pressure_detect(){

	Alarm_STATE = STATE(Start_Alarm);
}


STATE_define(Stop_Alarm)
{
	Alarm_Flag=0;
	Stop_alarm();
	STATE(Pressure_Detection)();

}


STATE_define(Start_Alarm)
{
	Alarm_Flag = 1;
	Start_alarm(); // Actuator fun
	alarm_timer = 60;
	Alarm_STATE = STATE(Alarm_Waiting);
}

STATE_define(Alarm_Waiting)
{

	while(alarm_timer)
	{
		alarm_timer--;
	};

	alarm_timer = 0;
	Stop_alarm(); // Actuator fun
	Alarm_STATE = STATE(Stop_Alarm);
}


