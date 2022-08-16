/*
 * US.h
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */

#ifndef US_H_
#define US_H_
#include "state.h"



enum{
	US_busy
}US_state_id;


void US_init();

void (*US_State)();

State_define(US_busy);





#endif /* US_H_ */
