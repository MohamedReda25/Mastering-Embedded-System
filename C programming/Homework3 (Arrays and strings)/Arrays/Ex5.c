/*
 * main.c
 *
 *  Created on: Jul 21, 2022
 *      Author: redam
 */


#include "stdio.h"

void main(){
	int elements[100];
	int n;
	int j;
	int number;
	int flag=0;
	printf("Enter number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("Enter the elements:\n");
	fflush(stdin); fflush(stdout);
	for(int i=0; i<n; i++){
		scanf("%d",&elements[i]);
	}
	printf("Enter the number to be searched: ");
	fflush(stdin); fflush(stdout);
		scanf("%d",&number);

		for(j=0; j<n; j++){
			if(elements[j]== number){
             flag=1;
             break;
			}
		}
     if(flag ==1){
       printf("Number found at the location = %d",j+1);
     }





}
