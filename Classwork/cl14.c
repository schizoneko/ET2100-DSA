#include "../inc/header.h"

typedef struct Node {
    int infor;
    struct Node* next;
} Node;

//typedef Node* PNode;
typedef Node* LinkedList;

void init_List(LinkedList *list) {
    *list = NULL;
}

bool isEmpty(LinkedList list) {
    return (list == NULL);
}

void insert_first(LinkedList* list, int k) {
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

void delete_first(LinkedList *list) {
    if (*list == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = *list;  
    *list = (*list)->next;  
    free(temp);  

    printf("First node deleted successfully.\n");
}

void insert_before(LinkedList *list, int k, Node* p) {
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

void insert_before2(LinkedList* list, int k, Node* p) {
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

void display_list(LinkedList list) {
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

void delete_end(LinkedList *l) {
    if(isEmpty(*l)) {
        printf("Queue is empty.\n");
        return;
    }

    if((*l)->next == NULL) {
        free(*l);
        (*l) == NULL;
        return;
    }



} 

void delete_current(LinkedList *l, Node* p) {
    if(isEmpty(*l)) {
        printf("Queue is empty.\n");
        return;
    }

    if(p == NULL) {
        printf("Node not exist.\n");
        return;
    }
    
    if(p == *l && *l->next == NULL) {
        free(p);
        *l = NULL;
    }

    Node* ptr = *l;
    while(ptr->next->next != p) {
        ptr = ptr->next;
    }
    ptr->next = p->next;
    free(p);
}

void free_list(LinkedList *list) {
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
    LinkedList l;
    init_List(&l);

    insert_first(&l, 11);
    insert_first(&l, 22);
    insert_first(&l, 33);
    insert_first(&l, 44);
    insert_first(&l, 55);

    display_list(l);
    free free_list(&l);
    return 0;
}