#include <stdio.h>
#include <stdlib.h>

// Structure for tree nodes
typedef struct Node {
    char* value;        // Value (operator or operand)
    struct Node* left;  // Left child
    struct Node* right; // Right child
} Node;

// Function to create a new node
Node* createNode(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));

    // Duplicate string manually
    int len = 0;
    while (value[len] != '\0') len++;
    node->value = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i <= len; i++) {
        node->value[i] = value[i];
    }

    node->left = NULL;
    node->right = NULL;
    return node;
}

// Stack structure for nodes
typedef struct Stack {
    Node** items;   // Array of node pointers
    int top;        // Index of the top element
    int capacity;   // Maximum capacity of the stack
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->items = (Node**)malloc(capacity * sizeof(Node*));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push a node onto the stack
void push(Stack* stack, Node* node) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = node;
}

// Pop a node from the stack
Node* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Manual string comparison (returns 0 if equal)
int stringCompare(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) return *str1 - *str2;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Check if a string is an operator
int isOperator(const char* token) {
    return stringCompare(token, "+") == 0 || stringCompare(token, "-") == 0 ||
           stringCompare(token, "*") == 0 || stringCompare(token, "/") == 0 ||
           stringCompare(token, "^") == 0;
}

// Check if a string is a valid operand (number or variable)
int isOperand(const char* token) {
    if (*token == '\0') return 0; // Empty string is not valid

    // Check if it starts with a letter (variable like "a", "b")
    if ((*token >= 'a' && *token <= 'z') || (*token >= 'A' && *token <= 'Z')) {
        return 1;
    }

    // Check if it's a number
    char* endPtr;
    double value = strtod(token, &endPtr);
    return *endPtr == '\0';
}

// Build the expression tree from a postfix expression
Node* buildTree(char* postfix[], int size) {
    Stack* stack = createStack(size);

    for (int i = 0; i < size; ++i) {
        char* token = postfix[i];

        if (isOperand(token)) {
            push(stack, createNode(token));
        } else if (isOperator(token)) {
            Node* node = createNode(token);
            node->right = pop(stack); // Right child
            node->left = pop(stack);  // Left child
            push(stack, node);
        } else {
            printf("Invalid token: %s\n", token);
            exit(EXIT_FAILURE);
        }
    }

    Node* root = pop(stack);
    free(stack->items);
    free(stack);
    return root;
}

// Preorder traversal (prefix)
void preorder(Node* node) {
    if (node) {
        printf("%s ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

// Inorder traversal (infix)
void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        printf("%s ", node->value);
        inorder(node->right);
    }
}

// Postorder traversal (postfix)
void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%s ", node->value);
    }
}

// Free the memory allocated for the tree
void freeTree(Node* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node->value);
        free(node);
    }
}

int main() {
    // Postfix expression
    char* postfix[] = {"a", "5", "b", "c", "/", "+", "c", "8", "^", "-", "d", "e", "0.5", "^", "+"};
    int size = sizeof(postfix) / sizeof(postfix[0]);

    // Build the expression tree
    Node* root = buildTree(postfix, size);

    // Print traversals
    printf("Preorder (Tiền tố): ");
    preorder(root);
    printf("\n");

    printf("Inorder (Trung tố): ");
    inorder(root);
    printf("\n");

    printf("Postorder (Hậu tố): ");
    postorder(root);
    printf("\n");

    // Free the memory
    freeTree(root);

    return 0;
}
