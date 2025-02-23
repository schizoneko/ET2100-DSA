#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int id;
    char name[MAX];
    long price;
} Book;

typedef struct {
    Book data[MAX]; // Array of books named [data]
    int top; 
} Stack;

void stack_init(Stack *stack){
    stack->top = -1; // Stack is empty so the pointer is pointing to the -1 position of the array (the array starts at 0)
}

void stack_reset(Stack *stack){
    stack->top = -1; // Reset stack by setting the top pointer to the first element of the list
}

bool is_full(Stack *stack){
    return stack->top == MAX - 1;
}

bool is_empty(Stack *stack){
    return stack->top == -1;
}

Book pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
        return; 
    }
    return stack->data[stack->top--];  // Return the top book and decrement top index
}

void push(Stack *stack, Book *book) {
    if (is_full(stack)) {
        printf("Stack is full! Cant put this book: %s\n", book->name);
        return;
    }
    stack->top++;
    stack->data[stack->top] = *book; // Copy book data into stack
}

void display_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Books in stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("ID: %d, Name: %s, Price: %ld\n", stack->data[i].id, stack->data[i].name, stack->data[i].price);
    }
}

double average_price(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
        return 0;
    }
    long total = 0;
    for (int i = 0; i <= stack->top; i++) {
        total += stack->data[i].price;
    }
    return (double) total / (stack->top + 1);
}

int main() {
    Stack bookStack;
    stack_init(&bookStack);

    Book book1 = {001, "Fundemetal of Logic Design", 250000};
    Book book2 = {002, "Digital Design and Computer Architecture", 300000};
    Book book3 = {003, "Signal & Systems", 400000};

    push(&bookStack, &book1);
    push(&bookStack, &book2);
    push(&bookStack, &book3);

    display_stack(&bookStack);

    printf("Average book price: %.2f\n", average_price(&bookStack));

    pop(&bookStack);
    display_stack(&bookStack);

    stack_reset(&bookStack);
    printf("\nAfter reset:\n");
    display_stack(&bookStack);

    return 0;
}