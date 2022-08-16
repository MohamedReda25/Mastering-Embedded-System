/*
 * US.c
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */

#include "US.h"
#include "state.h"

void (*US_State)();
int US_distance = 0;

void US_init()
{
	printf("US init \n");

}



State_define(US_busy)
{

	// state name
	US_state_id = US_busy;

	// state action
	US_distance = US_Get_distance_random(45 , 55 ,  1);
	printf("US_busy_state: distance =%d  \n",US_distance);

	US_Set_distance(US_distance);
	US_State = STATE(US_busy);



}







int US_Get_distance_random(int l , int r , int count){
	int i;
	for(i=0; i<count; i++){
		int rand_num = (rand() % (r - l + 1)) + 45;
		return rand_num;
	}
}
