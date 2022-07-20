/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: redam
 */
#include "stdio.h"

void main(){
	float num;
	printf("Enter a number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&num);
	if(num>0){
		printf("%f is a positive.",num);
	}
	else if(num<0){
		printf("%f is a negative.",num);
	}
	else if(num ==0){
			printf("You entered zero.");
		}
	else{
		printf("You entered zero.");
	}


}
