#include "fifo.h"



FIFO_STATUS FIFO_INIT(FIFO_BUFF_t* fifo, element_type* buff, uint8 length)
{
	if(buff == NULL){
		return FIFO_NULL;
	}
	fifo->base=buff;
	fifo->head=buff;
	fifo->tail=buff;
	fifo->count=0;
	fifo->length=length;
	return FIFO_NO_ERROR;
}
FIFO_STATUS FIFO_IS_FULL(FIFO_BUFF_t* fifo)
{
	if(fifo->count == fifo->length){
		return FIFO_FULL;
	}
	return FIFO_NO_ERROR;
}

FIFO_STATUS FIFO_IS_EMPTY(FIFO_BUFF_t* fifo)
{
	if(fifo->count == 0){
		return FIFO_EMPTY;
	}
	return FIFO_NO_ERROR;
}
FIFO_STATUS FIFO_ENQUQU(FIFO_BUFF_t* fifo, element_type item)
{
	if(!fifo->head || !fifo->base || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_FULL;
	*(fifo->head)=item;
	fifo->count++;
	if(fifo->head == (fifo->base+(fifo->length*sizeof(element_type)))){
		fifo->head= fifo->base;
	}
	else{
		fifo->head++;
	}
	return FIFO_NO_ERROR;


}
FIFO_STATUS FIFO_DEQUQU(FIFO_BUFF_t* fifo, element_type* item)
{
	if(!fifo->head || !fifo->base || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == 0)
		return FIFO_EMPTY;
	*item = *(fifo->tail);
	fifo->count--;
	if(fifo->tail == (fifo->base+(fifo->length*sizeof(element_type)))){
		fifo->tail= fifo->base;
	}
	else{
		fifo->tail++;
	}
	return FIFO_NO_ERROR;


}


void FIFO_PRINT(FIFO_BUFF_t* fifo)
{
	if(!fifo->head || !fifo->base || !fifo->tail)
		printf("FIFO IS NULL");
	if(fifo->count == 0){
		printf("FIFO IS EMPTY");}

	element_type* temp = fifo->tail;
	while(temp != fifo->head){
		printf("%x\n",*(temp));
		if(temp == (fifo->base+(fifo->length*sizeof(element_type)))){
			temp= fifo->base;
		}
		else{
			temp++;
		}

	}




}


