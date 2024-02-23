#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VIOLATION "\e[1;5;31m"
#define COLOR_OFF "\e[m"

struct Node{
	int value;
	int height;
	struct Node *left;
	struct Node *right;
	int bf;
};

struct Node *newNode(int val){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->left = newNode->right = NULL;
	newNode->value = val;
	newNode->height = 1;
	newNode->bf = 0;
	return newNode;
}

void updateNode(Node *curr){
	if(curr == NULL){
		return;
	}
	int left = curr->left ? curr->left->height : 0;
	int right = curr->right ? curr->right->height : 0;
	
	curr->height = 1 + (left > right ? left : right);
	curr->bf = left - right;
}

Node *leftRotate(Node *oldRoot){
	if(oldRoot == NULL) return NULL;
	
	Node *newRoot = oldRoot->right;
	Node *temp = newRoot->left;
	
	newRoot->left = oldRoot;
	oldRoot->right = temp;
	
	updateNode(oldRoot);
	updateNode(newRoot);
	
	return newRoot;
}

Node *rightRotate(Node *oldRoot){
	if(oldRoot == NULL) return NULL;
	
	Node *newRoot = oldRoot->left;
	Node *temp = newRoot->right;
	
	newRoot->right = oldRoot;
	oldRoot->left = temp;
	
	updateNode(oldRoot);
	updateNode(newRoot);
	
	return newRoot;
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
		printf(VIOLATION "%s%d(%d,%d)\n",arrow,root->value,root->height,root->bf);
		printf(COLOR_OFF);
	}
	else printf("%s%d(%d,%d)\n",arrow,root->value,root->height,root->bf);
	printTree(root->left,tabs+1,"\\->");
}

void print(Node *root){
	printf("\n================================================\n\n");
	printTree(root,0,"-) ");
	printf("\n================================================\n");
}

Node *rotation(Node *root, Node *top){
	if(root == NULL) return NULL;
	// left - right
	// positive means left
	// negative means right
	
	else if(root->bf <= -2){ //slanted right
		if(root->right->bf >= 1){ // slanted right-left
			print(top);
			root->right = rightRotate(root->right);
		}
		print(top);
		return leftRotate(root);
	} 
	
	else if(root->bf >= 2){ //slanted left
		if(root->left->bf <= -1){ //slanted left-right
			print(top);
			root->left = leftRotate(root->left);
		}
		print(top);
		return rightRotate(root); 
	}
	
	return root;
}

Node *predecessor(Node *curr){
	curr = curr->left;
	while(curr != NULL && curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}

Node *del(Node *curr, int val, Node *top){
	if(curr == NULL){
		printf("%d not found\n",val);
		return NULL;
	}
	else if(val < curr->value){
		curr->left = del(curr->left,val, top);
		updateNode(curr);
		return rotation(curr, top);
	}
	else if(val > curr->value){
		curr->right = del(curr->right,val, top);
		updateNode(curr);
		return rotation(curr, top);
	}
	else{
		if(curr->left == NULL && curr->right == NULL){
			free(curr);
			return NULL;
		}
		else if(curr->left != NULL && curr->right == NULL){
			struct Node *temp = curr->left;
			free(curr);
			updateNode(temp);
			return rotation(temp, top);
		}
		else if(curr->right != NULL && curr->left == NULL){
			struct Node *temp = curr->right;
			free(curr);
			updateNode(temp);
			return rotation(temp, top);
		}
		else{
			Node *replacement = predecessor(curr);
			curr->value = replacement->value;
			replacement->value = val;
			curr->left = del(curr->left,val, top);
			updateNode(curr);
			return rotation(curr, top);
		}
	}
}

Node *insert(Node *root, int val, Node *top){
	if(root == NULL){
		return newNode(val);
	}
	else if(val > root->value){
		root->right = insert(root->right, val, top);
	}
	else if(val < root->value){
		root->left = insert(root->left, val, top);
	}
	updateNode(root);
	
	return rotation(root, top);
}


int main()
{
	Node *root = NULL;
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
			root = insert(root,val,root);
	//		system("cls");
			print(root);	
		}
		else if(op == 'd'){
			scanf("%d",&val);
			if(val == -1) break;
			root = del(root,val,root);
			print(root);	
		}
	}
//	root = insert(root,30);
//	root = insert(root,20);
//	root = insert(root,10);
//	root = insert(root,15);
//	root = leftRotate(root);
//	root = rightRotate(root);
//	printTree(root,0);
//	system("cls");
	print(root);
 	return 0;
}

