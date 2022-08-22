/*
 * State.h
 *
 *  Created on: Aug 22, 2022
 *      Author: redam
 */

#ifndef STATE_H_
#define STATE_H_
#include "driver.h"
#define STATE_define(_statefunc_)  void ST_##_statefunc_()
#define STATE(_statefunc_)  ST_##_statefunc_



void Set_Pressure_val();
void High_pressure_detect();
void Stop_alarm();
void Start_alarm();



#endif /* STATE_H_ */
