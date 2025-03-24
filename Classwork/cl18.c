#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CLL {
    Node* last;
} CLL;

void init_CircleLL(CLL *cl) {
    cl->last = NULL;
}

bool is_empty(CLL *cl) {
    return(cl->last == NULL);
}

Node* create_Node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_Begin(CLL *cl, int data) {
    Node* newNode = create_Node(data);
    if(cl->last == NULL) {
        cl->last = newNode;
        cl->last->next = newNode;
        return;
    }

    newNode->next = cl->last->next;
    cl->last->next = newNode;
}

void display_CircleLL(CLL *cl) {
    if(is_empty(cl)) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = cl->last->next;
    printf("Data in CircleLL: ");
    while(temp != cl->last) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d", cl->last->data);
}

int main() {
    CLL cl;
    init_CircleLL(&cl);

    insert_Begin(&cl, 11);
    insert_Begin(&cl, 22);
    insert_Begin(&cl, 33);
    insert_Begin(&cl, 44);
    insert_Begin(&cl, 55);

    display_CircleLL(&cl);

    return 0;
}