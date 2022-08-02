/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "string.h"



int main(int argc, char *argv[]) {

	int arr[15];
	int n;
	printf("Input the number of elements to store in the array (max 15): ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	printf("Input %d numbers of elements in the array:\n",n);
	int i=0;
	for(; i<n; i++){
		printf("element - %d : ",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d",&arr[i]);

	}
	int* ptr = arr+n-1;
	printf("The elements of array in reverse order are :\n");
	i=0;
	for(; ptr>=arr; ptr--,i++){
		printf("element - %d : %d",i+1,*ptr);
		printf("\n");



	}
}
