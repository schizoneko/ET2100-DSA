#include "header.h"

#include "students.h"
#include "teachers.h"
#include "subjects.h"
#include "classroom.h"
#include "data_process.h"

void print_student_menu();
void print_teacher_menu();
void print_classroom_menu();
void print_subject_menu();
void print_main_menu();

int main() {
    Student_List student_list;
    Teacher_List teacher_list;
    Subject_List subject_list;
    Classroom classroom;

    init_student_list(&student_list);
    init_teacher_list(&teacher_list);
    init_subject_list(&subject_list);
    init_classroom(&classroom, "Class A", NULL); 

    // Read data from CSV files
    read_students_csv(STUDENT_DATA_PATH, &student_list);
    read_teachers_csv(TEACHER_DATA_PATH, &teacher_list);
    read_subjects_csv(SUBJECT_DATA_PATH, &subject_list);

    int choice;

    while (1) {
        print_main_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Student menu
                while (1) {
                    print_student_menu();
                    int student_choice;
                    scanf("%d", &student_choice);

                    switch (student_choice) {
                        case 1: {
                            // Add student
                            char name[MAX_NAME_LENGTH], parent_name[MAX_NAME_LENGTH], address[MAX_LINE_LENGTH];
                            int id;
                            Date birth;
                            int temp_sex;
                            Sex sex;
                            Receipt tuition;

                            printf("Enter student name: ");
                            scanf("%s", name);
                            printf("Enter student ID: ");
                            scanf("%d", &id);
                            printf("Enter birthdate (day month year): ");
                            scanf("%hd %hd %u", &birth.day, &birth.month, &birth.year);
                            printf("Enter sex (0 for Boy, 1 for Girl): ");
                            scanf("%d", &temp_sex);
                            printf("Enter parent name: ");
                            scanf("%s", parent_name);
                            printf("Enter address: ");
                            scanf("%s", address);
                            printf("Enter tuition fee: ");
                            scanf("%d", &tuition.money);
                            printf("Enter payment date (day month year): ");
                            scanf("%hd %hd %u", &tuition.payment_time.day, &tuition.payment_time.month, &tuition.payment_time.year);

                            sex = (Sex)temp_sex;
                            // Create and insert student
                            Student* new_student = create_student(name, id, birth, sex, tuition, parent_name, address, &classroom);
                            insert_student(&student_list, new_student);
                            write_students_csv(STUDENT_DATA_PATH, &student_list); 
                            break;
                        }
                        case 2: {
                            // Search student
                            int mssv;
                            printf("Enter student ID to search: ");
                            scanf("%d", &mssv);
                            Student* found_student = search_student(&student_list, mssv);
                            if (found_student != NULL) {
                                printf("Found student: %s\n", found_student->name);
                            } else {
                                printf("Student not found.\n");
                            }
                            break;
                        }
                        case 3: {
                            // Remove student
                            int mssv;
                            printf("Enter student ID to remove: ");
                            scanf("%d", &mssv);
                            remove_student(&student_list, mssv);
                            write_students_csv(STUDENT_DATA_PATH, &student_list); // Write to file
                            break;
                        }
                        case 4:
                            // Calculate bill
                            int id;
                            printf("Enter student ID to calculate tuition: ");
                            scanf("%d", &id);
                            calculate_bill(&student_list, id);
                            break;
                        case 0:
                            // Exit student menu
                            break;
                        default:
                            printf("Invalid choice, please try again.\n");
                            continue;
                    }

                    if (student_choice == 0) break; // Exit loop if user chooses 0
                }
                break;
            case 2:
                // Teacher menu
                while (1) {
                    print_teacher_menu();
                    int teacher_choice;
                    scanf("%d", &teacher_choice);

                    switch (teacher_choice) {
                        case 1: {
                            // Add teacher
                            char name[MAX_NAME_LENGTH], subject_name[MAX_NAME_LENGTH];
                            int id;
                            Sex sex;

                            printf("Enter teacher name: ");
                            scanf("%s", name);
                            printf("Enter teacher ID: ");
                            scanf("%d", &id);
                            printf("Enter subject name: ");
                            scanf("%s", subject_name);
                            printf("Enter sex (0 for Boy, 1 for Girl): ");
                            
                            int sex_input;
                            scanf("%d", &sex_input);
                            sex = (Sex)sex_input;

                            Subject* chosen_subject = search_subject(&subject_list, subject_name);
                            if (chosen_subject == NULL) {
                                printf("Subject not found. Please add the subject first.\n");
                                break;
                            }

                            Teacher* new_teacher = create_teacher(name, id, sex, *chosen_subject);
                            insert_teacher(&teacher_list, new_teacher);
                            write_teachers_csv(TEACHER_DATA_PATH, &teacher_list); // Ghi vào file
                            break;
                        }
                        case 2: {
                            // Search teacher
                            int id;
                            printf("Enter teacher ID to search: ");
                            scanf("%d", &id);
                            Teacher* found_teacher = search_teacher(&teacher_list, id);
                            if (found_teacher != NULL) {
                                printf("Found teacher: %s\n", found_teacher->name);
                            } else {
                                printf("Teacher not found.\n");
                            }
                            break;
                        }
                        case 3: {
                            // Remove teacher
                            int id;
                            printf("Enter teacher ID to remove: ");
                            scanf("%d", &id);
                            remove_teacher(&teacher_list, id);
                            write_teachers_csv(TEACHER_DATA_PATH, &teacher_list); // Write to file
                            break;
                        }
                        case 0:
                            // Exit teacher menu
                            break;
                        default:
                            printf("Invalid choice, please try again.\n");
                            continue;
                    }

                    if (teacher_choice == 0) break; // Exit loop if user chooses 0
                }
                break;
            case 3: {
                while (1) {
                    print_classroom_menu();
                    int classroom_choice;
                    scanf("%d", &classroom_choice);
                    getchar(); // Xoá newline từ input buffer

                    switch (classroom_choice) {
                        case 1: {
                            // Tạo classroom mới và gán cho học sinh
                            char class_name[MAX_NAME_LENGTH];
                            printf("Enter new classroom name: ");
                            scanf("%s", class_name);

                            Classroom* new_classroom = (Classroom*)malloc(sizeof(Classroom));
                            if (!new_classroom) {
                                printf("Failed to allocate memory for classroom.\n");
                                break;
                            }

                            init_classroom(new_classroom, class_name, NULL);  // Không có giáo viên chính lúc đầu

                            // Gán classroom cho từng học sinh
                            int student_id;
                            while (1) {
                                printf("Enter student ID to add to classroom (-1 to stop): ");
                                scanf("%d", &student_id);
                                if (student_id == -1) break;

                                Student* student = search_student(&student_list, student_id);
                                if (student) {
                                    add_student_to_classroom(new_classroom, student);
                                    printf("Added student %s to classroom %s.\n", student->name, class_name);
                                } else {
                                    printf("Student not found.\n");
                                }
                            }

                            break;
                        }

                        case 2: {
                            // Liệt kê tất cả classroom dựa trên student list
                            list_classrooms(&student_list);
                            break;
                        }

                        case 3: {
                            // In toàn bộ học sinh trong một lớp cụ thể
                            char class_name[MAX_NAME_LENGTH];
                            printf("Enter classroom name to list students: ");
                            scanf("%s", class_name);
                            list_students_in_classroom(&student_list, class_name);
                            break;
                        }

                        case 4: {
                            // In thời khóa biểu của classroom
                            char class_name[MAX_NAME_LENGTH];
                            printf("Enter classroom name to print schedule: ");
                            scanf("%s", class_name);

                            // Duyệt student_list để tìm classroom có tên khớp
                            Classroom* target = NULL;
                            Student* cur = student_list.first;
                            while (cur != NULL) {
                                if (cur->classroom && strcmp(cur->classroom->name, class_name) == 0) {
                                    target = cur->classroom;
                                    break;
                                }
                                cur = cur->next;
                            }

                            if (target) {
                                print_classroom_schedule(target);
                            } else {
                                printf("Classroom not found.\n");
                            }
                            break;
                        }

                        case 5: {
                            // In thông tin lớp học (tên, giáo viên, số học sinh)
                            char class_name[MAX_NAME_LENGTH];
                            printf("Enter classroom name to print info: ");
                            scanf("%s", class_name);

                            Classroom* target = NULL;
                            Student* cur = student_list.first;
                            while (cur != NULL) {
                                if (cur->classroom && strcmp(cur->classroom->name, class_name) == 0) {
                                    target = cur->classroom;
                                    break;
                                }
                                cur = cur->next;
                            }

                            if (target) {
                                print_classroom_info(target, &student_list);
                            } else {
                                printf("Classroom not found.\n");
                            }
                            break;
                        }

                        case 0:
                            // Thoát menu
                            break;

                        default:
                            printf("Invalid choice. Please try again.\n");
                            continue;
                    }

                    if (classroom_choice == 0) break;
                }
                break;
            }
            
            case 4:
                {
                    int subject_choice;
                    while (subject_choice != 5) {
                        print_subject_menu();
                        scanf("%d", &subject_choice);
                        switch (subject_choice) {
                            case 1: {
                                char name[MAX_NAME_LENGTH];
                                int fee_per_week;
                                Weekday weekday;
                                Timeslot time;
                                int temp_weekday;

                                printf("Enter subject name: ");
                                scanf("%s", name);
                                printf("Enter fee per week: ");
                                scanf("%d", &fee_per_week);
                                printf("Enter weekday (0=Monday, 1=Tuesday, etc.): ");
                                scanf("%d", &temp_weekday);
                                printf("Enter start hour: ");
                                scanf("%hd", &time.hour_start);
                                printf("Enter end hour: ");
                                scanf("%hd", &time.hour_end);

                                weekday = (Weekday)temp_weekday;
                                time.weekday = weekday;

                                Subject* new_subject = create_subject(name, fee_per_week, time);
                                insert_subject(&subject_list, new_subject);
                                write_subjects_csv(SUBJECT_DATA_PATH, &subject_list);
                                break;
                            }
                            case 2: {
                                char search_name[MAX_NAME_LENGTH];
                                printf("Enter subject name to search: ");
                                scanf("%s", search_name);

                                Subject* found_subject = search_subject(&subject_list, search_name);
                                if (found_subject) {
                                    printf("Found Subject: %s\n", found_subject->name);
                                } else {
                                    printf("Subject not found.\n");
                                }
                                break;
                            }
                            case 3: {
                                // Liệt kê tất cả các môn học
                                list_subjects(&subject_list);
                                break;
                            }
                            case 4: {
                                // Liệt kê môn học theo thời gian
                                int weekday;
                                printf("Enter weekday to filter by (0=Monday, 1=Tuesday, etc.): ");
                                scanf("%d", &weekday);
                                list_subjects_by_time(&subject_list, (Weekday)weekday);
                                break;
                            }
                            case 5:
                                printf("Back to Main Menu.\n");
                                break;
                            default:
                                printf("Invalid choice. Please try again.\n");
                        }
                    }
                }
                break;

            case 0:
                // Exit program
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                continue;

                
        }
    }

    return 0;
}
/*
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}*/

void print_main_menu() {
    //clear_screen();
    printf("=== Main Menu ===\n");
    printf("1. Student Management\n");
    printf("2. Teacher Management\n");
    printf("3. Classroom Management\n");
    printf("4. Subject Management\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void print_student_menu() {
    //clear_screen();
    printf("=== Student Menu ===\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Remove Student\n");
    printf("4. Calculate Tuition Bill\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
}

void print_teacher_menu() {
    //clear_screen();
    printf("=== Teacher Menu ===\n");
    printf("1. Add Teacher\n");
    printf("2. Search Teacher\n");
    printf("3. Remove Teacher\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
}

void print_classroom_menu() {
    //clear_screen();
    printf("=== Classroom Menu ===\n");
    printf("1. Add Classroom\n");
    printf("2. Add Subject to Classroom\n");
    printf("3. View Classroom Info\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
}

void print_subject_menu() {
    //clear_screen();
    printf("=== Subject Management ===\n");
    printf("1. Add Subject\n");
    printf("2. Search Subject\n");
    printf("3. List All Subjects\n");
    printf("4. List Subjects by Time\n");
    printf("5. Back to Main Menu\n");
    printf("Choose an option: ");
}