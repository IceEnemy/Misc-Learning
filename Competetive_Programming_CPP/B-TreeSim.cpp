#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 2
#define MIN 1

struct Node{
	int val[MAX+1];
	int count;
	struct Node *link[MAX+1];
};

struct Node *root = NULL;

struct Node *addNode(int val, struct Node *child){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	
	newNode->val[1] = val;
	newNode->count = 1;
	newNode->link[0] = root;
	newNode->link[1] = child;
	
	return newNode;
}

void insertNode(int val, int pos, struct Node *curr, struct Node *child){
	int i = curr->count;
	
	while(i > pos){
		curr->val[i+1] = curr->val[i];
		curr->link[i+1] = curr->link[i];
		i--;
	}
	
	curr->val[i+1] = val;
	curr->link[i+1] = child;
	curr->count++;
}

void splitNode(int val, int pos, int *pVal, struct Node *curr, struct Node *child, struct Node **newNode){
	int med;
	
	if(pos > MIN) med = MIN+1;
	else med = MIN;
	
	*newNode = (struct Node *)malloc(sizeof(struct Node));
	int i = med+1;
	
	while(i <= MAX){
		(*newNode)->val[i-med] = curr->val[i];
		(*newNode)->link[i-med] = curr->link[i];
		i++;
	}
	
	curr->count = med;
	(*newNode)->count = MAX - med;
	
	if(pos > MIN) insertNode(val,pos-med,*newNode, child);
	else insertNode(val,pos,curr,child);
	
	*pVal = curr->val[curr->count];
	(*newNode)->link[0] = curr->link[curr->count];
	curr->count--;
}

int setVal(int val, int *pVal, struct Node *curr, struct Node **child){
	int pos;
	
	if(curr == NULL){
		*pVal = val;
		*child = NULL;
		return 1;
	}
	
	if(val < curr->val[1]) pos = 0;
	else{
		pos = curr->count;
		while(val < curr->val[pos] && pos > 1){
			if(val == curr->val[pos]) return 0;
			pos--;
		}
	}
	if(setVal(val,pVal,curr->link[pos],child) == 1){
		if(curr->count < MAX){
			insertNode(*pVal,pos,curr,*child);
		}
		else{
			splitNode(*pVal,pos,pVal,curr,*child,child);
			return 1;
		}
	}
	return 0;
}

void insert(int val){
	int pVal;
	struct Node *child;
	
	if(setVal(val,&pVal,root,&child) == 1) root = addNode(pVal,child);
}

void search(int val, int *pos, struct Node *curr){
	if(curr == NULL){
		printf("%d not found!\n",val);
		return;
	}
	if(val < curr->val[1]) *pos = 0;
	else{
		*pos = curr->count;
		while(val < curr->val[*pos] && *pos > 1){
//			printf("%d, ",curr->val[*pos]);
			(*pos)--;
		}
		if(val == curr->val[*pos]){
			printf("%d is found!\n",val);
			return;
		}
	}
	search(val,pos,curr->link[*pos]);
	
	return;
}

void inOrder(struct Node *curr){
	if(curr == NULL) return;
	int i;
	
	for(i=0; i<curr->count; i++){
		inOrder(curr->link[i]);
		printf("%d ",curr->val[i+1]);
	}
	inOrder(curr->link[i]);
}

void print(struct Node *curr){
	printf("\n===============================\n");
	inOrder(curr);
	printf("\n===============================\n");
}
int main(){
	int pos;
	char op;
	int val;
	printf("=========================\n");
	printf("| B-Tree                |\n");
	printf("+-----------------------+\n");
	printf("| \'i\' (int) to insert   |\n");
	printf("| \'s\' (int) to search   |\n");
	printf("| \'x\' (int) to exit     |\n");
	printf("=========================\n");
	
	while(op != 'x'){
		scanf("%c",&op);
		switch(op){
			case 'i':
				scanf("%d",&val);
				insert(val);
				print(root);
				break;
			case 's':
				scanf("%d",&val);
				search(val,&pos,root);
				print(root);
				break;
		}
	}
}
