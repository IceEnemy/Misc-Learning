#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char name[30];
	char num[15];
	char email[25];
	int point;
	struct Node *left;
	struct Node *right;
};

struct Node *root = NULL;

struct Node *addNode(char name[], char num[], char email[]){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	strcpy(newNode->name,name);
	strcpy(newNode->num,num);
	strcpy(newNode->email,email);
	newNode->point = 10;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node *insert(struct Node *curr, char name [], char num[], char email[]){
	if(curr == NULL) return addNode(name, num, email);
	else{
		if(strcmp(curr->num,num) > 0){
			curr->left = insert(curr->left,name, num,email);
			return curr;
		}
		else if(strcmp(curr->num,num) < 0){
			curr->right = insert(curr->right,name, num, email);
			return curr;
		}
		else{
			return curr;
		}
	}
}

struct Node *search(struct Node *curr, char num[]){
	if(curr == NULL){
		return NULL;
	}
	else{
		if(strcmp(curr->num,num) > 0){
			return search(curr->left,num);
		}
		else if(strcmp(curr->num,num) < 0){
			return search(curr->right,num);
		}
		else{
			return curr;
		}
	}
}

struct Node *pred(struct Node *curr){
	curr = curr->left;
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}

struct Node *del(struct Node *curr, char num[]){
	if(curr == NULL){
		printf("Data Invalid !\n");
		return NULL;
	}
	else if(strcmp(curr->num,num) > 0){
		return del(curr->left,num);
	}
	else if(strcmp(curr->num,num) < 0){
		return del(curr->right,num);
	}
	else{
		if(curr->right == NULL && curr->left == NULL){
			free(curr);
			printf("Delete Success !\n");
			return NULL;
		}
		else if(curr->right == NULL){
			struct Node *temp = curr->left;
			free(curr);
			printf("Delete Success !\n");
			return temp;
		}
		else if(curr->left == NULL){
			struct Node *temp = curr->right;
			free(curr);
			printf("Delete Success !\n");
			return temp;
		}
		else{
			struct Node *rep = pred(curr);
			strcpy(curr->num, rep->num);
			strcpy(rep->num,num);
			del(curr->left,num);
			return NULL;
		}
	}
}

void delAll(struct Node *curr){
	if(curr == NULL) return;
	else{
		delAll(curr->left);
		delAll(curr->right);
		free(curr);
	}
}

void printInOrder(struct Node *curr,int flag){
	if(curr == NULL) return;
	else{
		if(flag == 0){
			printf("=============================================================================\n");
			printf("| Name                      | Phone Number  | Email                | Points |\n");
			printf("=============================================================================\n");
			flag = 1;
		}
		printInOrder(curr->left,flag);
		printf("| %-25s | %-13s | %-20 | %-6 |",curr->name,curr->num, curr->email, curr->point);
		printf("-----------------------------------------------------------------------------\n");
		printInOrder(curr->right,flag);
	}
}

int main()
{
	
 	return 0;
}

