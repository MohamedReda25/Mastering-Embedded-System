/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: redam
 */


#include "stdio.h"
void main(){
	int num=0,fact=1;
	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);
	if(num ==0){
		printf("Factorial = %d",1);
	}
	else if(num<0){
		printf("Error!!! Factorial of negative number doesn't exist");
	}
	else{

		for(int i=2; i<=num; i++ ){
			fact=fact*i;
		}
		printf("Factorial = %d",fact);
		return;
	}
}
