/*
 * FIFO.c
 *
 *  Created on: Aug 23, 2022
 *      Author: redam
 */
#include "stdio.h"
#include "FIFO.h"
#include "string.h"



int roll;
int no_c;


void FIFO_INIT(FIFO_t* fifo, Student_t* buff, int length)
{
	if(buff){
		fifo->base = buff;
		fifo->head = buff;
		fifo->tail = buff;
		fifo->length = length;
		fifo->count=0;
	}
}
void update_courses(FIFO_t* fifo)
{
	int no_c;
	Student_t* temp = fifo->tail;
	printf("Enter the new number of courses: ");
	scanf("%d",&no_c);
	while(temp != fifo->head){
		if(temp->roll == roll){
			temp->no_courses=no_c;
			for(int i=0; i<no_c; i++){
				printf("Course %d ID: ",i+1);
				scanf("%d",&temp->cid[i]);

			}
			printf("[INFO] Updated Successfully\n");
			return;
		}
		temp_advance;
	}


}
void update_GPA(FIFO_t* fifo)
{
	float new_GPA;
	Student_t* temp = fifo->tail;
	printf("Enter the new GPA: ");
	scanf("%f",&new_GPA);
	while(temp != fifo->head){
		if(temp->roll == roll){
			temp->GPA = new_GPA;
			printf("[INFO] Updated Successfully\n");
			return;
		}
		temp_advance;
	}
	return;

}
void update_roll(FIFO_t* fifo)
{
	int new_roll;
	Student_t* temp = fifo->tail;
	printf("Enter the new roll number: ");
	scanf("%d",&new_roll);
	if(check_roll(fifo,new_roll) == exist ){
		printf("The roll is already used!.. Please try another roll number\n");
		return;
	}
	while(temp != fifo->head){
		if(temp->roll == roll){
			temp->roll = new_roll;
			printf("[INFO] Updated Successfully\n");
			return;
		}
		temp_advance;
	}
	return;

}

void update_lname(FIFO_t* fifo)
{
	char lname[10];
	Student_t* temp = fifo->tail;
	printf("Enter the new last name: ");
	gets(lname);
	while(temp != fifo->head){
		if(temp->roll == roll){
			strcpy(temp->lastName,lname);
			printf("[INFO] Updated Successfully\n");
			return;
		}
		temp_advance;

	}
	return;

}
void update_fname(FIFO_t* fifo){
	char fname[10];
	Student_t* temp = fifo->tail;
	printf("Enter the new first name: ");
	gets(fname);
	while(temp != fifo->head){
		if(temp->roll == roll){
			strcpy(temp->firstName,fname);
			printf("[INFO] Updated Successfully\n");
			return;
		}
		temp_advance;
	}
	return;
}

course_state check_course_id(FIFO_t* fifo , int c_id){
	Student_t* temp = fifo->tail;
	while(temp != fifo->head){
		for(int i=0; i<temp->no_courses; i++){
			if(temp->cid[i] == c_id){
				return exist;
			}
		}
		temp_advance;
	}
	return not_exist;
}
Queue_state check_queue_status(FIFO_t* fifo){
	if(fifo->count == 0){
		return Empty;
	}
	else if(fifo->count==fifo->length){
		return Full;
	}
	else{
		return Not_empty;
	}
}

name_state check_name(FIFO_t* fifo ,char* fname)
{
	Student_t* temp = fifo->tail;
	while(temp != fifo->head){
		if(strcmp(temp->firstName,fname) == 0){
			return exist;
		}
		else{
			temp_advance;
		}
	}
	return not_exist;

}
roll_state check_roll(FIFO_t* fifo ,int roll){
	Student_t* temp = fifo->tail;
	while(temp != fifo->head){
		if(temp->roll == roll){
			return exist;
		}
		else{
			temp_advance;
		}
	}
	return not_exist;
}





void add_student_file(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Full){
		printf("The queue is full../n");
		return;
	}
	FILE* ptr;
	ptr = fopen("students_sample_file.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	while(!feof(ptr)){
		int temp;
		int flag=1;
		fscanf(ptr, "%d",&temp);
		if(check_roll(fifo,temp) == exist){
			printf("[ERROR] Roll number %d is already used\n",temp);
			flag=0;
		}
		if(flag){
			fifo->head->roll = temp;
			fscanf(ptr, "%s",fifo->head->firstName);
			fscanf(ptr, "%s",fifo->head->lastName);
			fscanf(ptr, "%f",&fifo->head->GPA);
			for(int i=0; i<5; i++){
				fscanf(ptr, "%d",&fifo->head->cid[i]);
			}
			fifo->head->no_courses = 5;
			printf("[INFO] Roll number %d is saved successfully\n",temp);
			if(fifo->head == (fifo->base+(fifo->length*sizeof(Student_t)))){
				fifo->head= fifo->base;
			}
			else{
				fifo->head++;
			}
			fifo->count++;
		}
		else{
			char  tr_fn[10];
				char tr_ln[10] ;
				float tr_gpa;
				int tr_c[10];
			continue_;
		}

	}
	printf("-------------------------\n");

	fclose(ptr);
	return ;
}



void add_student_manually(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Full){
		printf("The queue is full../n");
		return;
	}
	printf("Add the Student Details\n-----------------------\n");
	printf("Enter roll Number: ");
	scanf("%d",&roll);
	if(check_roll(fifo,roll) == exist ){
		printf("The roll is already used!.. Please try another roll number\n");
	}
	else{

		fifo->head->roll=roll;
		printf("Enter the first name of the student: ");
		gets(fifo->head->firstName);
		printf("Enter the last name of the student: ");
		gets(fifo->head->lastName);
		printf("Enter the GPA of the student: ");
		scanf("%f",&fifo->head->GPA);
		printf("Enter the number of courses registered by the student: ");
		scanf("%d",&fifo->head->no_courses);
		for(int i=0; i<fifo->head->no_courses; i++){
			printf("Course %d id: ",i+1);
			scanf("%d",&fifo->head->cid[i]);
		}
		if(fifo->head == (fifo->base+(fifo->length*sizeof(Student_t)))){
			fifo->head= fifo->base;
		}
		else{
			fifo->head++;
		}
		fifo->count++;
		printf("[INFO] Student Details is added Successfully\n----------------------------\n");
		students_info;

		return;

	}
}

void find_r1(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Empty){
		printf("Queue is empty!..\n");
		return;
	}
	printf("Enter the roll number of the student: ");
	scanf("%d",&roll);
	if(check_roll(fifo,roll) == not_exist){
		printf("Roll number %d not found\n---------------------------\n",roll);
		return;
	}
	else{
		Student_t* temp = fifo->tail;
		while(temp != fifo->head)
		{
			if(temp->roll == roll){
				printf("The Student Details are\n");
				printf("---------------------------\n");
				printf("The first name is %s\n",temp->firstName);
				printf("The last name is %s\n",temp->lastName);
				printf("The GPA is %.2f\n",temp->GPA);
				printf("The courses that the student registered are\n");
				for(int i=0; i<temp->no_courses; i++){
					printf("The course ID is %d\n",temp->cid[i]);
				}
				printf("---------------------------\n");
				return;
			}
			else
			{
				temp_advance;
			}
		}
		return;
	}
}

void find_fn(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Empty){
		printf("Queue is empty!..\n");
		return;
	}
	char fname[10];
	printf("Enter the first name of the student: ");
	gets(fname);
	if(check_name(fifo,fname) == not_exist){
		printf("First name %s not found\n---------------------------\n",fname);
		return;
	}
	else{
		Student_t* temp = fifo->tail;
		while(temp != fifo->head)
		{
			if(strcmp(temp->firstName,fname) == 0){
				printf("The Student Details are\n");
				printf("---------------------------\n");
				printf("The first name is %s\n",temp->firstName);
				printf("The last name is %s\n",temp->lastName);
				printf("The GPA is %.2f\n",temp->GPA);
				printf("The courses that the student registered are\n");
				for(int i=0; i<temp->no_courses; i++){
					printf("The course ID is %d\n",temp->cid[i]);
				}
				printf("---------------------------\n");
			}
			temp_advance;
		}
		return;

	}

}

void find_c(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Empty){
		printf("Queue is empty!..\n");
		return;
	}
	int c_id;
	printf("Enter the course ID: ");
	scanf("%d",&c_id);
	if(check_course_id(fifo,c_id) == not_exist){
		printf("Course ID %d not found\n---------------------------\n",c_id);
		return;
	}
	int count=0;
	Student_t* temp = fifo->tail;
	while(temp != fifo->head){
		for(int i=0; i<temp->no_courses; i++){
			if(temp->cid[i] == c_id){
				printf("The student Details are\n");
				printf("---------------------------\n");
				printf("The first name is %s\n",temp->firstName);
				printf("The last name is %s\n",temp->lastName);
				printf("The GPA is %.2f\n",temp->GPA);
				printf("---------------------------\n");
				count++;

			}
		}
		temp_advance;

	}
	printf("[INFO] The total number of students enrolled : %d\n--------------------------\n",count);

}

void total_number(FIFO_t* fifo)
{
	students_info;
}

void delete_student(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Empty){
		printf("Queue is empty!..\n--------------------\n");
		return;
	}
	printf("Enter the roll number of the student to be deleted: ");
	scanf("%d",&roll);
	if(check_roll(fifo,roll) == not_exist){
		printf("This roll number %d not found\n",roll);
		return;
	}
	if(roll == fifo->tail->roll){
		fifo->tail++;
		fifo->count--;
		printf("[INFO] The roll number is removed successfully..");
		return;
	}
	Student_t* temp1 = fifo->tail;
	Student_t* temp2;
	while(temp1 != fifo->head){
		if(temp1->roll == roll){
			temp2 = temp1;
			break;
		}
		if(temp1 == (fifo->base+(fifo->length*sizeof(Student_t)))){
			temp1 = fifo->base;
		}
		else{
			temp1++;
		}

	}
	Student_t* temp3;
	if(temp2 == (fifo->base+(fifo->length*sizeof(Student_t)))){
		temp3 = fifo->base;
	}
	else{
		temp3 = temp2+1;
	}
	while(temp3 != fifo->head){
		strcpy(temp2->firstName,temp3->firstName);
		strcpy(temp2->lastName,temp3->lastName);
		temp2->roll = temp3->roll;
		temp2->GPA = temp3->GPA;
		temp2->no_courses = temp3->no_courses;
		for(int i=0; i<temp2->no_courses; i++){
			temp2->cid[i] = temp3->cid[i];
		}
		if(temp2 == (fifo->base+(fifo->length*sizeof(Student_t)))){
			temp2 = fifo->base;
		}
		else{
			temp2++;
		}
		if(temp3 == (fifo->base+(fifo->length*sizeof(Student_t)))){
			temp3 = fifo->base;
		}
		else{
			temp3++;
		}

	}
	fifo->head = temp2;
	fifo->count--;
	printf("[INFO] The student number is removed successfully..\n---------------------------\n");

}

void update_student(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Empty){
		printf("Queue is empty!..\n");
		return;
	}
	printf("Enter the roll number to be updated: ");
	scanf("%d",&roll);
	if(check_roll(fifo,roll) == not_exist){
		printf("This roll number %d not found\n",roll);
		return;
	}
	printf("1. First name\n2. Last name\n3. Roll no.\n4. GPA\n5. Courses\n");
	int option;
	scanf("%d",&option);
	if(option == 1){
		update_fname(fifo);
		return;
	}
	if(option == 2){
		update_lname(fifo);
		return;
	}
	if(option == 3){
		update_roll(fifo);
		return;
	}
	if(option == 4){
		update_GPA(fifo);
		return;
	}
	if(option == 5){
		update_courses(fifo);
	}

	return;
}


void show_all(FIFO_t* fifo)
{
	if(check_queue_status(fifo) == Empty){
			printf("Queue is empty!..\n---------------------\n");
			return;
		}
	Student_t* temp = fifo->tail;
	while(temp != fifo->head){
		printf("Student info\n");
		printf("First name: %s\n",temp->firstName);
		printf("Last name: %s\n",temp->lastName);
		printf("Roll number: %d\n",temp->roll);
		printf("GPA: %.2f\n",temp->GPA);
		printf("No. courses registered: %d\n",temp->no_courses);
		for(int i=0; i<temp->no_courses; i++){
			printf("Course %d ID: %d\n",i+1,temp->cid[i]);
		}
		printf("-----------------------------\n");
		temp_advance;
	}



}



