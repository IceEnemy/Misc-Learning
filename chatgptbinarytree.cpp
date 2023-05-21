#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the maximum height of a binary tree
int maxHeight(struct Node* node) {
    if (node == NULL)
        return 0;

    int leftHeight = maxHeight(node->left);
    int rightHeight = maxHeight(node->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to print ASCII representation of a binary tree
void printBinaryTree(struct Node* root, int level, int isLeft) {
    if (root == NULL)
        return;

    printBinaryTree(root->right, level + 1, 0);

    int i;
    for (i = 0; i < level - 1; i++)
        printf("   ");

    if (level > 0) {
        if (isLeft)
            printf("  /-");
        else
            printf("  \\-");
    }

    printf("%d\n", root->data);

    printBinaryTree(root->left, level + 1, 1);
}

int main() {
    // Create the binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Calculate the maximum height of the binary tree
    int treeHeight = maxHeight(root);

    // Print the ASCII representation of the binary tree
    printBinaryTree(root, 0, 0);

    // Cleanup - free allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
