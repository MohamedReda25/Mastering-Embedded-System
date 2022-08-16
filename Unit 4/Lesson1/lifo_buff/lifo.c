/*
 * lifo.c
 *
 *  Created on: Aug 12, 2022
 *      Author: redam
 */

#include "lifo.h"

LIFO_STATUS LIFO_INIT(LIFO_BUFF_t* lifo,uint32* buff,uint32 length)
{
	if(buff == NULL){
		return LIFO_NULL;
	}
	lifo->base = buff;
	lifo->head =buff;
	lifo->length=length;
	lifo->count=0;
	return LIFO_NO_ERROR;
}
LIFO_STATUS LIFO_PUSH(LIFO_BUFF_t* lifo,uint32 item)
{
	if(!lifo->base || !lifo->head){
		return LIFO_NULL;
	}
	if(lifo->count == lifo->length){
		return LIFO_FULL;
	}
	*(lifo->head) = item;
	lifo->head++;
	lifo->count++;
	return LIFO_NO_ERROR;

}
LIFO_STATUS LIFO_POP(LIFO_BUFF_t* lifo,uint32* item)
{
	if(!lifo->base || !lifo->head){
		return LIFO_NULL;
	}
	if(lifo->count==0){
		return LIFO_EMPTY;
	}
    lifo->head--;
    *item = *(lifo->head);
    lifo->count--;
    return LIFO_NO_ERROR;



}
