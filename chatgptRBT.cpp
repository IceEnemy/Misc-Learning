#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int data;
    enum Color color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always red in a Red-Black Tree
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function declarations
struct Node* insert(struct Node* root, int data);
void fixViolation(struct Node** root, struct Node* node);
void rotateLeft(struct Node** root, struct Node* node);
void rotateRight(struct Node** root, struct Node* node);
void inorderTraversal(struct Node* root);

// Function to perform a left rotation
void rotateLeft(struct Node** root, struct Node* node) {
    struct Node* rightChild = node->right;
    node->right = rightChild->left;

    if (node->right != NULL)
        node->right->parent = node;

    rightChild->parent = node->parent;

    if (node->parent == NULL)
        *root = rightChild;
    else if (node == node->parent->left)
        node->parent->left = rightChild;
    else
        node->parent->right = rightChild;

    rightChild->left = node;
    node->parent = rightChild;
}

// Function to perform a right rotation
void rotateRight(struct Node** root, struct Node* node) {
    struct Node* leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != NULL)
        node->left->parent = node;

    leftChild->parent = node->parent;

    if (node->parent == NULL)
        *root = leftChild;
    else if (node == node->parent->left)
        node->parent->left = leftChild;
    else
        node->parent->right = leftChild;

    leftChild->right = node;
    node->parent = leftChild;
}

// Function to fix violations in the Red-Black Tree
void fixViolation(struct Node** root, struct Node* node) {
    struct Node* parent = NULL;
    struct Node* grandparent = NULL;

    while ((node != *root) && (node->color != BLACK) && (node->parent->color == RED)) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            struct Node* uncle = grandparent->right;

            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeft(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateRight(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        } else {
            struct Node* uncle = grandparent->left;

            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateLeft(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        }
    }

    (*root)->color = BLACK; // Root should always be black
}

// Function to insert a node into the Red-Black Tree
struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    if (root == NULL) {
        newNode->color = BLACK; // First node inserted should be black
        return newNode;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else {
            // Duplicate value, do not insert
            free(newNode);
            return root;
        }
    }

    newNode->parent = parent;

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    fixViolation(&root, newNode);
    return root;
}

// Function to perform in-order traversal of the Red-Black Tree
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    int op, val;

    while (op != 3) {
        system("cls");
        printf("------|RED-BLACK TREE|------\n");
        printf("1. Insertion\n");
        printf("2. Traversal\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                printf("Insert: ");
                scanf("%d", &val);
                getchar();
                root = insert(root, val);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Thank you!\n");
                break;
            default:
                printf("Unknown Command, Try again!\n");
                break;
        }

        if (op != 3) {
            printf("\nPress Enter to Continue...");
            getchar();
        }
    }

    return 0;
}

