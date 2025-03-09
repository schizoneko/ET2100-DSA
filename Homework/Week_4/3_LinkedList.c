#include "../../inc/header.h"

typedef struct Node {
    int infor;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

void init_List(List *l) {
    l->head = NULL;
}

bool isEmpty(List *l) {
    return (l->head == NULL);
}

void insert_first(List *l, int k) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->infor = k;

    if (isEmpty(l)) {
        l->head = newnode;
        newnode->next = NULL;
        return;
    }

    newnode->next = l->head;
    l->head = newnode;
}

void delete_first(List *l) {
    if (l->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = l->head;  
    l->head = (l->head)->next;  
    free(temp);  

    printf("First node deleted successfully.\n");
}

Node* search(List* l, int k) {
    Node* temp = l->head;
    while (temp != NULL) {
        if (temp->infor == k) return temp;
        temp = temp->next;
    }
    return NULL;
}

void insert_before(List *l, int k, Node* p) {
    if (p == NULL) return;

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->infor = k;

    if (l->head == p) { 
        insert_first(l, k);
        return;
    }

    if (isEmpty(l)) {
        l->head = newnode;
        newnode->next = NULL;
        return;
    }

    Node* temp = l->head;
    while (temp != NULL && temp->next != p) {
        temp = temp->next;
    }

    if (temp->next == p) {
        newnode->next = p;
        temp->next = newnode;
    } else {
        printf("Node not found!\n");
    }
}

void insert_before2(List* l, Node* p, int k) {
    if (l->head == NULL || p == NULL) return;

    if (l->head == p) {
        insert_first(l, k);
        return;
    }

    Node* temp = l->head;
    while (temp->next != NULL && temp->next != p) {
        temp = temp->next;
    }

    if (temp->next == p) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        
        newNode->infor = k;
        newNode->next = p;
        temp->next = newNode;
    } else {
        printf("No node\n");
    }
}

void insert_after(Node* p, int k) {
    if (p == NULL) {
        printf("Given node is NULL, insertion failed!\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->infor = k;
    newNode->next = p->next;
    p->next = newNode;
}

void display_list(List* l) {
    if (isEmpty(l)) {
        printf("Empty list!\n");
        return;
    }

    Node* temp = l->head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->infor);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_list(List* l) {
    Node* temp;
    while (l->head != NULL) {
        temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}

double average(List* l) {
    if (isEmpty(l)) return 0.0;

    int sum = 0, count = 0;
    Node* temp = l->head;
    while (temp != NULL) {
        sum += temp->infor;
        count++;
        temp = temp->next;
    }
    return (double)sum / count;
}

int main() {
    List l;
    init_List(&l);

    insert_first(&l, 10);
    insert_first(&l, 20);
    insert_first(&l, 30);
    insert_first(&l, 40);
    insert_first(&l, 50);

    display_list(&l);

    Node* found = search(&l, 30);
    if (found) {
        printf("Node with value 30 found.\n");
        insert_after(found, 35);
        insert_before(&l, 25, found);
        
    }

    display_list(&l);
    printf("Average value: %.2f\n", average(&l));

    free_list(&l);
    return 0;
}