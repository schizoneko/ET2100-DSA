#include "teachers.h"

void init_teacher_list(Teacher_List* list) {
    list->first = list->last = NULL;
}

Teacher* create_teacher(const char* name, int id, Sex sex, Subject subject) {
    Teacher* new_teacher = (Teacher*)malloc(sizeof(Teacher));
    if (!new_teacher) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(new_teacher->name, name);
    new_teacher->id = id;
    new_teacher->sex = sex;
    new_teacher->subject = subject;
    new_teacher->next = NULL;
    return new_teacher;
}

void insert_teacher(Teacher_List* list, Teacher* new_teacher) {
    if (list->first == NULL) {
        list->first = list->last = new_teacher;
    } else {
        list->last->next = new_teacher;
        list->last = new_teacher;
    }
}

// Tìm kiếm giáo viên theo ID
Teacher* search_teacher(Teacher_List* list, int id) {
    Teacher* temp = list->first;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Xóa giáo viên theo ID
void remove_teacher(Teacher_List* list, int id) {
    Teacher* temp = list->first;
    Teacher* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Teacher with ID %d not found.\n", id);
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

