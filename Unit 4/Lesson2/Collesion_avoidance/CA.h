/*
 * CA.h
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"



enum{
	CA_waiting,
	CA_driving
}CA_state_id;


void (*CA_State)();

State_define(CA_waiting);
State_define(CA_driving);

void US_Set_distance(int d);


#endif /* CA_H_ */
