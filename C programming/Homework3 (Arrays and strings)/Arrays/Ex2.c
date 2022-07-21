/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: redam
 */


#include "stdio.h"
#include "string.h"

void main(){

	float data[100];
	int n;
	float sum=0;
	float average;
	printf("Enter the number of data: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		printf("%d. Enter number: ",i+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&data[i]);
	}
	for(int i=0; i<n; i++){
		sum = sum+data[i];
	}
	average = sum/n;
	printf("Average = %.2f",average);

}
