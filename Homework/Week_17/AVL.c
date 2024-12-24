#include <stdio.h>   
#include <stdlib.h>  

// Define the structure of a node in the AVL tree
typedef struct AVLNode {
    int value;               // The value stored in the node
    int height;              // The height of the node
    struct AVLNode* leftChild;  // Pointer to the left child
    struct AVLNode* rightChild; // Pointer to the right child
} AVLNode;

// Function to create a new node
AVLNode* createNewNode(int value) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode)); // Allocate memory for a new node
    newNode->value = value;                              // Set the value of the new node
    newNode->height = 1;                                 // Initialize height as 1 (leaf node)
    newNode->leftChild = NULL;                           // Set the left child to NULL
    newNode->rightChild = NULL;                          // Set the right child to NULL
    return newNode;                                      // Return the newly created node
}

// Function to calculate the height of a node
int calcHeight(AVLNode* treeNode) {
    if (treeNode == NULL) {                              // Check if the node is NULL
        return 0;                                        // Height of a NULL node is 0
    }
    return treeNode->height;                             // Return the height of the node
}

// Function to calculate the balance factor of a node
int calcBalanceFactor(AVLNode* treeNode) {
    if (treeNode == NULL) {                              // Check if the node is NULL
        return 0;                                        // Balance factor of a NULL node is 0
    }
    return calcHeight(treeNode->leftChild) - calcHeight(treeNode->rightChild); // Calculate balance factor
}

// Function to perform a right rotation
AVLNode* performRightRotation(AVLNode* unbalancedNode) {
    printf("Performing right rotation at node %d\n", unbalancedNode->value); // Print rotation info
    AVLNode* newRoot = unbalancedNode->leftChild;        // Set the left child as the new root
    AVLNode* tempSubTree = newRoot->rightChild;          // Temporarily store the right subtree of the new root

    newRoot->rightChild = unbalancedNode;               // Set the unbalanced node as the right child of the new root
    unbalancedNode->leftChild = tempSubTree;            // Attach the temporarily stored subtree

    // Update the heights of the affected nodes
    unbalancedNode->height = 1 + (calcHeight(unbalancedNode->leftChild) > calcHeight(unbalancedNode->rightChild) ? calcHeight(unbalancedNode->leftChild) : calcHeight(unbalancedNode->rightChild));
    newRoot->height = 1 + (calcHeight(newRoot->leftChild) > calcHeight(newRoot->rightChild) ? calcHeight(newRoot->leftChild) : calcHeight(newRoot->rightChild));

    return newRoot;                                     // Return the new root after rotation
}

// Function to perform a left rotation
AVLNode* performLeftRotation(AVLNode* unbalancedNode) {
    printf("Performing left rotation at node %d\n", unbalancedNode->value); // Print rotation info
    AVLNode* newRoot = unbalancedNode->rightChild;       // Set the right child as the new root
    AVLNode* tempSubTree = newRoot->leftChild;           // Temporarily store the left subtree of the new root

    newRoot->leftChild = unbalancedNode;                // Set the unbalanced node as the left child of the new root
    unbalancedNode->rightChild = tempSubTree;           // Attach the temporarily stored subtree

    // Update the heights of the affected nodes
    unbalancedNode->height = 1 + (calcHeight(unbalancedNode->leftChild) > calcHeight(unbalancedNode->rightChild) ? calcHeight(unbalancedNode->leftChild) : calcHeight(unbalancedNode->rightChild));
    newRoot->height = 1 + (calcHeight(newRoot->leftChild) > calcHeight(newRoot->rightChild) ? calcHeight(newRoot->leftChild) : calcHeight(newRoot->rightChild));

    return newRoot;                                     // Return the new root after rotation
}

// Function to insert a new node into the AVL tree
AVLNode* addNodeToAVLTree(AVLNode* rootNode, int value) {
    if (rootNode == NULL) {                             // If the tree is empty, create a new node
        return createNewNode(value);                    // Return the new node as the root
    }

    if (value < rootNode->value) {                      // If the value is smaller, insert into the left subtree
        rootNode->leftChild = addNodeToAVLTree(rootNode->leftChild, value);
    } else if (value > rootNode->value) {               // If the value is larger, insert into the right subtree
        rootNode->rightChild = addNodeToAVLTree(rootNode->rightChild, value);
    } else {                                            // If the value already exists, do nothing
        return rootNode;                                // Return the current root
    }

    // Update the height of the current node
    rootNode->height = 1 + (calcHeight(rootNode->leftChild) > calcHeight(rootNode->rightChild) ? calcHeight(rootNode->leftChild) : calcHeight(rootNode->rightChild));

    // Calculate the balance factor to check for imbalance
    int balance = calcBalanceFactor(rootNode);

    // Perform rotations based on the balance factor
    if (balance > 1 && value < rootNode->leftChild->value) { // Left-Left case
        return performRightRotation(rootNode);
    }

    if (balance < -1 && value > rootNode->rightChild->value) { // Right-Right case
        return performLeftRotation(rootNode);
    }

    if (balance > 1 && value > rootNode->leftChild->value) { // Left-Right case
        rootNode->leftChild = performLeftRotation(rootNode->leftChild);
        return performRightRotation(rootNode);
    }

    if (balance < -1 && value < rootNode->rightChild->value) { // Right-Left case
        rootNode->rightChild = performRightRotation(rootNode->rightChild);
        return performLeftRotation(rootNode);
    }

    return rootNode;                                     // Return the updated root node
}

// Function to print the tree structure as a diagram
void printTreeStructure(AVLNode* rootNode, int spacing) {
    if (rootNode == NULL) {                              // If the node is NULL, return
        return;
    }

    spacing += 10;                                       // Increase spacing for the next level

    printTreeStructure(rootNode->rightChild, spacing);   // Print the right subtree

    printf("\n");                                        // Move to the next line
    for (int i = 10; i < spacing; i++) {                 // Add spaces for formatting
        printf(" ");
    }
    printf("%d\n", rootNode->value);                     // Print the value of the current node

    printTreeStructure(rootNode->leftChild, spacing);    // Print the left subtree
}

int main() {
    AVLNode* rootNode = NULL;                            // Initialize the root of the tree
    int elements[] = {10, 20, 30, 40, 50, 25};           // Array of elements to insert into the tree
    int size = sizeof(elements) / sizeof(elements[0]);   // Calculate the size of the array

    printf("Adding elements to the AVL Tree:\n");        // Print the operation being performed

    for (int i = 0; i < size; i++) {                     // Loop through all elements in the array
        rootNode = addNodeToAVLTree(rootNode, elements[i]); // Insert the element into the tree
        printf("\nAfter adding %d:\n", elements[i]);     // Print the current state of the tree
        printTreeStructure(rootNode, 0);                // Print the structure of the tree
    }

    return 0;                                            // End the program
}
