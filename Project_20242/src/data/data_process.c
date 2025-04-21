#include "data_process.h"

void read_students_csv(const char* filename, Student_List* list) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open student file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        Student* s = (Student*)malloc(sizeof(Student));
        if (!s) continue;
        s->next = NULL;

        int day, month, year;
        sscanf(line, "%99[^,],%hd/%hd/%u,%d,%99[^,],%99[^,],%d,%hd/%hd/%u",
            s->name, 
            &s->birth.day, &s->birth.month, &s->birth.year, 
            (int*)&s->sex,
            s->parent_name, s->address,
            &s->tuition.money,
            &s->tuition.payment_time.day, &s->tuition.payment_time.month, &s->tuition.payment_time.year
        );

        // Nếu danh sách trống, gán cả first và last là sinh viên mới
        if (list->first == NULL) {
            list->first = list->last = s;
        } else {
            // Nếu danh sách không trống, gán s vào cuối danh sách
            list->last->next = s;
            list->last = s;
        }
    }

    fclose(file);
}

void write_students_csv(const char* filename, Student_List* list) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open student file for writing");
        return;
    }

    Student* s = list->first;
    while (s) {
        fprintf(file, "%s,%02d/%02d/%04u,%d,%s,%s,%d,%02d/%02d/%04u\n",
            s->name,
            s->birth.day, s->birth.month, s->birth.year,
            s->sex,
            s->parent_name,
            s->address,
            s->tuition.money,
            s->tuition.payment_time.day,
            s->tuition.payment_time.month,
            s->tuition.payment_time.year
        );
        s = s->next;
    }

    fclose(file);
}

void read_teachers_csv(const char* filename, Teacher_List* list) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open teacher file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        Teacher* t = (Teacher*)malloc(sizeof(Teacher));
        if (!t) continue;
        t->next = NULL;

        sscanf(line, "%[^,]", t->main_subject);

        if (list->first == NULL) {
            list->first = list->last = t;
        } else {
            list->last->next = t;
            list->last = t;
        }
    }
    fclose(file);
}

void write_teachers_csv(const char* filename, Teacher_List* list) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open teacher file for writing");
        return;
    }
    Teacher* t = list->first;
    while (t) {
        fprintf(file, "%s\n", t->main_subject);
        t = t->next;
    }
    fclose(file);
}

void read_subjects_csv(const char* filename, Subject_List* list) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open subject file");
        return;
    }
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        Subject* s = (Subject*)malloc(sizeof(Subject));
        if (!s) continue;
        s->next = NULL;

        sscanf(line, "%[^,],%d", s->name, &s->fee);

        if (list->first == NULL) {
            list->first = list->last = s;
        } else {
            list->last->next = s;
            list->last = s;
        }
    }
    fclose(file);
}

void write_subjects_csv(const char* filename, Subject_List* list) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open subject file for writing");
        return;
    }
    Subject* s = list->first;
    while (s) {
        fprintf(file, "%s,%d\n", s->name, s->fee);
        s = s->next;
    }
    fclose(file);
}


