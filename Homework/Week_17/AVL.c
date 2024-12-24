#include <stdio.h>
#include <stdlib.h>

// Cấu trúc của một node trong cây AVL
typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Hàm tạo một node mới
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1; // Chiều cao của node mới là 1
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Hàm lấy chiều cao của một node
int getHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Hàm tính hệ số cân bằng của một node
int getBalance(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Hàm xoay phải
AVLNode* rotateRight(AVLNode* y) {
    printf("Thực hiện xoay phải tại node %d\n", y->key);
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Hàm xoay trái
AVLNode* rotateLeft(AVLNode* x) {
    printf("Thực hiện xoay trái tại node %d\n", x->key);
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Hàm thêm một node mới vào cây AVL
AVLNode* insertNode(AVLNode* node, int key) {
    // Thực hiện chèn bình thường
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        return node; // Không cho phép giá trị trùng lặp
    }

    // Cập nhật chiều cao của node
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Kiểm tra hệ số cân bằng
    int balance = getBalance(node);

    // Trường hợp mất cân bằng
    // Trái - Trái
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }

    // Phải - Phải
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }

    // Trái - Phải
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Phải - Trái
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Hàm in cấu trúc cây theo dạng sơ đồ
void printTree(AVLNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;

    // In cây con phải trước
    printTree(root->right, space);

    // In node hiện tại
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    // In cây con trái
    printTree(root->left, space);
}

// Duyệt cây theo thứ tự Inorder
void inorderTraversal(AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    AVLNode* root = NULL;
    int elements[] = {10, 20, 30, 40, 50, 25};
    int size = sizeof(elements) / sizeof(elements[0]);

    printf("Quá trình thêm phần tử vào cây AVL:\n");

    for (int i = 0; i < size; i++) {
        root = insertNode(root, elements[i]);
        printf("Sau khi thêm %d:\n", elements[i]);

        printTree(root, 0); // In cấu trúc cây

        printf("Inorder: ");
        inorderTraversal(root);
        printf("\n\n");
    }

    return 0;
}
