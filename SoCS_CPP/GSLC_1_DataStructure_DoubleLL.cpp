#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
	char character;
	struct Node *next;
	struct Node *prev;
};

	struct Node *head = NULL;
	struct Node *tail = NULL;
	struct Node *head2 = NULL;
	struct Node *tail2 = NULL;
	
struct Node *addNode(char str){
	struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
	curr->character = str;
	curr->next=curr->prev=NULL;
	return curr;
}
	
	
void firstData(char str){
//	printf("firstdata\n");
	struct Node *curr = addNode(str);
	head = tail = curr;
	head->prev = tail->next = NULL;
}

void frontPush(char str){
//	printf("frontPush\n");
	struct Node *curr = addNode(str);
	curr->next = head;
	head->prev = curr;
	head = curr;
	head->prev = NULL;
}

void backPush(char str){
//	printf("backPush\n");
	struct Node *curr = addNode(str);
	tail->next = curr;
	curr->prev = tail;
	tail = curr;
	tail->next = NULL;
}

void midPush(char str){
	if(str < head->character){
		frontPush(str);
	}
	else if(str > tail->character){
		backPush(str);
	}
	else{
//		printf("midPush\n");
		struct Node *curr = addNode(str);
		struct Node *temp = head;
		while(temp->next->character < curr->character && temp->next != NULL){
			temp = temp->next;
		}
		curr->next = temp->next;
		curr->prev = temp;
		curr->next->prev = curr;
		temp->next = curr;
	}
	
}

void ouptPush(char str){
	struct Node *curr = addNode(str);
	if(head2 == NULL && tail2 == NULL){
		head2 = tail2 = curr;
		head2->prev = tail2->next = NULL;
	}
	else{
		tail2->next = curr;
		curr->prev = tail;
		tail2 = curr;
		tail2->next = NULL;
	}
}

void popSwitch(){
	struct Node *temp = tail;
	while(temp != head){
		ouptPush(temp->character);
		temp = tail->prev;
		tail->prev = NULL;
		temp->next = NULL; 
		free(tail);
		tail = temp;
	}
	ouptPush(temp->character);
	head = tail = NULL;
}

void ouptPop(){
//	struct Node *temp = tail2;
//	while(temp != NULL){
//		temp = temp->prev;
//		tail2 = temp;
//		tail2->next = NULL; 
//	}
	free(head2);
	free(tail2);
	head2 = tail2 = NULL;
}

void printList(char get){
//	struct Node *temp = head;
	struct Node *temp = head2;
	while(temp != NULL){
		if(temp->next == NULL){
			printf("%c%c",temp->character,get);
		}
		else{
			printf("%c",temp->character);
		}
		temp = temp->next;
	}
}



int main()
{
	char text[100];
	char get;
	
	do{
		scanf("%s%c",text,&get);
		int len = strlen(text);
		for(int i=0;i<len;i++){
			char str = tolower(text[i]);
			if(head == NULL && tail == NULL){
				firstData(str);
			}
			else{
				midPush(str);
			}
		}
		popSwitch();
		printList(get);
		ouptPop();
		
	}while(get != '\n');
 	return 0;
}

