//viết chương trình chính ứng dụng Stack để chuyển đổi một số nguyên sang số hệ 2.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top; 
} Stack;

void stack_init(Stack *stack){
    stack->top = -1; 
}

void stack_reset(Stack *stack){
    stack->top = -1; 
}

bool is_full(Stack *stack){
    return stack->top == MAX - 1;
}

bool is_empty(Stack *stack){
    return stack->top == -1;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
        return -1; 
    }
    return stack->data[stack->top--];
}

bool push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack is full!\n");
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

int main() {
    Stack s;
    stack_init(&s);

    int x;

    printf("Insert integer x: ");
    scanf("%d", &x);

    if (x == 0) {
        printf("Binary: 0\n");
        return 0;
    }

    while (x > 0) {
        push(&s, x % 2); 
        x /= 2;          
    }

    printf("Binary: ");
    while (!is_empty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");

    return 0;
}