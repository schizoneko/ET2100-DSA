#include <stdio.h>
#include <string.h>

#define MAX 100

typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} Status;

typedef struct Process {
    int id;
    char name[100];
    Status status;
    int priority;
} Process;

typedef struct Node {
    Process data;
    Node* next;
} Node;

typedef struct ProcessList {
    Node* head;
    Node* tail;
} ProcessList;

void initList(ProcessList* list) {
    list->head = NULL;
    list->tail = NULL;
}

Node* createNode(Process process) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = process;
    newNode->next = NULL;
    return newNode;
}

void insertProcess(ProcessList* list, Process _data) {
    Node* newNode = createNode(_data);

    // List is empty or inserting at the beginning
    if(list->head == NULL || _data.priority < list->head->data.priority) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    // General case 
    Node* ptr = list->head;
    while(ptr != NULL && ptr->data.priority <= _data.priority) {
        ptr = ptr->next;
    }

    if(ptr != NULL){
        // Found the ptr->data has the higher priority than the newNode -> add it before the ptr
        newNode->data = ptr->data;
        ptr->data = _data;

        newNode->next = ptr->next;
        ptr->next = newNode;
    } else{
        // Insert at the end, at the moment ptr is NULL so we have to create another pointer to traverse through the list
        Node* p = list->head;
        while(p->next != NULL)
            p = p->next;
        p->next = newNode;        
    }
}

Node* findReadyHighestPriority(ProcessList* list) {
    Node* temp = list->head;
    Node* found = NULL;

    while(temp != NULL) {
        if(temp->data.status == READY) {
            if(found == NULL || found->data.priority > temp->data.priority) {
                found = temp;
            }
        }
        temp = temp->next;
    }
    return found;
}

void remove(ProcessList* list, Node* target) {
    if (list->head == NULL || target == NULL) return;

    // Target is the head
    if (list->head == target) {
        list->head = list->head->next;
        free(target);
        return;
    }

    // Traverse to find node before target
    Node* prev = list->head;
    while (prev->next != NULL && prev->next != target) {
        prev = prev->next;
    }

    // If found, remove it
    if (prev->next == target) {
        prev->next = target->next;
        free(target);
    }
}

void removeAllTerminated(ProcessList* list) {
    if (list->head == NULL) return;

    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data.status == TERMINATED) {
            Node* temp = current;
            if (prev == NULL) {
                // Removing head node
                list->head = current->next;
                current = list->head;
            } else {
                prev->next = current->next;
                current = current->next;
            }
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void displayList(ProcessList* list) {
    Node* temp = list->head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n%-5s %-15s %-10s %-10s\n", "ID", "Name", "Status", "Priority");
    while (temp != NULL) {
        printf("%-5d %-15s ", temp->data.id, temp->data.name);
        switch (temp->data.status) {
            case READY: printf("%-10s", "READY"); break;
            case RUNNING: printf("%-10s", "RUNNING"); break;
            case WAITING: printf("%-10s", "WAITING"); break;
            case TERMINATED: printf("%-10s", "TERMINATED"); break;
        }
        printf("%-10d\n", temp->data.priority);
        temp = temp->next;
    }
}

int main() {
    ProcessList list;
    initList(&list);

    Process p1 = {1, "Process1", READY, 2};
    Process p2 = {2, "Process2", WAITING, 5};
    Process p3 = {3, "Process3", READY, 1};
    Process p4 = {4, "Process4", TERMINATED, 4};
    Process p5 = {5, "Process5", TERMINATED, 3};

    insertProcess(&list, p1);
    insertProcess(&list, p2);
    insertProcess(&list, p3);
    insertProcess(&list, p4);
    insertProcess(&list, p5);

    printf("Process List:\n");
    displayList(&list);

    Node* ready = findReadyHighestPriority(&list);
    if (ready != NULL) {
        printf("\nHighest priority READY process: %s (Priority: %d)\n", ready->data.name, ready->data.priority);

        remove(&list, ready);

        printf("\nAfter removing highest priority READY process:\n");
        displayList(&list);
    }

    removeAllTerminated(&list);

    printf("\nAfter removing all TERMINATED processes:\n");
    displayList(&list);

    return 0;
}
