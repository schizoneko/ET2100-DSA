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

typedef struct Subject {
    char name[MAX_NAME_LENGTH];       
    int fee_per_week;                 
    Timeslot time;                     
    struct Subject* next;
} Subject;

typedef struct {
    Subject* first;
    Subject* last;
} Subject_List;

typedef struct Teacher {
    char name[MAX_NAME_LENGTH];
    int id;
    Sex sex;
    Subject subject;
    
    struct Teacher* next;
} Teacher;

typedef struct {
    Teacher* first;
    Teacher* last;
} Teacher_List;

typedef struct {
    Subject* subject;       
    Timeslot time;          
} Schedule_Entry;

typedef struct {
    Schedule_Entry entries[MAX_SUBJECTS];
    int count; 
} Class_Schedule;

typedef struct Classroom {
    char name[MAX_NAME_LENGTH];     
    Teacher* main_teacher;          
    Class_Schedule schedule;        
} Classroom;

typedef struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    Date birth;
    Sex sex;
    Receipt tuition;

    char parent_name[MAX_NAME_LENGTH];
    char address[MAX_LINE_LENGTH];

    struct Student* next;
    struct Classroom* classroom;  
} Student;

typedef struct {
    Student* first;
    Student* last;
} Student_List;

#endif
