#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include "../config.h"
#include "../data_struct.h"

void read_students_csv(const char *filename, Student_List *list);
void write_students_csv(const char *filename, Student_List *list);

void read_teachers_csv(const char *filename, Teacher *teachers, int *count);
void write_teachers_csv(const char *filename, Teacher *teachers, int count);

void read_subjects_csv(const char *filename, Subject *subjects, int *count);
void write_subjects_csv(const char *filename, Subject *subjects, int count);

void read_classroom_csv(const char *filename, Classroom *classroom, int *count);
void write_classroom_csv(const char *filename, Classroom *classroom, int count);

#endif