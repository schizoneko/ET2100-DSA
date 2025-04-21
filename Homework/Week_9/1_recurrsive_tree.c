#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* build_tree(int arr[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node* root = create_node(arr[mid]);
    root->left = build_tree(arr, start, mid - 1);
    root->right = build_tree(arr, mid + 1, end);
    return root;
}

void pre_order(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node* root) {
    if (root == NULL) return;
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

void post_order(Node* root) {
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}

int height(Node* root) {
    if (root == NULL) return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

int sum(Node* root) {
    if (root == NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = build_tree(arr, 0, n - 1);

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
