/*
 * FIFO.h
 *
 *  Created on: Aug 23, 2022
 *      Author: redam
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "Student.h"

#define printf(...)  { fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

#define students_info {printf("[INFO] The total number of the student is %d\n",fifo->count); \
		printf("[INFO] You can add up to %d students\n",fifo->length); \
		printf("[INFO] You can add %d more students\n----------------------\n",(fifo->length-fifo->count));}

#define temp_advance {if(temp == (fifo->base+(fifo->length*sizeof(Student_t)))){ \
			temp = fifo->base;}\
		else{\
			temp++;}\
					}
#define continue_ {\
			fscanf(ptr, "%s",tr_fn);\
			fscanf(ptr, "%s",tr_ln);\
			fscanf(ptr, "%f",&tr_gpa);\
			for(int i=0; i<5; i++){\
				fscanf(ptr, "%d",&tr_c[i]);\
			}\
}



typedef struct {
	Student_t* base;
	Student_t* head;
	Student_t* tail;
	int count;
	int length;
}FIFO_t;


typedef enum{
	Empty,
	Not_empty,
	Full
}Queue_state;

FIFO_t fifo;

Queue_state check_queue_status(FIFO_t* fifo);
name_state check_name(FIFO_t* fifo ,char* fname);
roll_state check_roll(FIFO_t* fifo ,int roll);
course_state check_course_id(FIFO_t* fifo , int c_id);

void update_courses(FIFO_t* fifo);
void update_GPA(FIFO_t* fifo);
void update_roll(FIFO_t* fifo);
void update_lname(FIFO_t* fifo);
void update_fname(FIFO_t* fifo);
void FIFO_INIT(FIFO_t* fifo, Student_t* buff, int length);
void add_student_file();
void add_student_manually(FIFO_t* fifo);
void find_r1(FIFO_t* fifo);
void find_fn(FIFO_t* fifo);
void find_c(FIFO_t* fifo);
void total_number(FIFO_t* fifo);
void delete_student(FIFO_t* fifo);
void update_student(FIFO_t* fifo);
void show_all(FIFO_t* fifo);



#endif /* FIFO_H_ */
