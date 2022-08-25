/*
 * Student.h
 *
 *  Created on: Aug 23, 2022
 *      Author: redam
 */

#ifndef STUDENT_H_
#define STUDENT_H_


typedef struct{
	char firstName[50];
	char lastName[50];
	int roll;
	float GPA;
	int cid[10];
	int no_courses;
}Student_t;

typedef enum {
	exist,
	not_exist
}roll_state,name_state,course_state;


Student_t students[50];




#endif /* STUDENT_H_ */
