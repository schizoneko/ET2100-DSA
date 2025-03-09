#include <stdio.h>
#include <stdbool.h>

#define CONST 6

typedef struct Queue {
    int data[CONST];
    int rear;
    int front;
} Queue;

void init_Queue(Queue *q) {
    q->rear = q->front = -1;
}

bool is_empty(Queue *q) {
    return (q->front == -1);
}

bool is_full(Queue *q) {
    return ((q->rear + 1) % CONST == q->front);
}

bool enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue overflow\n");
        return false;
    }
    if (is_empty(q)) {
        q->front = q->rear = 0;  
    } else {
        q->rear = (q->rear + 1) % CONST;  
    }
    q->data[q->rear] = value;         
    return true;
}   

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int temp = q->data[q->front];    
    if (q->front == q->rear) {        
        q->front = q->rear = -1;      
    } else {                          
        q->front = (q->front + 1) % CONST; 
    }                                 
    return temp;
}

void display_queue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = q->front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % CONST;
    }
    printf("\n");
}

int main() {
    Queue q;
    init_Queue(&q);

    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 66);
    enqueue(&q, 77);
    enqueue(&q, 88);
    enqueue(&q, 99);
    enqueue(&q, 111);
    enqueue(&q, 222);

    display_queue(&q);

    return 0;
}
