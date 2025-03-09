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

bool enqueue(PQueue *pq, int value, int priority) {
    if (is_full(pq)) {
        printf("Queue overflow!\n");
        return false;
    }

    // If empty, insert at front
    if (is_empty(pq)) {
        pq->front = pq->rear = 0;
        pq->queue[0].data = value;
        pq->queue[0].priority = priority;
        return true;
    }

    // Find position to insert while maintaining priority order
    int i = pq->rear;
    while (i >= pq->front && pq->queue[i].priority > priority) {
        pq->queue[i + 1] = pq->queue[i];  // Shift elements right
        i--;
    }

    // Insert the new element
    pq->queue[i + 1].data = value;
    pq->queue[i + 1].priority = priority;
    pq->rear++; // Increase rear

    return true;
}

int dequeue(PQueue* pq) {
    if (is_empty(pq)) {
        printf("Queue has 0 elements.\n");
        return -1;
    }

    int dequeued_value = pq->queue[pq->front].data;  // Get highest priority element

    // Shift all elements left (FIFO for equal priority)
    for (int i = pq->front; i < pq->rear; i++) {
        pq->queue[i] = pq->queue[i + 1];
    }
    
    pq->rear--; // Reduce rear

    // If the queue becomes empty, reset front and rear
    if (pq->rear < pq->front) {
        pq->front = pq->rear = -1;
    }

    return dequeued_value;
}

void display_queue(PQueue *pq) {
    if (is_empty(pq)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\nPriority Queue (front -> rear):\n");
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("[Value: %d, Priority: %d] ", pq->queue[i].data, pq->queue[i].priority);
    }
    printf("\n");
}


int main() {
    PQueue pq;
    init_PQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 40, 0);
    enqueue(&pq, 50, 1);

    display_queue(&pq);

    printf("\nDequeued: %d\n", dequeue(&pq));
    display_queue(&pq);

    return 0;
}
