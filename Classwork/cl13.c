#include "../inc/header.h"

typedef struct {
    string name;
    string content;
} Document;

DECLARE_QUEUE(Document, DocQueue)

void display_queue(DocQueue *q) {
    if (DocQueue_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\n--- Current Print Queue ---\n");
    int i = q->front;
    while (1) {
        printf("Document Name: %s\n", q->data[i].name);
        printf("Content: %s\n", q->data[i].content);
        printf("---------------------\n");

        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
}
int main() {
    DocQueue printer_queue;
    DocQueue_init(&printer_queue);

    int choice;
    Document doc;

    do {
        printf("\n---- PRINTER SIMULATOR ----\n");
        printf("1. Add document\n");
        printf("2. Print document\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                fgets(doc.name, sizeof(doc.name), stdin);
                doc.name[strcspn(doc.name, "\n")] = '\0';

                printf("Enter document content: ");
                fgets(doc.content, sizeof(doc.content), stdin);
                doc.content[strcspn(doc.content, "\n")] = '\0';

                if (DocQueue_enqueue(&printer_queue, doc))
                    printf("Document added successfully!\n");
                break;

            case 2:
                if (!DocQueue_empty(&printer_queue)) {
                    Document current_doc = DocQueue_dequeue(&printer_queue);
                    printf("\nPrinting Document:\n");
                    printf("Name: %s\nContent: %s\n", current_doc.name, current_doc.content);
                    printf("...Done Printing!\n");
                } else {
                    printf("No documents to print.\n");
                }
                break;

            case 3:
                display_queue(&printer_queue);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}