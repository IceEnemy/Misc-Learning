#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int val;
    char color;
    struct Node *left, *right, *parent;
};

struct Node *addNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->color = 'R';
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

char getColor(struct Node *curr) {
    if (curr == NULL) return 'B';
    else return curr->color;
}

void leftRotate(struct Node **root, struct Node *parent) {
    struct Node *child = parent->right;

    parent->right = child->left;
    if(child->left != NULL) child->left->parent = parent;

    child->parent = parent->parent;
    
    if(parent->parent == NULL) *root = child;
    else if(parent == parent->parent->left) parent->parent->left = child;
    else parent->parent->right = child;

    child->left = parent;
    parent->parent = child;
}

void rightRotate(struct Node **root, struct Node *parent) {
    struct Node *child = parent->left;

    parent->left = child->right;
    if(child->right != NULL) child->right->parent = parent;

    child->parent = parent->parent;
    
    if(parent->parent == NULL) *root = child;
    else if(parent == parent->parent->left) parent->parent->left = child;
    else parent->parent->right = child;

    child->right = parent;
    parent->parent = child;
}

void repair(struct Node **root, struct Node *curr) {
    while (curr->parent != NULL && curr->parent->color == 'R') {
        struct Node *parent = curr->parent;
        struct Node *grand = parent->parent;
        struct Node *uncle;
        
        if(parent == grand->left) uncle = grand->right;
        else uncle = grand->left;
        
        if(getColor(uncle) == 'R'){
        	parent->color = uncle->color = 'B';
        	grand->color = 'R';
        	curr = grand;
		}
		else{
			if(parent == grand->left){
				if(curr == parent->right){
					curr = parent;
					leftRotate(root,curr);	
				}
				
				parent = curr->parent;
                grand = parent->parent;

                parent->color = 'B';
                grand->color = 'R';
                rightRotate(root, grand);
			}
			else{
				if(curr == parent->left){
					curr = parent;
					rightRotate(root,curr);	
				}
				
				parent = curr->parent;
                grand = parent->parent;

                parent->color = 'B';
                grand->color = 'R';
                leftRotate(root, grand);
			}
		}
	}
    (*root)->color = 'B';
}

void insert(struct Node **root, int val){
    struct Node *parent = NULL;
    struct Node *curr = *root;

    while(curr != NULL){
        parent = curr;
        if(val < curr->val) curr = curr->left;
        else if(val > curr->val) curr = curr->right;
        else{
            printf("Duplicate Value!\n");
            return;
        }
    }
    
    struct Node *newNode = addNode(val);

    newNode->parent = parent;

    if(parent == NULL) *root = newNode;
	else if(val < parent->val) parent->left = newNode;
	else parent->right = newNode;

    repair(root, newNode);
}

void inOrder(struct Node *curr){
    if(curr != NULL){
        inOrder(curr->left);
        printf("%d ", curr->val);
        inOrder(curr->right);
    }
}


int main() {
    struct Node *root = NULL;
//	int val;
//	while(val != -1){
//		scanf("%d",&val);
//		insert(&root,val);
//		inOrder(root);
//		print(root);
//	}
	insert(&root,41);
	insert(&root,22);
	insert(&root,5);
	insert(&root,51);
	insert(&root,48);
	insert(&root,29);
	insert(&root,18);
	insert(&root,21);
	insert(&root,45);
	insert(&root,3);
	
	printf("InOrder Traversal of Created Tree\n");
	inOrder(root);
	
    return 0;
}

