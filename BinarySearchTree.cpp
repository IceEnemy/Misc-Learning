#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *left;
	struct Node *right;
};

struct Node *root = NULL;

struct Node *addNode(int val){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->value = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void insert(int val){
	if(root == NULL){
		struct Node *newNode = addNode(val);
		root = newNode;
		printf("%d inserted into Binary Search Tree!\n",val);
	}
	else{
		struct Node *curr = root;
		while(1){
			if(val == curr->value){
				printf("Value already inside Binary Search Tree!\n");
				return;
			}
			else if(val < curr->value){
				if(curr->left == NULL){
					struct Node *newNode = addNode(val);
					curr->left = newNode;
					printf("%d inserted into Binary Search Tree!\n",val);
					return;
				}
				curr = curr->left;
			}
			else if(val > curr->value){
				if(curr->right == NULL){
					struct Node *newNode = addNode(val);
					curr->right = newNode;
					printf("%d inserted into Binary Search Tree!\n",val);
					return;
				}
				curr = curr->right;
			}
		}
	}
}

void search(int val){
	struct Node *temp = root;
	while(temp != NULL){
		if(temp->value == val){
			printf("Value Found in Binary Search Tree!\n");
			return;
		}
		else if(val > temp->value) temp = temp->right;
		else temp = temp->left;
	}
	printf("Value Not Found in Binary Search Tree!\n");
}

void del(int val){
    struct Node *curr = root;
    struct Node *parent = NULL;
    
    while(curr != NULL && curr->value != val){
        parent = curr;
        if(val < curr->value) curr = curr->left;
        else curr = curr->right;
    }
    if(curr == NULL){
        printf("Value Not Found in Binary Search Tree!\n");
        return;
    }
    if(curr->left == NULL && curr->right == NULL){
        if(parent == NULL) root = NULL;
        else{
            if(parent->left == curr) parent->left = NULL;
            else parent->right = NULL;
        }
        free(curr);
        printf("%d deleted from Binary Search Tree!\n",val);    
    }
    else if(curr->left == NULL){
        if(parent == NULL) root = curr->right;
        else{
            if(parent->left == curr) parent->left = curr->right;
            else parent->right = curr->right;
        }
        free(curr);
        printf("%d deleted from Binary Search Tree!\n",val);
    }
    else if(curr->right == NULL){
        if(parent == NULL) root = curr->left;
        else{
            if(parent->left == curr) parent->left = curr->left;
            else parent->right = curr->left;
        }
        free(curr);
        printf("%d deleted from Binary Search Tree!\n",val);
    }
    else{
        struct Node *temp = curr->right;
        struct Node *tempParent = curr;
        while(temp->left != NULL){
            tempParent = temp;
            temp = temp->left;
        }
        if(tempParent != curr){
            tempParent->left = temp->right;
            temp->right = curr->right;
        }
        temp->left = curr->left;
        if(parent == NULL) root = temp;
        else{
            if(parent->left == curr) parent->left = temp;
            else parent->right = temp;
        }
        free(curr);
        printf("%d deleted from Binary Search Tree!\n",val);
    }
}

void printInOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    printf("%d ", node->value);
    printInOrder(node->right);
}

int main()
{
	char op;
	int input;
	printf("====================\n");
	printf("| insert = i (int) |\n");
	printf("| search = s (int) |\n");
	printf("| delete = d (int) |\n");
	printf("| exit = e         |\n");
	printf("====================\n");
	while(1){
		scanf(" %c",&op);
		if(op == 'i'){
			scanf("%d",&input);
			insert(input);
		} 
		else if(op == 's'){
			scanf("%d",&input);
			search(input);
		}
		else if(op == 'd'){
			scanf("%d",&input);
			del(input);
		}
		else if(op == 'e'){
			system("cls");
			printf("Program Finished\n");
			break;
		}
		printInOrder(root);
		printf("\n");
	}
 	return 0;
}

