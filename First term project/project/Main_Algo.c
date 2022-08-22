/*
 * Main_Algo.c
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */

#include "Main_Algo.h"
#include "State.h"


int Pressure_value =0;
int threshold = 20;


void Set_Pressure_val()
{
Pressure_value = getPressureVal();
}


STATE_define(Pressure_Detection)
{
	Set_Pressure_val();
	if(Pressure_value <= 20){
		Set_Pressure_val();
		Algo_STATE = STATE(Pressure_Detection);
	}
	else
		{
			High_pressure_detect();
			Set_Pressure_val();
			Algo_STATE = STATE(Pressure_Detection);
		}



}

