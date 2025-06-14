#include "classroom.h"

// Initialize a classroom with a name and a main teacher
void init_classroom(Classroom* classroom, const char* name, Teacher* main_teacher) {
    strcpy(classroom->name, name);
    classroom->main_teacher = main_teacher;
    classroom->schedule.count = 0;
}

// Add a student to a classroom
void add_student_to_classroom(Classroom* classroom, Student* student) {
    student->classroom = classroom;  // Link the student to the classroom
}

// Add a subject to the classroom's schedule
void add_subject_to_classroom(Classroom* classroom, Subject* subject, Timeslot time) {
    if (classroom->schedule.count < MAX_SUBJECTS) {
        classroom->schedule.entries[classroom->schedule.count].subject = subject;
        classroom->schedule.entries[classroom->schedule.count].time = time;
        classroom->schedule.count++;
    }
}

// Print the classroom's information (name, main teacher, and number of students)
void print_classroom_info(Classroom* classroom, Student_List* student_list) {
    printf("Classroom: %s\n", classroom->name);
    printf("Main Teacher: %s\n", classroom->main_teacher ? classroom->main_teacher->name : "None");
    printf("Number of Students: %d\n", count_students_in_classroom(student_list, classroom));
}

// Count the number of students in a classroom
int count_students_in_classroom(Student_List* student_list, Classroom* classroom) {
    int count = 0;
    Student* temp = student_list->first; // Assume `student_list` is a global list of students
    while (temp != NULL) {
        if (temp->classroom == classroom) {  // Check if the student belongs to this classroom
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Remove a student from a classroom
void remove_student_from_classroom(Student_List* student_list, Classroom* classroom, int student_id) {
    Student* temp = student_list->first; // Assume `student_list` is a global list of students
    while (temp != NULL) {
        if (temp->id == student_id && temp->classroom == classroom) {
            temp->classroom = NULL;  // Unlink the student from the classroom
            break;
        }
        temp = temp->next;
    }
}

// Print subjects in a classroom based on schedule
void print_classroom_schedule(Classroom* classroom) {
    printf("Schedule for Classroom %s:\n", classroom->name);
    for (int i = 0; i < classroom->schedule.count; i++) {
        Subject* subject = classroom->schedule.entries[i].subject;
        Timeslot time = classroom->schedule.entries[i].time;
        printf("Subject: %s, Fee per Week: %d, Time: %d-%d, Day: %d\n", 
               subject->name, 
               subject->fee_per_week, 
               time.hour_start, time.hour_end, 
               time.weekday);
    }
}

void list_classrooms(Student_List* list) {
    Classroom* printed[100];  
    int count = 0;

    Student* current = list->first;
    while (current != NULL) {
        Classroom* c = current->classroom;
        int already_printed = 0;

        for (int i = 0; i < count; i++) {
            if (printed[i] == c) {
                already_printed = 1;
                break;
            }
        }

        if (!already_printed && c != NULL) {
            printed[count++] = c;
            printf("Classroom: %s\n", c->name);
        }

        current = current->next;
    }
}

void list_students_in_classroom(Student_List* list, const char* class_name) {
    Student* current = list->first;
    printf("Students in classroom %s:\n", class_name);
    int found = 0;
    while (current != NULL) {
        if (current->classroom != NULL && strcmp(current->classroom->name, class_name) == 0) {
            printf("- %s (ID: %d)\n", current->name, current->id);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("No students found for this classroom.\n");
    }
}
