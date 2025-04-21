#define MAX_NAME 50

typedef struct {
    char class_name[MAX_NAME];
    int max_student;

    student_list list;
    Teacher* main_teach;

} Classroom;

typedef struct Student {
    char name[MAX_NAME];
    struct Student* next;
} Student;

typedef struct {
    Student* first;
    Student* last;
} student_list;

typedef struct Teacher {
    char name[MAX_NAME];
    struct Teacher* teacher;
} Teacher;

typedef struct {
    Teacher* first;
    Teacher* last;
} teacher_list;