/*
 * PS.h
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */

#ifndef PS_H_
#define PS_H_
#include "State.h"


enum{
	PS_waiting,
	PS_reading
}PS_state_id;

void PS_init();

void (*PS_State)();

STATE_define(PS_reading);

STATE_define(PS_waiting);








#endif /* PS_H_ */
