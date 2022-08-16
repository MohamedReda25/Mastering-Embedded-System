/*
 * fifo.h
 *
 *  Created on: Aug 13, 2022
 *      Author: redam
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "Platform_Types.h"
#include "stdio.h"


#define element_type uint8
#define size 5
element_type buff[size];

typedef struct{
	uint8 count;
	uint8 length;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_BUFF_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL

}FIFO_STATUS;

FIFO_STATUS FIFO_INIT(FIFO_BUFF_t* fifo, element_type* buff, uint8 length);
FIFO_STATUS FIFO_ENQUQU(FIFO_BUFF_t* fifo, element_type item);
FIFO_STATUS FIFO_DEQUQU(FIFO_BUFF_t* fifo, element_type* item);
FIFO_STATUS FIFO_IS_FULL(FIFO_BUFF_t* fifo);
FIFO_STATUS FIFO_IS_EMPTY(FIFO_BUFF_t* fifo);
void FIFO_PRINT(FIFO_BUFF_t* fifo);






#endif /* FIFO_H_ */
