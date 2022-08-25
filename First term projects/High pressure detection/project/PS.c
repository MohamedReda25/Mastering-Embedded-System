/*
 * PS.c
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */
#include "PS.h"
#include "driver.h"
#include "State.h"

int Pressure_val = 0;
int s_timer =0;


void PS_init()
{
	GPIO_INITIALIZATION();

}



STATE_define(PS_reading)
{
	PS_state_id = PS_reading;
	Pressure_val = getPressureVal();
	s_timer =100;
	PS_State = STATE(PS_waiting);

}

STATE_define(PS_waiting)
{
	while(s_timer)
	{
		s_timer--;
	};

		s_timer = 0;
  PS_State = STATE(PS_reading);


}





