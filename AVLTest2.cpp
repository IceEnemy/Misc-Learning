#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int val;
	int height;
	int bf;
	struct Node *left, *right;
};

struct Node *newNode(int val){
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->val = val;
	newNode->bf = 0;
	newNode->height = 1;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void update(struct Node *root){
	if(root == NULL) return;
	
	int left,right;
	if(root->left == NULL) left = 0;
	else left = root->left->height;
	if(root->right == NULL) right = 0;
	else right = root->right->height;
	
	if(left > right) root->height = left+1;
	else root->height = right+1;
	
	root->bf = left-right;
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
	
	if(root->bf >= 2){
		if(root->left->bf <= -1) root->left = lRotate(root->left);
		return rRotate(root);
	}
	else if(root->bf <= -2){
		if(root->right->bf >= 1) root->right = rRotate(root->right);
		return lRotate(root);
	}
	return root;
}

struct Node *insert(struct Node *root,int val){
	if(root == NULL) return newNode(val);
	
	if(val < root->val) root->left = insert(root->left,val);
	else if(val > root->val) root->right = insert(root->right,val);
	
	update(root);
	return rotate(root);
}

struct Node *pred(struct Node *root){
	if(root == NULL || root->left == NULL) return NULL;
	root = root->left;
	while(root->right){
		root = root->right;
	}
	return root;
}

struct Node *del(struct Node *root, int val){
	if(root == NULL) return NULL;
	
	if(val < root->val) root->left = del(root->left,val);
	else if(val > root->val) root->right = del(root->right,val);
	else{
		if(!root->left && !root->right){
			free(root);
			return NULL;
		}
		else if(root->left && !root->right){
			struct Node *temp = root->left;
			free(root);
			return rotate(temp);
		}
		else if(!root->left && root->right){
			struct Node *temp = root->right;
			free(root);
			return rotate(temp);
		}
		else{
			struct Node *replace = pred(root);
			root->val = replace->val;
			replace->val = val;
			root->left = del(root->left,val);
		}
	}
	update(root);
	return rotate(root);
}

void printTree(Node *root, int tabs, char arrow[]){
	if(root == NULL){
		return;
	}
	printTree(root->right,tabs+1,"/->");
	for(int i=0;i<tabs;i++){
		printf("\t");
	}
	if(root->bf >= 2 || root->bf <= -2) {
		printf("%s%d(%d,%d) --> VIOLATION\n",arrow,root->val,root->height,root->bf);
	}
	else printf("%s%d(%d,%d)\n",arrow,root->val,root->height,root->bf);
	printTree(root->left,tabs+1,"\\->");
}

void print(Node *root){
	printf("\n================================================\n\n");
	printTree(root,0,"-) ");
	printf("\n================================================\n");
}

int main()
{
	struct Node *root = NULL;
//	root = insert(root,10);
//	root = insert(root,20);
//	root = insert(root,30);
	int val;
	char op;
	printf("==========================\n");
	printf("|   AVL Tree Simulator   |\n");
	printf("+------------------------+\n");
	printf("| \'i\' (int) to insert    |\n");
	printf("| \'d\' (int) to delete    |\n");
	printf("| \'x\' to exit            |\n");
	printf("==========================\n");
	print(root);
	while(op != 'x'){
		scanf("%c",&op);
		if(op == 'i'){
			scanf("%d",&val);
			if(val == -1) break;
			root = insert(root,val);
	//		system("cls");
			print(root);	
		}
		else if(op == 'd'){
			scanf("%d",&val);
			if(val == -1) break;
			root = del(root,val);
			print(root);	
		}
	}
	print(root);
 	return 0;
}

