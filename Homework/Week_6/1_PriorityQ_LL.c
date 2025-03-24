#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* front;
} PriorityQueue;

void init(PriorityQueue* pq) {
    pq->front = NULL;
}

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->front == NULL;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* newNode = createNode(data, priority);

    // Nếu hàng đợi rỗng hoặc node mới có độ ưu tiên cao hơn (số nhỏ hơn)
    if (isEmpty(pq) || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node* current = pq->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued: %d (Priority %d)\n", data, priority);
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue underflow!\n");
        return -1;
    }
    Node* temp = pq->front;
    int data = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return data;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* current = pq->front;
    printf("Priority Queue: \n");
    while (current != NULL) {
        printf("Data: %d, Priority: %d\n", current->data, current->priority);
        current = current->next;
    }
}

int main() {
    PriorityQueue pq;
    init(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 5, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 20, 2);

    display(&pq);

    printf("\nDequeued: %d\n", dequeue(&pq));
    printf("\nAfter dequeue:\n");
    display(&pq);

    return 0;
}
