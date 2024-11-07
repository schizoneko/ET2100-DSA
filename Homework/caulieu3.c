/*Cài đặt giải thuật để in ra 2 đa thức */


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float coef; //Hệ số
    int exp; //Số mũ
    Node *link;
} Node; //Tạo struct tên Node mới

typedef struct {
    Node *first; 
    Node *last;
} List; //Tao list moi

void init(List *list) { //Khởi tạo List 
    list->first = 0;    //NULL
    list->last = 0;   //NULL
}

Node* create_Node(float coef, int exp) {
    Node *newnode = (Node*)malloc(sizeof(Node)); //
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->link = NULL;
    return newnode;
} 

void insert_Node(List *list, float coef, int exp) {
    Node* newNode = createNode(coef, exp);
    if (list->first == NULL || list->first->exp < exp) {
        newNode->next = list->first;
        list->first = newNode;
        if (list->last == NULL) list->last = newNode;
    } else {
        Node* current = list->first;
        while (current->next != NULL && current->link->exp > exp) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == NULL) list->last = newNode;
    }
}




int main() {
    
    return 0;
}