/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "string.h"



int main(int argc, char *argv[]) {

char str[30];
printf("Input a string: ");
fflush(stdout); fflush(stdin);
gets(str);
char* ptr =str+strlen(str)-1;
printf("Reverse of the string is: ");

for(; ptr>=str; ptr--){
	printf("%c",*ptr);
}


}
