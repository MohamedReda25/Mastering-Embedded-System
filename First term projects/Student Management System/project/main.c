/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "FIFO.h"


int main(void)
{
	int option;
	FIFO_INIT(&fifo, students, 50);
	printf("Welcome to the Student Management System\n");
	while(1){

		printf("Choose the task you want to perform\n1. Add the student details manually\n"
				"2. Add the student details from Text file\n3. Find the student details by roll number\n"
				"4. Find the student details by first name\n5. Find the student details by course_ID\n"
				"6. Find the total number of the students\n7. Delete the student details by roll number\n"
				"8. Update the student details by roll number\n9. Show all information\n"
				"10. To exit\n")
		printf("Enter your choice to perform: ");

		scanf("%d",&option);
		if(option == 1){
			add_student_manually(&fifo);
		}
		else if(option == 2){
			add_student_file(&fifo);
		}
		else if(option == 3){
			find_r1(&fifo);
		}
		else if(option == 4){
			find_fn(&fifo);
		}
		else if(option == 5){
			find_c(&fifo);
		}
		else if(option == 6){
			total_number(&fifo);
		}
		else if(option == 7){
			delete_student(&fifo);
		}
		else if(option == 8){
			update_student(&fifo);
		}
		else if(option == 9){
			show_all(&fifo);
		}
		else if(option == 10){
			break;
		}


	}

}
