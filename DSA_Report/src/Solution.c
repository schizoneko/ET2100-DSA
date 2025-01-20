#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node, and the DLL
struct Node {
    int data;
    struct Node* left;  // Left child in tree, or previous node in DLL
    struct Node* right; // Right child in tree, or next node in DLL
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    //malloc(sizeof(struct Node))` dynamically allocates memory for a new `Node` structure.
    //The returned pointer is cast to `(struct Node*)` to ensure type compatibility.

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    //Initialize the node

    return newNode; //Returns the address of the newly allocated and initialized node.
}

// Function to convert the binary tree to a doubly linked list using inorder traversal
void convertToDLL(struct Node* root, struct Node** head, struct Node** prev) {
    if (root == NULL) return;

    // Recursively convert the left subtree
    convertToDLL(root->left, head, prev);

    // Link the current node in the DLL
    if (*prev == NULL) {
        // If this is the first node, set it as the head of the DLL
        *head = root;
    } else {
        // Link the current node with the previous node in the DLL
        root->left = *prev;
        (*prev)->right = root;
    }
    *prev = root; // Update the prev pointer to the current node

    // Recursively convert the right subtree
    convertToDLL(root->right, head, prev);

    // See the external note below for details
}                                                                                               

// Function to print the doubly linked list in forward direction
void printDLL(struct Node* head) {
    printf("Doubly Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    struct Node* head = NULL; // Head of the DLL
    struct Node* prev = NULL; // Previous pointer for DLL

    // Convert the binary tree to a doubly linked list
    convertToDLL(root, &head, &prev);

    // Print the doubly linked list
    printf("Converted Doubly Linked List:\n");
    printDLL(head);                                                                                              

    return 0;
}
/* 
 * External note:
 *
 * Why Recursion is Used in This Problem?
 * In the convertToDLL function, I used recursion for traversing the binary tree
 * in **inorder traversal** (Left -> Root -> Right) and simultaneously converting
 * the binary tree nodes into a doubly linked list (DLL) by reusing their left and right pointers.
 *
 * 1. Recursive Approach:
 *    - Recursion naturally fits the structure of a binary tree, where each subtree
 *      can be treated as a smaller binary tree.
 *    - We use **inorder traversal** (Left -> Root -> Right) to process nodes in the
 *      correct order for creating a sorted Doubly Linked List (DLL).
 *
 * 2. How Recursion Works:
 *    - The function `convertToDLL` recursively:
 *      a. Processes the left subtree.
 *      b. Links the current node to the previous node (`prev`).
 *      c. Processes the right subtree.
 *
 * 3. Example Walkthrough (Binary Tree):
 *             10
 *           /    \
 *         5       20
 *       /   \    /   \
 *      3     8  15   25
 *
 *    - Steps:
 *      a. Start at the root (10), recursively move to the leftmost node (3).
 *      b. Link 3 as the first node in the DLL.
 *      c. Move back to 5, link 5 to 3, and continue to 8.
 *      d. Process 10 and move to the right subtree (20).
 *      e. Continue linking 15, 20, and 25 to complete the DLL.
 *
 *    - Resulting DLL:
 *      3 <-> 5 <-> 8 <-> 10 <-> 15 <-> 20 <-> 25