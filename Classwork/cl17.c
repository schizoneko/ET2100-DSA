#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DLL {
    Node* l;
    Node* r;
} DLL;

void init_DoubleLL(DLL *dl) {
    dl->l = dl->r = NULL;
}

bool is_empty(DLL *dl) {
    return(dl->l == NULL);
}

Node* create_Node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insert_Begin(DLL *dl, int data) {
    Node* newNode = create_Node(data);
    if(is_empty(dl)) {
        dl->l = dl->r = newNode;
    } else {
        newNode->next = dl->l;
        dl->l->prev = newNode;
        dl->l = newNode;
    }
}

void insert_After(DLL *dl, int data, Node* p) {
    if(is_empty(dl)) {
        printf("List is empty!\n");
        return;
    }

    if(p == NULL) {
        printf("Given node is NULL!\n");
        return;
    }

    Node* newNode = create_Node(data);

    newNode->next = p->next;
    newNode->prev = p;

    if(p->next == NULL) {
        dl->r = newNode;
    } else {
        p->next->prev = newNode;
    }   

    p->next = newNode;
}

void insert_Before(DLL *dl, int data, Node* p) {
    if(is_empty(dl)) {
        printf("List is empty!\n");
        return;
    }

    if(p == NULL) {
        printf("Given node is NULL!\n");
        return;
    }

    Node* newNode = create_Node(data);
    
    if(p == dl->l) {
        newNode->next = dl->l;
        dl->l->prev = newNode;
        dl->l = newNode;
        return;
    }
}

Node* search(DLL* dl, int data) {
    if(is_empty(dl)) {
        printf("List is empty!\n");
        return NULL;
    }
    Node* temp = dl->l;
    while(temp != NULL) {
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void delete_Begin(DLL *dl) {
    if(is_empty(dl)) {
        printf("List is empty!\n");
        return;
    }
    if(!is_empty(dl) && dl->l == dl->r) {
        free(dl->l);
        dl->l = dl->r = NULL;
        return;
    }
    Node* temp = dl->l;
    dl->l = temp->next;
    dl->l->prev = NULL;
    free(temp);
}

void delete_Current(DLL *dl, Node *p) {
    if (is_empty(dl)) {
        printf("List is empty!\n");
        return;
    }

    if (p == NULL) {
        printf("Given node is NULL!\n");
        return;
    }

    if(!is_empty(dl) && dl->l == dl->r && p == dl->l) { // Danh sách k rỗng, chỉ có 1 ptu và = p
        free(dl->l);
        dl->l = dl->r = NULL;
        return;
    }

    // p is the first node 
    if(p == dl->l) {
        dl->l = dl->l->next;
        dl->l->prev = NULL;
        free(p);
    }

    // p is the last node
    if (p == dl->r) {
        dl->r = dl->r->prev;
        dl->r->next = NULL;
        free(p);
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

void display_DoubleLL(DLL* dl) {
    if(is_empty(dl)) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = dl->l;
    printf("\nData in DoubleLL:\n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main() {
    DLL dl;
    init_DoubleLL(&dl);

    insert_Begin(&dl, 11);
    insert_Begin(&dl, 22);
    insert_Begin(&dl, 33);
    insert_Begin(&dl, 44);
    insert_Begin(&dl, 55);

    display_DoubleLL(&dl);

    Node* temp = search(&dl, 22);
    insert_After(&dl, 66, temp);
    insert_Before(&dl, 77, temp);
    display_DoubleLL(&dl);

    delete_Begin(&dl);
    display_DoubleLL(&dl);

    return 0;
}