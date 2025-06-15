#ifndef TEACHERS_H
#define TEACHERS_H

#include "header.h"

void init_teacher_list(Teacher_List* list);

Teacher* create_teacher(const char* name, int id, Sex sex, Subject subject);

void insert_teacher(Teacher_List* list, Teacher* new_teacher);

Teacher* search_teacher(Teacher_List* list, int id);

void remove_teacher(Teacher_List* list, int id);

void print_teacher_list(Teacher_List* list);

#endif