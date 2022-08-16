/*
 * DC.c
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */

#include "DC.h"
#include "state.h"

void (*DC_State)();
int DC_speed =0;

void DC_init()
{
	// init DC Motor
	printf("DC Motor init \n");
}

void DC_Motor(int s)
{
	DC_speed =s;
	DC_State = STATE(DC_busy);
	printf("CA----------speed=%d--------> DC\n",DC_speed);

}


State_define(DC_idle)
{

	// state name
	DC_state_id = DC_idle;

	// state action
	// Call PWM to make speed = DC_speed
	DC_State = STATE(DC_idle);
	printf("DC_idle_state: speed=%d\n",DC_speed);



}

State_define(DC_busy)
{
	// state name
		DC_state_id = DC_busy;

		// state action
		// Call PWM to make speed = DC_speed

		DC_State=STATE(DC_idle);
		printf("DC_busy_state: speed=%d\n",DC_speed);






}

