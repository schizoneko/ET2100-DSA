#include "../../inc/header.h"

// Priority Queue

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element queue[MAX];
    int front;
    int rear; 
} PQueue;

void init_PQueue(PQueue *pq) {
    pq->front = pq->rear = -1;
}

bool is_empty(PQueue *pq) {
    return pq->front == -1;
}

bool is_full(PQueue *pq) {
    return (pq->front == (pq->rear + 1) % MAX);
}