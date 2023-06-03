#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
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

char color(struct Node *root){
	if(root == NULL) return 'B';
	else return root->color;
}

struct Node *granpa(struct Node *root){
	if(root == NULL || root->parent == NULL || root->parent->parent == NULL) return NULL;
	return root->parent->parent;
}

struct Node *uncle(struct Node *parent, struct Node *gran){
	if(parent == NULL || gran == NULL) return NULL;
	return (parent == gran->left) ? gran->right : gran->left;
}

struct Node *lRotate(struct Node *root){
	printf("lRotate\n");
	if(root == NULL) return NULL;
	
	struct Node *newRoot = root->right;
	struct Node *temp = newRoot->left;
	
	newRoot->left = root;
	root->right = temp;
	
	newRoot->color = 'B';
	root->color = 'R';
	
	newRoot->parent = root->parent;
	root->parent = newRoot;
	if(temp) temp->parent = root;
	
	return newRoot;
}

struct Node *rRotate(struct Node *root){
	printf("rRotate\n");
	if(root == NULL) return NULL;
	
	struct Node *newRoot = root->left;
	struct Node *temp = newRoot->right;
	
	newRoot->right = root;
	root->left = temp;
	
	newRoot->color = 'B';
	root->color = 'R';
	
	newRoot->parent = root->parent;
	root->parent = newRoot;
	if(temp) temp->parent = root;
	
	
	return newRoot;
}

struct Node *rotate(struct Node *root){
	if(root == NULL) return NULL;
	
	if(color(root->left) == 'R'){
		if(color(root->left->right) == 'R') root->left = lRotate(root->left);
		return rRotate(root);
	}
	else if(color(root->right) == 'R'){
		printf("lRotate\n");
		if(color(root->right->left) == 'R') root->right = rRotate(root->right);
		return lRotate(root);
	}
	
	return root;
}

void colorChange(struct Node *root){
	if(root->color == 'B') root->color = 'R';
	else root->color = 'B';
}

void colorUpdate(struct Node *root){
	struct Node *grand = granpa(root);
	if(grand != NULL){
		if(grand->parent != NULL) colorChange(grand);
		colorChange(root->parent);
		if(color(grand->parent) =='R'){
			struct Node *changeRotate = granpa(grand);
			changeRotate = rotate(changeRotate);
		}
	}
}

//void colorUpdate(struct Node *root) {
//    struct Node *grand = granpa(root);
//    if (grand != NULL && color(grand) == 'R') {
//        colorChange(grand);
//        colorChange(root->parent);
//        struct Node *changeRotate = granpa(grand);
//        if (grand == grand->parent->left)
//            grand->parent->left = rotate(grand);
//        else
//            grand->parent->right = rotate(grand);
//    }
//}

struct Node *insert(struct Node *root, struct Node *parent, int val){
	if(root == NULL){
		struct Node *newNode = addNode(val);
		if(parent == NULL){
			newNode->color = 'B';
			return newNode;
		}
		newNode->parent = parent;
		if(parent->color == 'R'){
			struct Node *grand = granpa(newNode);
			struct Node *ucl = uncle(parent,grand);
			
			if(color(ucl) == 'B') grand = rotate(grand);
			else{
				colorChange(ucl);
				colorUpdate(newNode);
			}
		}
		return newNode;
	}
	else if(val == root->val){
		printf("Duplicate Value!\n");
		return root;
	}
	else if(val < root->val) root->left = insert(root->left,root,val);
	else root->right = insert(root->right,root,val);
	
	return root;
}

//void insert(struct Node **root, struct Node **parent, struct Node **grand, int val){
//	if(*root == NULL){
//		struct Node *newNode = addNode(val);
//		if(*parent == NULL){
//			newNode->color = 'B';
//			*root = newNode;
//		}
//		newNode->parent = *parent;
//		if((*parent)->color == 'R'){
//			struct Node *ucl = uncle(parent,grand);
//			
//			if(color(ucl) == 'B') *grand = rotate(grand);
//			else{
//				colorChange(ucl);
//				colorUpdate(newNode);
//			}
//		}
//		*root = newNode;
//	}
//	else if(val == root->val){
//		printf("Duplicate Value!\n");
//	}
//	else if(val < root->val) insert(root->left,root,parent,val);
//	else insert(root->right,root,parent,val);
//	
//}

void inOrder(struct Node *root){
	if(root == NULL) return;
	inOrder(root->left);
	printf("%d ",root->val);
	inOrder(root->right);
}

void printTree(struct Node *root, int tabs, char arrow[]){
	if(root == NULL){
		return;
	}
	printTree(root->right,tabs+1,"/->");
	for(int i=0;i<tabs;i++){
		printf("\t");
	}
	if(root->color == 'B') printf("%s%d(B)\n",arrow,root->val);
	else printf("%s%d(R)\n",arrow,root->val);
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
	root = insert(root,NULL,41);
//	print(root);
	root = insert(root,NULL,22);
//	print(root);
	root = insert(root,NULL,5);
	printf("root : %d(%c)\n",root->val,root->color);
	printf("left : %d(%c)\n",root->left->val,root->left->color);
	printf("left-left : %d(%c)\n",root->left->left->val,root->left->left->color);
	if(root->right==NULL) printf("right : NULL\n");
	else printf("right : %d\n",root->right->val);
//	root = insert(root,NULL,51);
//	print(root);
//	root = insert(root,NULL,48);
//	print(root);
//	root = insert(root,NULL,29);
//	root = insert(root,NULL,18);
//	root = insert(root,NULL,21);
//	root = insert(root,NULL,45);
//	root = insert(root,NULL,3);
//	inOrder(root);
	printf("\n");
 	return 0;
}

