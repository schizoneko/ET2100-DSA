#include "external_func.h"

void init_list(List *list) {
    list->first = NULL;
    list->last = NULL;
}

bool is_empty(List *list) {
    return list->first == NULL;
}

void sort_list_ascending(List* list) {
    if (list->first == NULL) return;
    for (Node* i = list->first; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void insert_list_at(List *list1, List *list2, int position) {
    if (is_empty(list2)) return;
    if (position == 0) {
        list2->last->next = list1->first;
        list1->first = list2->first;

        if (list1->last == NULL) {
            list1->last = list2->last;
        }

        list2->first = list2->last = NULL;
    }
    
    Node* temp = list1->first;
    int index = 0;
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index += 1;
    }
    if (temp != NULL) {
        list2->last->next = temp->next;
        temp->next = list2->first;
        if (list2->last->next == NULL) list1->last = list2->last;
        list2->first = list2->last = NULL;
    }    
}

void reverse_list(List* list) {
    Node *prev = NULL, *current = list->first, *next = NULL;
    list->last = list->first;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->first = prev;
}

