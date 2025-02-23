#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    float data[MAX];
    int size;
} List;

void list_init(List *l) {
    l->size = 0;
}

bool is_empty(List *l) {
    return l->size == 0;
}

bool is_full(List *l) {
    return l->size == MAX;
}

bool insert(List *l, float val, int pos) {
    if (is_full(l)) {
        printf("List is full.\n");
        return false;
    }
    if (pos < 0 || pos > l->size) {
        printf("Invalid position. Allowed range: 0 to %d\n", l->size);
        return false;
    }

    for (int i = l->size; i > pos; i--) {
        l->data[i] = l->data[i - 1];
    }

    l->data[pos] = val;
    l->size++;
    return true;
}

bool delete(List *l, int pos) {
    if (is_empty(l)) {
        printf("List is empty.\n");
        return false;
    }
    if (pos < 0 || pos >= l->size) {
        printf("Invalid position. Allowed range: 0 to %d\n", l->size - 1);
        return false;
    }

    for (int i = pos; i < l->size - 1; i++) {
        l->data[i] = l->data[i + 1];
    }

    l->size--;
    return true;
}

void display_list(List *l) {
    if (is_empty(l)) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    for (int i = 0; i < l->size; i++) {
        printf("%.2f ", l->data[i]);
    }
    printf("\n");
}

int main() {
    List new_list;
    list_init(&new_list);

    insert(&new_list, 10.5f, 0);
    insert(&new_list, 20.2f, 1);
    insert(&new_list, 30.8f, 2);
    insert(&new_list, 15.3f, 1);

    display_list(&new_list); 

    delete(&new_list, 2);
    display_list(&new_list); 

    return 0;
}
