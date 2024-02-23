#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *left;
	struct Node *right;
};

//struct Node *root = NULL;

struct Node *addNode(int val){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->value = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//void insert(int val){
//	if(root == NULL){
//		struct Node *newNode = addNode(val);
//		root = newNode;
//		printf("%d Inserted\n",val);
//	}
//	else{
//		struct Node *curr = root;
//		while(1){
//			if(val == curr->value){
//				printf("%d Exists\n",val);
//				return;
//			}
//			else if(val < curr->value){
//				if(curr->left == NULL){
//					struct Node *newNode = addNode(val);
//					curr->left = newNode;
//					printf("%d Inserted\n",val);
//					return;
//				}
//				curr = curr->left;
//			}
//			else if(val > curr->value){
//				if(curr->right == NULL){
//					struct Node *newNode = addNode(val);
//					curr->right = newNode;
//					printf("%d Inserted\n",val);
//					return;
//				}
//				curr = curr->right;
//			}
//		}
//	}
//}

//void search(int val){
//	struct Node *temp = root;
//	while(temp != NULL){
//		if(val == temp->value){
//			printf("%d is found",val);
//			return;
//		}
//		else if(val < temp->value) temp = temp->left;
//		else temp = temp->right;
//	}
//	printf("%d not found\n",val);
//}

//void del(int val){
//	struct Node *curr = root;
//	struct Node *parent = NULL;
//	while(curr != NULL && val != curr->value){
//		parent = curr;
//		if(val < curr->value) curr = curr->left;
//		else curr = curr->right;
//	}
//	if(curr == NULL){
//		printf("%d not found\n",val);
//	}
//	else if(curr->left == NULL && curr->right == NULL){
//		if(parent == NULL) root = NULL;
//		else{
//			if(parent->left == curr) parent->left = NULL;
//			else parent->right = NULL;
//		}
//		free(curr);
//		printf("%d Deleted\n",val);
//	}
//	else if(curr->right == NULL){
//		if(parent == NULL) root = curr->left;
//		else{
//			if(parent->left == curr) parent->left = curr->left;
//			else parent->right = curr->left;
//		}
//	}
//	else if(curr->left == NULL){
//		if(parent == NULL) root = curr->right;
//		else{
//			if(parent->left == curr) parent->left = curr->right;
//			else parent->right = curr->right;
//		}
//	}
//	else{
//		struct Node *pred = curr->left;
//		struct Node *predParent = curr;
//		while(pred != NULL && pred->right != NULL){
//			predParent = pred;
//			pred = pred->right;
//		}
//		if(predParent == curr){
//			if(pred->left != NULL){
//				predParent->left = pred->left;
//				curr->value = pred->value;
//			}
//			else{
//				predParent->left = NULL;
//				curr->value = pred->value;
//			}	
//		}
//		else{
//			if(pred->left != NULL){
//				predParent->right = pred->left;
//				curr->value = pred->value;
//			}
//			else{
//				predParent->right = NULL;
//				curr->value = pred->value;
//			}
//		}
//		free(pred);
//		printf("%d Deletedn",val);
//	}
//}

Node *predecessor(Node *curr){
	curr = curr->left;
	while(curr != NULL && curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}

Node *delrec(Node *curr, int val){
	if(curr == NULL){
		printf("%d not found\n",val);
		return NULL;
	}
	else if(val < curr->value){
		curr->left = delrec(curr->left,val);
		return curr;
	}
	else if(val > curr->value){
		curr->right = delrec(curr->right,val);
		return curr;
	}
	else{
		if(curr->left == NULL && curr->right == NULL){
			free(curr);
			return NULL;
		}
		else if(curr->left != NULL && curr->right == NULL){
			struct Node *temp = curr->left;
			free(curr);
			return temp;
		}
		else if(curr->right != NULL && curr->left == NULL){
			struct Node *temp = curr->right;
			free(curr);
			return temp;
		}
		else{
			Node *replacement = predecessor(curr);
			curr->value = replacement->value;
			replacement->value = val;
			curr->left = delrec(curr->left,val);
			return curr;
		}
	}
}

Node *shortdelrec(struct Node *curr, int val){
	if(curr == NULL){
		return NULL;
	}
	else if(val < curr->value){	
		curr->left = delrec(curr->left,val);
		return curr;
	}
	else if(val > curr->value){
		curr->right = delrec(curr->right,val);
		return curr;
	}
	else{
		if(curr->left != NULL && curr->right != NULL){
			Node *replacement = predecessor(curr);
			curr->value = replacement->value;
			replacement->value = val;
			curr->left = delrec(curr->left,val);
			return curr;
		}
		else{
			Node *temp = curr->left != NULL ? curr->left : curr->right;
			free(curr);
			return temp;
		}
	}
}

Node *delAllrec(Node *curr){
	if(curr == NULL){
		return NULL;
	}
	delAllrec(curr->right);
	delAllrec(curr->left);
	free(curr);
	return NULL;
}

struct Node *insertrec(struct Node *curr, int val){
	if(curr == NULL) return addNode(val);
	else{
		if(curr->value > val){
			curr->left = insertrec(curr->left,val);
			return curr;
		}
		else if(curr->value < val){
			curr->right = insertrec(curr->right,val);
			return curr;
		}
		else{
			return curr;
		}
	}
}

struct Node *searchrec(struct Node *curr,int val){
	if(curr == NULL){
		printf("%d is not found\n",val);
		return NULL;
	}
	else{
		if(val < curr->value){
			return searchrec(curr->left,val);
		}
		else if(val > curr->value){
			return searchrec(curr->right,val);
		}
		else if(val == curr->value){
			printf("%d is found\n",val);
			return curr;
		}
	}
}

Node *updaterec(Node *curr, int oldVal, int newVal){
	curr = delrec(curr,oldVal);
	return insertrec(curr,newVal);
}

void preOrder(struct Node *curr){
	if(curr == NULL) return;
	else{
		printf("%d ",curr->value);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(struct Node *curr){
	if(curr == NULL) return;
	else{
		inOrder(curr->left);
		printf("%d ",curr->value);
		inOrder(curr->right);
	}
}

void inOrderIndent(struct Node *curr,int count){
	if(curr == NULL) return;
	inOrderIndent(curr->right,count+1);
	for(int i=0;i<count;i++){
		printf("\t");
	}
	printf("%d\n",curr->value);
	inOrderIndent(curr->left,count+1);
}

void printDebug(struct Node *curr, int count){
	inOrderIndent(curr,count);
	printf("-------------------------------------------------\n");
}

void postOrder(struct Node *curr){
	if(curr == NULL) return;
	else{
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ",curr->value);
	}
}

int main()
{
	char op;
	int input;
	Node *rec = NULL;
	rec = insertrec(rec,50);
	rec = insertrec(rec,70);
	rec = insertrec(rec,20);
	rec = insertrec(rec,10);
	rec = insertrec(rec,30);
	rec = insertrec(rec,80);
	rec = insertrec(rec,90);
//	preOrder(rec);
//	printf("\n");
//	inOrder(rec);
//	printf("\n");
//	postOrder(rec);
//	printf("\n");
//	printDebug(rec,0);
	shortdelrec(rec,80);
	printDebug(rec,0);
	shortdelrec(rec,50);
	printDebug(rec,0);
	shortdelrec(rec,70);
	printDebug(rec,0);
	rec = updaterec(rec,90,50);
	printDebug(rec,0);
	rec = searchrec(rec,70);
	rec = searchrec(rec,100);
	delAllrec(rec);
	printDebug(rec,0);
//	while(1){
//		inOrder(root);
//		printf("\n");
//		scanf(" %c",&op);
//		if(op == 'i' || op == 's'){
//			scanf("%d",&input);
//			if(op == 'i') insert(input);
//			else if(op == 's') search(input);
//		}
//		else if(op == 'e') break;
//	}
 	return 0;
}

