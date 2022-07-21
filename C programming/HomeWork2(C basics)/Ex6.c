/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: redam
 */


#include "stdio.h"
void main(){
	int num,sum=0;
	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);

	for(int i=1; i<=num; i++ ){
		sum=sum+i;
	}
	printf("Sum = %d",sum);
	return;
}
