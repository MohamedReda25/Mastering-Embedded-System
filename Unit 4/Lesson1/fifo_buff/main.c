/*
 * main.c
 *
 *  Created on: Aug 13, 2022
 *      Author: redam
 */

#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"





int main(){
	element_type temp;
	FIFO_BUFF_t fifo;
	FIFO_INIT(&fifo,buff,5);
	for(element_type i=0; i<7; i++){
		printf("ENQUQU(%x):\n",i);
		if(FIFO_ENQUQU(&fifo,i)== FIFO_NO_ERROR ){
			printf("ENQUQU of (%x) is done---------\n",i);
		}
		else{
			printf("ENQUQU of (%x) is failed---------\n",i);
		}
	}
	printf("\n----------------------------------------\n");

	if(FIFO_DEQUQU(&fifo,&temp)==FIFO_NO_ERROR){
		printf("DEQUQU of (%x) is done---------\n",temp);
	}
	if(FIFO_DEQUQU(&fifo,&temp)==FIFO_NO_ERROR){
		printf("DEQUQU of (%x) is done---------\n",temp);
	}
	printf("\n----------------------------------------\n");
	FIFO_PRINT(&fifo);


}

