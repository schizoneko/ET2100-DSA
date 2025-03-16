#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Stack with linked list

#define MAX 100
#define VALUE 50

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void init_Stack (Stack *s) {
    s->top = NULL;
}

Node* create_node(int k) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

bool is_Empty(Stack *s) {
    return (s->top == NULL);
}

void push(Stack *s, int k) {
    Node* newNode = create_node(k);
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if(is_Empty(s)) {
        printf("Stack underflow.\n");
        return -1;
    }
    Node* temp = s->top;
    int data = temp->data;
    temp->data = s->top->next;
    free(temp);
    return data;
}

int peek(Stack *s) {
    if(is_Empty(s)) {
        printf("Stack underflow.\n");
        return -1;
    }
    return stack->top->data;
}

void display_Stack(Stack *s) {
    if(is_Empty(s)) {
        printf("Stack underflow.\n");
        return -1;
    }

    Node* temp = stack->top;
    printf("Data in queue: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void free_Stack(Stack *s) {
    Node* temp;
    while (s->top != NULL) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int main () {
    Stack s;
    init_Stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    display_Stack(&s);

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    display_Stack(&s);

    free_Stack(&s);
    return 0;
}
