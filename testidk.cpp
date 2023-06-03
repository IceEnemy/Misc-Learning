#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    char color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = 'R';
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(struct Node** root, struct Node* node) {
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

// Function to perform right rotation
void rightRotate(struct Node** root, struct Node* node) {
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

// Function to fix the 'R'-'B' Tree after insertion
void fixInsert(struct Node** root, struct Node* node) {
    if (node->parent == NULL) {
        node->color = 'B';
        *root = node;
        return;
    }

    if (node->parent->color == 'B')
        return;

    struct Node* grandparent = node->parent->parent;
    struct Node* parent = node->parent;
    struct Node* uncle = NULL;

    if (parent == grandparent->left)
        uncle = grandparent->right;
    else
        uncle = grandparent->left;

    if (uncle != NULL && uncle->color == 'R') {
        parent->color = 'B';
        uncle->color = 'B';
        grandparent->color = 'R';
        fixInsert(root, grandparent);
    } else {
        if (parent == grandparent->left && node == parent->right) {
            leftRotate(root, parent);
            node = parent;
            parent = node->parent;
        } else if (parent == grandparent->right && node == parent->left) {
            rightRotate(root, parent);
            node = parent;
            parent = node->parent;
        }

        if (parent == grandparent->left)
            rightRotate(root, grandparent);
        else
            leftRotate(root, grandparent);

        parent->color = 'B';
        grandparent->color = 'R';
    }
}

// Function to insert a node into the 'R'-'B' Tree
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        (*root)->color = 'B';
        return;
    }

    struct Node* curr = *root;
    struct Node* parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (data < parent->data) {
        parent->left = newNode;
        newNode->parent = parent;
    } else {
        parent->right = newNode;
        newNode->parent = parent;
    }

    fixInsert(root, newNode);
}

// Function to print the 'R'-'B' Tree (in-order traversal)
void inOrderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}

void printTree(struct Node *root, int tabs, char arrow[]){
	if(root == NULL){
		return;
	}
	printTree(root->right,tabs+1,"/->");
	for(int i=0;i<tabs;i++){
		printf("\t");
	}
	if(root->color == 'B') printf("%s%d(B)\n",arrow,root->data);
	else printf("%s%d(R)\n",arrow,root->data);
	printTree(root->left,tabs+1,"\\->");
}

void print(Node *root){
	printf("\n================================================\n\n");
	printTree(root,0,"-) ");
	printf("\n================================================\n");
}

// Main function
int main() {
    struct Node* root = NULL;
    insert(&root, 10);
    print(root);
    getchar();
    insert(&root, 20);
    print(root);
    getchar();
    insert(&root, 30);
    print(root);
    getchar();
    insert(&root, 15);
    print(root);
    getchar();
    insert(&root, 13);
    print(root);
    getchar();
    insert(&root, 5);
    print(root);
    getchar();
    insert(&root, 25);
    print(root);
    getchar();
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");
    print(root);
    return 0;
}

