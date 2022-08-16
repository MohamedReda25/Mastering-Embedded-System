/*
 * CA.c
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */

#include "CA.h"
#include "state.h"

void (*CA_State)();
int CA_speed =0;
int CA_distance = 0;
int CA_threshold = 50;

void US_Set_distance(int d)
{

	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_State = STATE(CA_waiting)) : (CA_State = STATE(CA_driving));
	printf("US----------distance=%d--------> CA \n",CA_distance);



}



State_define(CA_waiting)
{

	// state name
	CA_state_id = CA_waiting;
	printf("CA_waiting_state: distance =%d   speed=%d\n",CA_distance,CA_speed);

	// state action
	CA_speed =0;  // DC Motor speed
	DC_Motor(CA_speed);





}

State_define(CA_driving)
{
	// state name
	CA_state_id = CA_driving;
	printf("CA_driving_state: distance =%d  speed=%d \n",CA_distance,CA_speed);

	// state action
	CA_speed =30;
	// DC Motor speed
	DC_Motor(CA_speed);

	// Event check






}





