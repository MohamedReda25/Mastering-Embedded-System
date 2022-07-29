/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "string.h"


struct Sstudent{
	char name[20];
	int roll_num;
	float mark;

};





int main(int argc, char *argv[]) {
	struct Sstudent students[30];

	int count=0;
	char x='n';
	printf("Enter information of students: \n");
	fflush(stdout); fflush(stdin);
	do{

		printf("Enter name: ");
		fflush(stdout); fflush(stdin);
		gets(students[count].name);
		printf("Enter roll number: ");
		fflush(stdout); fflush(stdin);
		scanf("%d",&students[count].roll_num);
		printf("Enter marks: ");
		fflush(stdout); fflush(stdin);
		scanf("%f",&students[count].mark);
		count++;
		if(count ==30){
			break;
		}

		printf("Do you want another student??  please press 'y' ");
		fflush(stdout); fflush(stdin);
		scanf("%c",&x);
	}while( x== 'y');




	printf("Displaying Information\n");
	fflush(stdout); fflush(stdin);
	for(int i=0; i<count; i++){
		printf("name: %s\n",students[i].name);
		printf("Roll: %d\n",students[i].roll_num);
		printf("name: %f\n",students[i].mark);
		printf("\n----------------------------------\n");

	}








}

