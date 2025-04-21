#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* build_tree(int arr[], int n) {
    Node* root = NULL;
    if (n == 0) return root;

    Node* queue[n];
    int front = 0, rear = 0;
    root = create_node(arr[0]);
    queue[rear++] = root;

    for (int i = 1; i < n;) {
        Node* current = queue[front++];
        
        current->left = create_node(arr[i++]);
        queue[rear++] = current->left;
        
        if (i < n) {
            current->right = create_node(arr[i++]);
            queue[rear++] = current->right;
        }
    }
    return root;
}

void pre_order(Node* root) {
    Node* stack[100];
    int top = -1;
    if (root != NULL) {
        stack[++top] = root;
    }

    while (top >= 0) {
        Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

void in_order(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        if (top >= 0) {
            current = stack[top--];
            printf("%d ", current->data);
            current = current->right;
        }
    }
}

void post_order(Node* root) {
    Node* stack[100], *output[100];
    int top = -1, outTop = -1;
    
    if (root != NULL) {
        stack[++top] = root;
    }

    while (top >= 0) {
        Node* node = stack[top--];
        output[++outTop] = node;

        if (node->left) stack[++top] = node->left;
        if (node->right) stack[++top] = node->right;
    }

    while (outTop >= 0) {
        printf("%d ", output[outTop--]->data);
    }
}

int height(Node* root) {
    if (root == NULL) return 0;
    
    Node* stack[100], *heightStack[100];
    int top = -1, heightTop = -1;
    stack[++top] = root;
    heightStack[++heightTop] = 1;
    
    int maxHeight = 0;

    while (top >= 0) {
        Node* node = stack[top];
        int currentHeight = heightStack[heightTop];
        top--;
        heightTop--;

        if (node != NULL) {
            maxHeight = currentHeight > maxHeight ? currentHeight : maxHeight;
            if (node->left) {
                stack[++top] = node->left;
                heightStack[++heightTop] = currentHeight + 1;
            }
            if (node->right) {
                stack[++top] = node->right;
                heightStack[++heightTop] = currentHeight + 1;
            }
        }
    }
    return maxHeight;
}

int sum(Node* root) {
    int total = 0;
    Node* stack[100];
    int top = -1;
    
    if (root != NULL) {
        stack[++top] = root;
    }

    while (top >= 0) {
        Node* node = stack[top--];
        total += node->data;

        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
    return total;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = build_tree(arr, n);

    printf("Pre-order traversal: ");
    pre_order(root);
    printf("\n");

    printf("In-order traversal: ");
    in_order(root);
    printf("\n");

    printf("Post-order traversal: ");
    post_order(root);
    printf("\n");

    printf("Height of the tree: %d\n", height(root));

    printf("Sum of all elements in the tree: %d\n", sum(root));

    return 0;
}
