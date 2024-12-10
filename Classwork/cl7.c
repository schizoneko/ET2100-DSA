//Thêm phần tử vào dưới stack   

#include <stdio.h>
#include <stdlib.h>

typedef struct Wood {
    char type[100];
    int size;
    int age;
    struct Wood *next;
} Wood;

// Định nghĩa stack cho từng loại gỗ
typedef struct WoodStack {
    int capacity;
    int current_Size;
    Wood* top;
} WoodStack;

void initStack(WoodStack* stack, int capacity) {
    // Khởi tạo trạng thái ban đầu
    stack->top = NULL;            // Stack rỗng ban đầu
    stack->capacity = capacity;   // Gán sức chứa tối đa
    stack->current_Size = 0;       // Gán số phần tử hiện tại là 0
}

int isFull(struct WoodStack* stack) {
    return stack->current_Size == stack->capacity;
}

// Stack is empty when top is equal to NULL
int isEmpty(struct WoodStack* stack) {
    return stack->top == NULL;
}

void string_copy(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

Wood* create_Wood(char* name, int size, int age) {
    
}