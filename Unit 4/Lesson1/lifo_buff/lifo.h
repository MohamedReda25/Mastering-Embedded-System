/*
 * lifo.h
 *
 *  Created on: Aug 12, 2022
 *      Author: redam
 */
#include "Platform_Types.h"

#ifndef LIFO_H_
#define LIFO_H_


//Unsigned INT LIFO BUFFER
typedef struct{
	uint32 length;
	uint32* base;
	uint32* head;
	uint32 count;

}LIFO_BUFF_t;
 typedef enum{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL

}LIFO_STATUS;



//APIs


LIFO_STATUS LIFO_INIT(LIFO_BUFF_t* lifo,uint32* buff,uint32 length);//Initialization

LIFO_STATUS LIFO_PUSH(LIFO_BUFF_t* lifo,uint32 item);//Push to LIFO

LIFO_STATUS LIFO_POP(LIFO_BUFF_t* lifo,uint32* item);// Pop from LIFO








#endif /* LIFO_H_ */
