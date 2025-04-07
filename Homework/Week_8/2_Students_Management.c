#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_CODE 6

typedef struct Course {
    char mshp[MAX_CODE];     
    char name[MAX_NAME];     
    int credits;       
    int semester;     
    float grade;        
    struct Course* next;
} Course;

typedef struct {
    Course* head;
    Course* tail;
} CourseList;

typedef struct Student {
    long mssv;
    char name[MAX_NAME];
    CourseList courses;
    struct Student* next;
} Student;

typedef struct {
    Student* head;
    Student* tail;
} StudentList;

void initCourseList(CourseList* list) {
    list->head = list->tail = NULL;
}

void initStudentList(StudentList* list) {
    list->head = list->tail = NULL;
}

Course* createCourse(const char* mshp, const char* name, int credits, int semester, float grade) {
    Course* newCourse = (Course*)malloc(sizeof(Course));
    strcpy(newCourse->mshp, mshp);
    strcpy(newCourse->name, name);
    newCourse->credits = credits;
    newCourse->semester = semester;
    newCourse->grade = grade;
    newCourse->next = NULL;
    return newCourse;
}

Student* createStudent(long mssv, const char* name) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->mssv = mssv;
    strcpy(newStudent->name, name);
    initCourseList(&newStudent->courses);
    newStudent->next = NULL;
    return newStudent;
}

void addCourse(CourseList* list, Course* course) {
    if (list->head == NULL) {
        list->head = list->tail = course;
    } else {
        list->tail->next = course;
        list->tail = course;
    }
}

void addStudent(StudentList* list, Student* student) {
    if (list->head == NULL) {
        list->head = list->tail = student;
    } else {
        list->tail->next = student;
        list->tail = student;
    }
}

void displayCourses(CourseList* list) {
    Course* cur = list->head;
    while (cur != NULL) {
        printf("  MSHP: %s\n", cur->mshp);
        printf("  Name: %s\n", cur->name);
        printf("  Credits: %d, Semester: %d, Score: %.2f\n", cur->credits, cur->semester, cur->grade);
        cur = cur->next;
    }
}

void displayStudents(StudentList* list) {
    Student* cur = list->head;
    while (cur != NULL) {
        printf("MSSV: %ld\n", cur->mssv);
        printf("Name: %s\n", cur->name);
        printf("Courses:\n");
        displayCourses(&cur->courses);
        printf("----------------------\n");
        cur = cur->next;
    }
}

int main() {
    StudentList list;
    initStudentList(&list);

    Student* sv1 = createStudent(12345678, "Nguyen Van A");
    Student* sv2 = createStudent(87654321, "Tran Thi B");

    addCourse(&sv1->courses, createCourse("MI1111", "Giai Tich I", 3, 1, 8.5));
    addCourse(&sv1->courses, createCourse("ET2100", "DSA", 4, 1, 7.0));

    addCourse(&sv2->courses, createCourse("ET4032", "Analog IC Design", 3, 2, 9.0));

    addStudent(&list, sv1);
    addStudent(&list, sv2);

    displayStudents(&list);

    return 0;
}
