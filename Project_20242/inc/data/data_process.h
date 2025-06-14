#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include "header.h"  

// Student CSV
void read_students_csv(const char *filename, Student_List *list);
void write_students_csv(const char *filename, Student_List *list);

// Teacher CSV
void read_teachers_csv(const char *filename, Teacher_List *list);
void write_teachers_csv(const char *filename, Teacher_List *list);

// Subject CSV
void read_subjects_csv(const char *filename, Subject_List *list);
void write_subjects_csv(const char *filename, Subject_List *list);

#endif
