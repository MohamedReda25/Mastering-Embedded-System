/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: redam
 */
#include "stdio.h"

void main(){
	float x,y,z,temp;
	printf("Enter three numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f %f",&x , &y , &z);
	fflush(stdin);
	fflush(stdout);
	if(x>y){
		temp =x;
	}
	else{
		temp = y;
	}
	if(temp>z){
		printf("Largest number is %f",temp);
	}
	else{
		printf("Largest number is %f",z);
	}


}
