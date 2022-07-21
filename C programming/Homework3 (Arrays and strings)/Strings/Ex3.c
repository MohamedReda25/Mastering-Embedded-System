/*
 * main.c
 *
 *  Created on: Jul 21, 2022
 *      Author: redam
 */
#include "stdio.h"
#include "string.h"
void main(){


char st[100];
char rev[100];
	int i;
	int j=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(st);

	for(i= strlen(st)-1; i>=0; i--){
     rev[j]=st[i];
     j++;
	}
	rev[j]=0;
	printf("Reverse string is: %s",&rev);

}
