#ifndef QUEUE_H
#define QUEUE_H

#define DECLARE_QUEUE(type, typename) \
typedef struct {                      \
    type data[MAX];                   \
    int front;                        \
    int rear;                         \
} typename;                           \
                                      \
void typename##_init(typename *q) {   \
    q->front = q->rear = -1;          \
}                                     \
                                      \
bool typename##_empty(typename *q) {  \
    return (q->front == -1);          \
}                                     \
                                      \
bool typename##_full(typename *q) {   \
    return ((q->rear + 1) % MAX == q->front); \
}                                     \
                                      \
bool typename##_enqueue(typename *q, type value) { \
    if (typename##_full(q)) {         \
        printf("Queue overflow!\n");  \
        return false;                 \
    }                                 \
    if (typename##_empty(q)) {        \
        q->front = 0;                 \
    }                                 \
    q->rear = (q->rear + 1) % MAX;    \
    q->data[q->rear] = value;         \
    return true;                      \
}                                     \
                                      \
type typename##_dequeue(typename *q) { \
    if (typename##_empty(q)) {        \
        printf("Queue underflow!\n"); \
        exit(1);                      \
    }                                 \
    type temp = q->data[q->front];    \
    if (q->front == q->rear) {        \
        q->front = q->rear = -1;      \
    } else {                          \
        q->front = (q->front + 1) % MAX; \
    }                                 \
    return temp;                      \
}                                     \
                                      \
type typename##_peek(typename *q) {   \
    if (typename##_empty(q)) {        \
        printf("Queue is empty!\n");  \
        exit(1);                      \
    }                                 \
    return q->data[q->front];         \
}

#endif // QUEUE_H
