#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int bf;
	int height;
	int val;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int val){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->bf = 0;
	newNode->height = 1;
	newNode->val = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void update(struct Node *root){
	if(root == NULL) return;
	
	int left, right;
	
	if(root->left == NULL) left = 0;
	else left = root->left->height;
	if(root->right == NULL) right = 0;
	else right = root->right->height;
	
	if(left > right) root->height = left + 1;
	else root->height = right + 1;
	
	root->bf = left - right;
}

struct Node *lRotate(struct Node *root){
	if(root == NULL) return NULL;
	
	struct Node *newRoot = root->right;
	struct Node *temp = newRoot->left;
	
	newRoot->left = root;
	root->right = temp;
	
	update(root);
	update(newRoot);
	
	return newRoot;
}

struct Node *rRotate(struct Node *root){
	if(root == NULL) return NULL;
	
	struct Node *newRoot = root->left;
	struct Node *temp = newRoot->right;
	
	newRoot->right = root;
	root->left = temp;
	
	update(root);
	update(newRoot);
	
	return newRoot;
}

struct Node *rotate(struct Node *root){
	if(root == NULL) return NULL;
	
	if(root->bf <= -2){
		if(root->right->bf >= 1) root->right = rRotate(root->right);
		return lRotate(root);
	}
	else if(root->bf >= 2){
		if(root->left->bf <= -1) root->left = lRotate(root->left);
		return rRotate(root);
	}
	
	return root;
}

struct Node *insert(struct Node *root, int val){
	if(root == NULL){
		printf("Data Successfully Inserted\n");
		return newNode(val);
	} 
	
	if(val == root->val){
		printf("Duplicate Value!\n");
		return root;
	}
	else if(val < root->val) root->left = insert(root->left,val);
	else if(val > root->val) root->right = insert(root->right,val);
	
	update(root);
	return rotate(root);
}

struct Node *predecessor(struct Node *root){
	root = root->left;
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

struct Node *del(struct Node *root, int val){
	if(root == NULL){
		printf("Data not Found\n");
		return NULL;
	}
	if(val < root->val) root->left = del(root->left,val);
	else if(val > root->val) root->right = del(root->right,val);
	else{
		if(root->left == NULL && root->right == NULL){
			printf("Data Found\n");
			free(root);
			printf("Value %d was deleted\n",val);
			return NULL;
		}
		else if(root->left != NULL && root->right == NULL){
			printf("Data Found\n");
			struct Node *temp = root->left;
			free(root);
			printf("Value %d was deleted\n",val);
			return rotate(temp);
		}
		else if(root->left == NULL && root->right != NULL){
			printf("Data Found\n");
			struct Node *temp = root->right;
			free(root);
			printf("Value %d was deleted\n",val);
			return rotate(temp);
		}
		else{
			struct Node *pred = predecessor(root);
			root->val = pred->val;
			pred->val = val;
			root->left = del(root->left,val);
		}
	}
	update(root);
	return rotate(root);
}

void preOrder(struct Node *root){
	if(root == NULL) return;
	
	printf("%d ",root->val);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(struct Node *root){
	if(root == NULL) return;
	
	inOrder(root->left);
	printf("%d ",root->val);
	inOrder(root->right);
}

void postOrder(struct Node *root){
	if(root == NULL) return;
	
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->val);
}

void traversal(struct Node *root){
	printf("PreOrder: ");
	preOrder(root);
	printf("\n");
	printf("InOrder: ");
	inOrder(root);
	printf("\n");
	printf("PostOrder: ");
	postOrder(root);
	printf("\n");
}

int main()
{
	int op, val;
	struct Node *root = NULL;
	while(op != 4){
		system("cls");
		printf("------|AVL TREE|------\n");
		printf("1. Insertion\n");
		printf("2. Deletion\n");
		printf("3. Traversal\n");
		printf("4. Exit\n");
		printf("Choose: ");
		scanf("%d",&op); getchar();
		switch(op){
			case 1:
				printf("Insert: ");
				scanf("%d",&val); getchar();
				root = insert(root,val);
				break;
			case 2:
				printf("Delete: ");
				scanf("%d",&val); getchar();
				root = del(root,val);
				break;
			case 3:
				traversal(root);
				break;
			case 4:
				printf("Thank you!\n");
				break;
			default:
				printf("Unknown Command, Try again!\n");
				break;
		}
		if(op != 4){
			printf("\nPress Enter to Continue..."); getchar();
		} 
	}
 	return 0;
}

