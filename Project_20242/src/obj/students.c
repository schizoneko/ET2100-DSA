#include "students.h"

void init_student_list(Student_List* list) {
    list->first = list->last = NULL;
}

Student* create_student(const char* name, int id, Date birth, Sex sex, Receipt tuition, const char* parent_name, const char* address, Classroom* classroom) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (!new_student) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(new_student->name, name);
    new_student->id = id;
    new_student->birth = birth;
    new_student->sex = sex;
    new_student->tuition = tuition;
    strcpy(new_student->parent_name, parent_name);
    strcpy(new_student->address, address);
    new_student->classroom = classroom;
    new_student->next = NULL;

    return new_student;
}

void insert_student(Student_List* list, Student* new_student) {
    if (list->first == NULL) {
        list->first = list->last = new_student;
    } else {
        list->last->next = new_student;
        list->last = new_student;
    }
}

Student* search_student(Student_List* list, int id) {
    Student* temp = list->first;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void remove_student(Student_List* list, int id) {
    Student* temp = list->first;
    Student* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        list->first = temp->next;
    } else {
        prev->next = temp->next;
    }

    if (temp == list->last) {
        list->last = prev;
    }

    free(temp);
}

void calculate_bill(Student_List* list, int id) {
    Student* student = search_student(list, id);
    if (student != NULL) {
        printf("Calculating bill for student: %s (ID: %d)\n", student->name, student->id);
        
        // Calculate tuition fee from subjects in the student's classroom
        int total_fee = 0;
        Classroom* classroom = student->classroom;
        for (int i = 0; i < classroom->schedule.count; i++) {
            Subject* subject = classroom->schedule.entries[i].subject;
            total_fee += subject->fee_per_week;
        }

        // Total tuition for 4 weeks (per month)
        int monthly_fee = total_fee * 4;
        printf("Total Monthly Tuition Fee: %dk dong\n", monthly_fee);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

void print_student_list(Student_List* list) {
    Student* current = list->first;
    printf("Student List:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}