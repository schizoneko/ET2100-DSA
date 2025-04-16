#include "../config.h"
#include "../data_struct.h"

bool add_subject_to_schedule(ClassSchedule* schedule, Subject* subject) {
    if (schedule->count >= MAX_SUBJECTS) 
    return false;

    // Kiểm tra trùng lịch học
    for (int i = 0; i < schedule->count; i++) {
        if (schedule->entries[i].time.weekday == subject->time.weekday &&
            !(subject->time.hour_end <= schedule->entries[i].time.hour_start ||
              subject->time.hour_start >= schedule->entries[i].time.hour_end)) {
            return false; // Trùng giờ
        }
    }

    schedule->entries[schedule->count].subject = subject;
    schedule->entries[schedule->count].time = subject->time;
    schedule->count++;
    return true;
}
