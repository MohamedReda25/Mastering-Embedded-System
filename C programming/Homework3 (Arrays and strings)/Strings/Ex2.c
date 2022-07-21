/*
 * main.c
 *
 *  Created on: Jul 21, 2022
 *      Author: redam
 */


#include "stdio.h"

void main(){
	char st[100];
	int i=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(st);
	while(st[i]!=0){
     i++;
	}
	printf("Length of string: %d",i);



}
