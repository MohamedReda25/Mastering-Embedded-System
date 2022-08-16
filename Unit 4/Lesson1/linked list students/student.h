/*
 * student.h
 *
 *  Created on: Aug 16, 2022
 *      Author: redam
 */





#ifndef STUDENT_H_
#define STUDENT_H_
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "Platform_Types.h"

#define printf(...)  { fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}


typedef struct{
	char name[40];
	uint32 id;
	float height;
}Sdata_t;


typedef struct {
	Sdata_t data;
	struct Student_t* nextStudent;
}Student_t;

typedef enum{
	exists,
	Not_exist
}id_state;





id_state check_id(int id);
void Add_Student();
void Delete_Student();
void Show_all_list();
void Delete_All();
void List_lenght();
void Reverse_list();








#endif /* STUDENT_H_ */
