#ifndef STUDENTS_H
#define STUDENTS_H

#include "../config.h"
#include "../data_struct.h"

void init_student_list(Student_List* list);  
Student* create_student(const char* name, Date birth, Sex sex, Receipt tuition, const char* parent_name, const char* address); 
void insert_student(Student_List* list, Student* new_student); 
Student* search_student(Student_List* list, int mssv);
void remove_student(Student_List* list, long mssv);
void calculate_bill(Student_List* list, long mssv); 

#endif