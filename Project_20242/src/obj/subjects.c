#include "subjects.h"

// Hàm khởi tạo danh sách môn học
void init_subject_list(Subject_List* list) {
    list->first = list->last = NULL;
}

// Hàm tạo một môn học mới
Subject* create_subject(const char* name, int fee_per_week, Timeslot time) {
    Subject* new_subject = (Subject*)malloc(sizeof(Subject));
    if (!new_subject) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(new_subject->name, name);
    new_subject->fee_per_week = fee_per_week;
    new_subject->time = time;
    new_subject->next = NULL;
    return new_subject;
}

// Hàm thêm môn học vào danh sách
void insert_subject(Subject_List* list, Subject* new_subject) {
    if (list->first == NULL) {
        list->first = list->last = new_subject;
    } else {
        list->last->next = new_subject;
        list->last = new_subject;
    }
}

// Hàm tìm kiếm môn học theo tên
Subject* search_subject(Subject_List* list, const char* name) {
    Subject* temp = list->first;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Hàm liệt kê tất cả các môn học trong danh sách
void list_subjects(Subject_List* list) {
    Subject* temp = list->first;
    if (temp == NULL) {
        printf("No subjects found.\n");
        return;
    }

    printf("List of Subjects:\n");
    while (temp != NULL) {
        printf("Name: %s, Fee per Week: %dk dong, Time: %dh - %dh\n",
            temp->name, temp->fee_per_week, temp->time.hour_start, temp->time.hour_end);
        temp = temp->next;
    }
}

// Hàm liệt kê các môn học theo thời gian
void list_subjects_by_time(Subject_List* list, Weekday weekday) {
    Subject* temp = list->first;
    int found = 0;
    printf("Subjects on %d:\n", weekday);

    while (temp != NULL) {
        if (temp->time.weekday == weekday) {
            printf("Name: %s, Fee per Week: %dk dong, Time: %dh - %dh\n",
                temp->name, temp->fee_per_week, temp->time.hour_start, temp->time.hour_end);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No subjects found for this day.\n");
    }
}
