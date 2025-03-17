#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Linked List

#define MAX 100

typedef struct SinhVien {
    long studID; 
    char name[MAX]; 
    char class[MAX];
} SinhVien; 

typedef struct Node {
    SinhVien data; 
    struct Node *next;
} Node;

typedef struct List {
    Node *first; 
    Node *last;
} List;

void init_List(List *l) {
    l->first = NULL;
    l->last = NULL;
}

Node* create_Node(SinhVien sv) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
} 

bool is_empty(List *l) {
    return(l->first == NULL);
}

void insert_First(List* l, SinhVien sv) {
    Node* newNode = create_Node(sv);
    if(is_empty(l)) {
        l->first = l->last = newNode;
    } else {
        newNode->next = l->first;
        l->first = newNode;
    }
}

void insert_Last(List *l, SinhVien sv) {
    Node* newNode = create_Node(sv);
    if(is_empty(l)) {
        l->first = l->last = newNode;
    } else {
        l->last->next = newNode;
        l->last = newNode;
    }
}

void insert_Before(List *l, Node*p, SinhVien sv) {
    if (p == NULL) {
        printf("Given node is NULL!\n");
        return;
    }

    Node* newNode = create_Node(sv);

    if (l->first == p) {
        newNode->next = l->first;
        l->first = newNode;
        return;
    }

    Node* temp = l->first;

    while (temp != NULL && temp->next != p) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = p;
        temp->next = newNode;
    } else {
        free(newNode); 
        printf("Node not found in the list!\n");
    }
}

void insert_After(Node* p, SinhVien sv) {
    if (p == NULL) {
        printf("Given node is NULL!\n");
        return;
    }
    Node* newNode = create_Node(sv);
    newNode->next = p->next;
    p->next = newNode;
}

Node* search(List* l, long mssv) {
    Node* temp = l->first;
    while(temp != NULL) {
        if(temp->data.studID == mssv){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


SinhVien input_Student() {
    SinhVien sv;
    
    printf("Enter Student ID (MSSV): ");
    scanf("%ld", &sv.studID);
    
    printf("Enter Full Name: ");
    getchar(); // Clear buffer
    fgets(sv.name, sizeof(sv.name), stdin);
    sv.name[strcspn(sv.name, "\n")] = '\0';
    
    printf("Enter Class: ");
    fgets(sv.class, sizeof(sv.class), stdin);
    sv.class[strcspn(sv.class, "\n")] = '\0';
    
    return sv;
}

void input_List(List *l) {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter student %d details:\n", i + 1);
        SinhVien sv = input_Student();
        insert_Last(l, sv); 
    }
}

void display_List(List* l) {
    if (is_empty(l)) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = l->first;
    printf("\nStudent List:\n");
    while (temp != NULL) {
        printf("\nMSSV: %ld", temp->data.studID);
        printf("\nName: %s", temp->data.name);
        printf("\nYear: %s\n", temp->data.class);
        temp = temp->next;
    }
}

void free_List(List* l) {
    Node* temp;
    while (l->first != NULL) {
        temp = l->first;
        l->first = l->first->next;
        free(temp);
    }
}

int main() {
    List l;
    init_List(&l);
    
    input_List(&l);  
    
    printf("\nStudent List:\n");
    display_List(&l); 

    long searchID;
    printf("\nEnter Student ID to search: ");
    scanf("%ld", &searchID);
    
    Node* found = search(&l, searchID);
    if (found) {
        printf("Student with ID %ld found.\n", searchID);
    } else {
        printf("Student not found.\n");
    }

    free_List(&l);
    return 0;
}