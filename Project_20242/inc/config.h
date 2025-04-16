#ifndef CONFIG_H
#define CONFIG_H

/* Standard libraries ------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>

/* Configuration ------------------------------------*/
// Paths
#define STUDENT_DATA_PATH "student_data.csv"
#define TEACHER_DATA_PATH "teacher_data.csv"
#define SUBJECT_DATA_PATH "subject_data.csv"
#define CLASSROOM_DATA_PATH "classroom.csv"

// Params
#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 10

#endif /* CONFIG_H */