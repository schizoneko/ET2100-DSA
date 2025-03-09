#include "../../inc/header.h"

typedef struct Node {
    int infor;
    struct Node* next;
} Node;

void init_List(Node **list) {
    *list = NULL;
}

bool isEmpty(Node *list) {
    return (list == NULL);
}

void insert_first(Node **list, int k) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->infor = k;

    if (isEmpty(*list)) {
        *list = newnode;
        newnode->next = NULL;
        return;
    }

    newnode->next = *list;
    *list = newnode;
}

void delete_first(Node **list) {
    if (*list == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = *list;  
    *list = (*list)->next;  
    free(temp);  

    printf("First node deleted successfully.\n");
}

void insert_before(Node **list, int k, Node* p) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->infor = k;

    if (isEmpty(*list)) {
        *list = newnode;
        newnode->next = NULL;
        return;
    }

    if (p == NULL) return;

    Node* temp = *list;
    while (temp != NULL && temp->next != p) {
        temp = temp->next;
        newnode->next = p;
        temp->next = newnode;
    }
}

void insert_before2(Node **list, int k, Node* p) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->infor = k;

    if (isEmpty(*list)) {
        *list = newnode;
        newnode->next = NULL;
        return;
    }

    if (p == NULL) return;
    newnode->infor = p->infor;
    newnode->next = p->next;
    p->next = newnode;
}

void display_list(Node *list) {
    if (isEmpty(list)) {
        printf("Empty!\n");
        return;
    }
    Node* temp = list;
    printf("The list's components:\n");
    while (temp != NULL) {
        printf("%d\n", temp->infor);
        temp = temp->next;
    }
}

void free_list(Node **list) {
    Node* current = *list;
    Node* next_node;

    while (current != NULL) {
        next_node = current->next; 
        free(current); 
        current = next_node; 
    }
    *list = NULL;
}

int main() {
    Node *l;
    init_List(&l);

    insert_first(&l, 11);
    insert_first(&l, 22);
    insert_first(&l, 33);
    insert_first(&l, 44);
    insert_first(&l, 55);

    display_list(l);
    free_list(&l);
    return 0;
}