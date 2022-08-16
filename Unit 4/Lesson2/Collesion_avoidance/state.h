/*
 * state.h
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"
#define State_define(_stat_fun_) void ST_##_stat_fun_()
#define STATE(_stat_fun_) ST_##_stat_fun_



void US_Set_distance(int d);
void DC_Motor(int s);




#endif /* STATE_H_ */
