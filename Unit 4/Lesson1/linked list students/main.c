/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: redam
 */


#include "student.h"





void main(){
	volatile int i;
	int option;
	while(1){
		printf("Select option:\n1-Add student\n2-Delete Student\n3-Show All Students\n4-"
				"Delete all students\n5-Reverse the list\n6-Show List length\n");
		scanf("%d", &option);
		if(option == 1){
			Add_Student();
		}

		else if(option == 2)
		{
			Delete_Student();
		}
		else if(option == 3){
			Show_all_list();
		}
		else if(option == 4){
			Delete_All();
		}
		else if(option == 5){
			 Reverse_list();
		}
		else if(option == 6){
			List_lenght();
		}


	}
}
