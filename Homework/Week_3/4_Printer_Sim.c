#include "../../inc/header.h"

typedef struct {
    string name;
    string content;
    float size;
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
        printf("Size: %f\n Mb", q->data[i].size);
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
        getchar(); // Clear the buffer, prevent errors

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                fgets(doc.name, sizeof(doc.name), stdin); // Note about fgets(char *str, int size, stdin): the pointer here will be place in the first element of array doc.name, and will read maximum size of it (including the \0) and will be read from stdin mode, which means from the user's keyboard
                //getchar(); => fgets will leaves the extra "\n" in the buffer that getchar() will took that so it will be error
                doc.name[strcspn(doc.name, "\n")] = '\0';
                // Here we use strcspn(doc.name, "\n") to traverse the array doc.name that not include the "\n" => it will find the first "\n"'s place 
                // After that we change the "\n" to "\0" => delete the newline that the extra "\n" in the buffer made

                printf("Enter document content: ");
                fgets(doc.content, sizeof(doc.content), stdin);
                //getchar();
                doc.content[strcspn(doc.content, "\n")] = '\0';

                printf("Enter document size: ");
                scanf("%f", &doc.size);
                getchar();

                if (DocQueue_enqueue(&printer_queue, doc))
                    printf("Document added successfully!\n");
                break;

            case 2:
                if (!DocQueue_empty(&printer_queue)) {
                    Document current_doc = DocQueue_dequeue(&printer_queue);
                    printf("\nPrinting Document:\n");
                    printf("Name: %s\nContent: %s\nSize: %f\n", current_doc.name, current_doc.content, current_doc.size);
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