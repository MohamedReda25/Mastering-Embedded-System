/*
 * student.c
 *
 *  Created on: Aug 16, 2022
 *      Author: redam
 */

#include "student.h"

Student_t* FirstStudent = NULL;



id_state check_id(int id){
	Student_t* TempStudent = FirstStudent;
	while(TempStudent != NULL){
		if (TempStudent->data.id == id){
			return exists;
		}
		else{
			TempStudent = TempStudent->nextStudent;
		}
	}
	return Not_exist;
}




void Add_Student()
{
	Student_t* NewStudent = malloc(sizeof(Student_t));
	char txt[40];
	printf("Enter student id: ");
	gets(txt);
	int id = atoi(txt);
	if(check_id(id) == exists){ //check id validity
		printf("Student id is already existed..\n");
	}
	else if(check_id(id) == Not_exist)
	{
		NewStudent->data.id=atoi(txt);
		printf("Enter student name: ");
		gets(NewStudent->data.name);
		printf("Enter student height: ");
		gets(txt);
		NewStudent->data.height=atof(txt);
		if(FirstStudent == NULL){
			FirstStudent = NewStudent;
			NewStudent->nextStudent=NULL;
		}
		else{
			Student_t* TempStudent = FirstStudent;
			while(TempStudent->nextStudent != NULL){
				TempStudent = TempStudent->nextStudent;
			}
			TempStudent->nextStudent=NewStudent;
			NewStudent->nextStudent=NULL;

		}
		printf("Student data inserted Successfully----\nStudent id: %d\nStudent name: %s\nStudent height:"
				" %.2f\n-------------------------------\n",NewStudent->data.id,NewStudent->data.name,NewStudent->data.height);


	}
}





void Delete_Student()
{
	Student_t* CurrentStudent = FirstStudent;
	Student_t* PreviousStudent = NULL;

	if(FirstStudent == NULL){
		printf("Empty list\n");
		return;
	}

	char txt[40];
	printf("Enter Student id to be deleted: ");
	gets(txt);
	int id = atoi(txt);

	while(CurrentStudent){
		if(CurrentStudent->data.id == id){
			printf("Student information to be deleted:\nStudent id: %d\nStudent name: "
					"%s\nStudent height: %.2f\n",id,CurrentStudent->data.name,CurrentStudent->data.height);
			if(PreviousStudent){
				PreviousStudent->nextStudent= CurrentStudent->nextStudent;
			}
			else
			{
				FirstStudent=CurrentStudent->nextStudent;
			}
			free(CurrentStudent);
			printf("Deletion done Successfully\n");
			return;
		}
		else{
			PreviousStudent = CurrentStudent;
			CurrentStudent = CurrentStudent->nextStudent;
		}

	}
	printf("Not existed id\n");


}





void Show_all_list()
{
	Student_t* TempStudent = FirstStudent;
	uint32 count =1;
	if(FirstStudent == NULL){
		printf("Empty list\n");
		return;
	}

	while (TempStudent){
		printf("Student No.%d:\nStudent id: %d\nStudent name: %s\nStudent height:"
				" %.2f\n---------------------------"
				"\n",count,TempStudent->data.id,TempStudent->data.name,TempStudent->data.height);
		TempStudent = TempStudent->nextStudent;
		count++;
	}
}


void Delete_All()
{
	Student_t* CurrentStudent = FirstStudent;
	Student_t* TempStudent;
	if(CurrentStudent == NULL){
		printf("Empty list");
		return;
	}
	while(CurrentStudent){
		TempStudent = CurrentStudent;
		CurrentStudent = CurrentStudent->nextStudent;
		free(TempStudent);

	}
	FirstStudent = NULL;
	printf("List is deleted\n");



}



void List_lenght(){
	Student_t* TempStudent = FirstStudent;
	uint32 count = 0;
	if (TempStudent == NULL){
		printf("List is empty\n");
		return;
	}
	while(TempStudent != NULL){
		TempStudent = TempStudent->nextStudent;
		count++;

	}
	printf("List length = %d\n",count);
}



void Reverse_list(){
	Student_t* PreviousStudent = NULL;
	Student_t* CurrentStudent=FirstStudent;
	Student_t* ForwardStudent = FirstStudent;

	while(CurrentStudent != NULL){
		ForwardStudent = CurrentStudent->nextStudent;
		CurrentStudent->nextStudent = PreviousStudent;
		PreviousStudent = CurrentStudent;
		CurrentStudent = ForwardStudent;
	}
	FirstStudent = PreviousStudent;
	printf("Reverse is done successfully\n");
}

