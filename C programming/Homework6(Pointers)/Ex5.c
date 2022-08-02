/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "string.h"

struct Semployee{
	char name[30];
	int id;
};

int main(int argc, char *argv[]) {
	struct Semployee employees[3]={{"Mohamed",1000},{"Ahmed", 1001},{"Ali",1002}};
	struct Semployee *ptr;
	ptr=&employees;
	for(int i=0; i<3; i++){
		printf("Employee name: %s\n",ptr->name);
		printf("Employee Id: %d\n",ptr->id);
		printf("-------------------------------\n");
		ptr++;

	}




}
