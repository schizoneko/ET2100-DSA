#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include "config.h"

typedef enum {
    Boy,
    Girl,
} Sex;

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
} Weekday;

typedef struct {
    short int hour_start;
    short int hour_end;
    Weekday weekday;
} Timeslot;

typedef struct {
    short int day;
    short int month;
    unsigned int year;
} Date;

typedef struct {
    int money;
    Date payment_time;
} Receipt;

typedef struct Student {
    char name[MAX_NAME_LENGTH];
    Date birth;
    Sex sex;
    Receipt tuition;

    char parent_name[MAX_NAME_LENGTH];
    char address[MAX_LINE_LENGTH];
    
    struct Student* next;
} Student;

typedef struct {
    Student* first;
    Student* last;
} Student_List;

typedef struct Teacher {
    char name[MAX_NAME_LENGTH];
    char subject[MAX_NAME_LENGTH];
    Sex sex;

    struct Teacher* next;
} Teacher;

typedef struct {
    Teacher* first;
    Teacher* last;
} Teacher_List;

typedef struct {
    char name[MAX_NAME_LENGTH];       
    int fee_per_week;                 
    Teacher* teacher;
    Timeslot time;                 
} Subject;

typedef struct {
    Subject* subject;       
    Timeslot time;          
} Schedule_Entry;

typedef struct {
    Schedule_Entry entries[MAX_SUBJECTS];
    int count; 
} Class_Schedule;

typedef struct {
    char name[MAX_NAME_LENGTH];       
    Student_List students;            
    Teacher* main_teacher;           
    Class_Schedule schedule;
} Classroom;

#endif