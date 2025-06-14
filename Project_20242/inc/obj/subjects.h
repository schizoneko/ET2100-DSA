#ifndef SUBJECT_H
#define SUBJECT_H

#include "header.h"

void init_subject_list(Subject_List* list);

Subject* create_subject(const char* name, int fee_per_week, Timeslot time);

void insert_subject(Subject_List* list, Subject* new_subject);

Subject* search_subject(Subject_List* list, const char* name);

void list_subjects(Subject_List* list);

void list_subjects_by_time(Subject_List* list, Weekday weekday);

#endif
