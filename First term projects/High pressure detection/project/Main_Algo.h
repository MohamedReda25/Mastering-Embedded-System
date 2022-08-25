/*
 * Main_Algo.h
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */

#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_
#include "State.h"

enum{
	Pressure_Detection
}MainAlgo_state_id;


void (* Algo_STATE) ();

STATE_define(Pressure_Detection);






#endif /* MAIN_ALGO_H_ */
