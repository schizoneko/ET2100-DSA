#ifndef CLASSROOMS_H
#define CLASSROOMS_H

#include "header.h"
#include "students.h"
#include "subjects.h" 

void init_classroom(Classroom* classroom, const char* name, Teacher* main_teacher);
void add_student_to_classroom(Classroom* classroom, Student* student);
void add_subject_to_classroom(Classroom* classroom, Subject* subject, Timeslot time);
void remove_student_from_classroom(Student_List* student_list, Classroom* classroom, int student_id);
void print_classroom_info(Classroom* classroom, Student_List* student_list);
int count_students_in_classroom(Student_List* student_list, Classroom* classroom);
void print_classroom_schedule(Classroom* classroom);
void list_classrooms(Student_List* list);
void list_students_in_classroom(Student_List* list, const char* class_name);

#endif
