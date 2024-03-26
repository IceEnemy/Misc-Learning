#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
	char letter;
	struct Node *left;
	struct Node *right;
};

struct Node *root = NULL;

struct Node *addNode(char let){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->letter = let;
	newNode->left = newNode->right = NULL;
	return newNode;
}

int input(char str[]){
	int len = strlen(str);
	int count = len;
	struct Node *curr = root;
	for(int i=0;i<len;i++){
		str[i] = tolower(str[i]);
		if(root == NULL){
			struct Node *newNode = addNode(str[i]);
			root = newNode;
			curr = root;
		}
		else if(i == 0){
			if(str[i] != root->letter) return 0;
			else count--;
		}
		else{
			if(curr->left == NULL){
//				printf("added left\n");
				struct Node *newNode = addNode(str[i]);
				curr->left = newNode;
				curr = curr->left;
			}
			else if(curr->left->letter == str[i]){
//				printf("%c == %c\n",curr->left->letter,str[i]);
				curr = curr->left;
				count--;
			}
			else if(curr->right == NULL){
//				printf("added right\n");
				struct Node *newNode = addNode(str[i]);
				curr->right = newNode;
				curr = curr->right;
			}
			else if(curr->right->letter == str[i]){
//				printf("%c == %c\n",curr->right->letter,str[i]);
				curr = curr->right;
				count--;
			}
			else return 0; 
		}
	}
	if(count == 0) return 2;
	return 1;
}

int main(){
	char word[100];
	printf("===========================\n");
	printf("| Input Strings & Check!  |\n");
	printf("| Input \"!done\" to stop   |\n");
	printf("===========================\n");
	
	do{
		scanf("%s",word);
		int valid = input(word);
		if(valid == 0){
			printf("Unable to put string into tree\n");
		}
		else if(valid == 1){
			printf("String was put into tree\n");
		}
		else{
			printf("String already in tree\n");
		}
	}while(strcmp(word,"!done") != 0);
 	return 0;
}
	

