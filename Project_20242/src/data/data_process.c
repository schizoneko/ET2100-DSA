#include "data_process.h"

void write_students_csv(const char* filename, Student_List* list) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open student file for writing");
        return;
    }

    Student* s = list->first;
    while (s) {
        fprintf(file, "%s,%d,%02d/%02d/%04u,%d,%s,%s,%d,%02d/%02d/%04u\n",
            s->name,
            s->id,
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

void read_students_csv(const char* filename, Student_List* list) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open student file for reading");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        Student* s = (Student*)malloc(sizeof(Student));
        if (!s) continue;
        s->next = NULL;
        s->classroom = NULL;

        sscanf(line, "%99[^,],%d,%hd/%hd/%u,%d,%99[^,],%99[^,],%d,%hd/%hd/%u",
            s->name,
            &s->id,
            &s->birth.day, &s->birth.month, &s->birth.year,
            (int*)&s->sex,
            s->parent_name,
            s->address,
            &s->tuition.money,
            &s->tuition.payment_time.day,
            &s->tuition.payment_time.month,
            &s->tuition.payment_time.year
        );

        if (list->first == NULL) {
            list->first = list->last = s;
        } else {
            list->last->next = s;
            list->last = s;
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
        fprintf(file, "%s,%d,%d,%s\n",
            t->name,
            t->id,
            t->sex,
            t->subject.name
        );
        t = t->next;
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

        sscanf(line, "%99[^,],%d,%d,%99[^,\n]",
            t->name,
            &t->id,
            (int*)&t->sex,
            t->subject.name
        );

        if (list->first == NULL) {
            list->first = list->last = t;
        } else {
            list->last->next = t;
            list->last = t;
        }
    }

    fclose(file);
}

void read_subjects_csv(const char* filename, Subject_List* list) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open subject file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        Subject* s = (Subject*)malloc(sizeof(Subject));
        if (!s) continue;
        s->next = NULL;

        int hour_start, hour_end, weekday;
        sscanf(line, "%99[^,],%d,%d,%d,%d",
            s->name,
            &s->fee_per_week,
            &hour_start,
            &hour_end,
            &weekday
        );

        s->time.hour_start = hour_start;
        s->time.hour_end = hour_end;
        s->time.weekday = (Weekday)weekday;

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
        fprintf(file, "%s,%d,%d,%d,%d\n",
            s->name,
            s->fee_per_week,
            s->time.hour_start,
            s->time.hour_end,
            s->time.weekday
        );
        s = s->next;
    }

    fclose(file);
}