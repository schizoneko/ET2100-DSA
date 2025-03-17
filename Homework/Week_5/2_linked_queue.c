#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Queue with linked list

#define MAX 100
#define VALUE 50

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void init_Queue(Queue *q) {
    q->front = q->rear = NULL;
}

bool is_empty(Queue *q) {
    return(q->front == NULL);
}

Node* create_node(int k) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* q, int value) {
    Node* newNode = create_node(value); 

    if (is_empty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; 
    }

    free(temp);
    return data;
}

int peek(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

void display_Queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_Queue(Queue* q) {
    Node* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

int main() {
    Queue q;
    init_Queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display_Queue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display_Queue(&q);

    free_Queue(&q);
    return 0;
}