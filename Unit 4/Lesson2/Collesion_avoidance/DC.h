/*
 * CA.h
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"



enum{
	DC_idle,
	DC_busy
}DC_state_id;


void DC_init();
void (*DC_State)();

State_define(DC_idle);
State_define(DC_busy);





#endif /* CA_H_ */
