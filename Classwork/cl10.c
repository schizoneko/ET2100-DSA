#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int data[MAX];
    int size;
} Stack;
 
int isFull(Stack *s) {
    return (s->size == MAX);
}
 
void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("\nngan xep day!");
        return;
    }
    s->data[s->size] = x;
    s->size++;
}
 
int isEmpty(Stack *s) {
    return (s->size == 0);
}
 
void initStack(Stack *s) {
    s->size = 0;
}
 
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("\n ngan xep rong!");
        return false; 
    }
    s->size--;
    return s->data[s->size];
}
 
int peek(Stack *s) {
    return s->data[s->size - 1];
}
 
void display(Stack *s) {
    for (int i = 0; i < s->size; i++) {
        printf("%d\t", s->data[i]);
    }
    printf("\n");
}
 
int main() {
    Stack s;
    initStack(&s);
    pop(&s);
    display(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    display(&s);
    int p = pop(&s);
    printf("%d\n", p);
    display(&s);
    return 0;
}