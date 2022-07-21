/*
 * main.c
 *
 *  Created on: Jul 21, 2022
 *      Author: redam
 */


#include "stdio.h"

void main(){
	char st[100];
	char c;
	int i=0;
	int counter=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(st);
	fflush(stdin); fflush(stdout);
	printf("Enter a character to find: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &c);
	fflush(stdin); fflush(stdout);
	while(st[i] !=0){
       if(st[i]== c){
    	   counter++;
       }
       i++;
	}
	printf("Frequency of %c = %d",c,counter);





}
