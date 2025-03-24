#ifndef EXTERNAL_FUNC_H
#define EXTERNAL_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* first;
    Node* last;
} List;

void init_list(List *list);
bool is_empty(List *list);
void sort_ascending(Node* head); 
void insert_list_at(List* list1, List* list2, int position);
void reverse_list(List* list);

#endif