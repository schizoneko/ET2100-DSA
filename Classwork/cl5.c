#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data; 
    Node *link;
} Node; //Tao node moi

typedef struct {
    Node *first; 
    Node *last;
} List; //Tao list moi

void init(List *list) { //Khởi tạo List sinh viên
    list->first = 0;    //NULL
    list->last = 0;   //NULL
}

void insert_Node(Node *T, int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->link = T->link;
    T->link = newnode;
}

void list_delete_last(List* list) {
    if (list->first == 0) {
        printf("list có cái nịt");
        return;
    }
    if (list->last == list->first) {
        free(list->first);
        list->first = 0;
        list->last = 0;
    }
    else {
        Node *cs = list->first;
        while (cs->link != list->last) {
            cs = cs->link;
        }
        free (list->last);
        list->last = cs;
        list->last->link = 0;
    }
}

void list_delete (List *list, Node *node) {
    if (list->first == 0) {
        printf("list có cái nịt");
        return;
    }
    if (list->first == node) {  
        list->first = node->next;
        free(list->first);
    }
    else {
        Node *cs = list->first;
        while (cs->link != list->last) {
            if (cs->link == node) {
                cs = node->next;
            }
            cs = cs->link;
        }
        free (list->last);
    }

}


int main() {

    return 0;
}