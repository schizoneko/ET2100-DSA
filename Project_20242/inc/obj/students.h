#ifndef STUDENT_H
#define STUDENT_H

#include "header.h"

void init_student_list(Student_List* list);

Student* create_student(const char* name, int id, Date birth, Sex sex, Receipt tuition, const char* parent_name, const char* address, Classroom* classroom);

void insert_student(Student_List* list, Student* new_student);

Student* search_student(Student_List* list, int id);

void remove_student(Student_List* list, int id);

void calculate_bill(Student_List* list, int id);

void print_student_list(Student_List* list);

#endif
