#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *addNode(int val){
	struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
	curr->value = val;
	curr->next = NULL;
	return curr;
}

void firstData(int val){
	struct Node *curr = addNode(val);
	head = tail = curr;
	tail->next = NULL;
}

void frontPush(int val){
	struct Node *curr = addNode(val);
	curr->next = head;
	head = curr;
}

void backPush(int val){
	struct Node *curr = addNode(val);
	tail->next = curr;
	tail = curr;
	tail->next = NULL;
}

void midPush(int val){
	if(val < head->value){
		frontPush(val);
	}
	else if(val > tail->value){
		backPush(val);
	}
	else{
		struct Node *curr = addNode(val);
		struct Node *temp = head;
		while(temp->next->value < curr->value && temp->next != NULL){
			temp = temp->next;
		}
		curr->next = temp->next;
		temp->next = curr;
		
	}
}

void printList(){
	struct Node *temp = head;
	while(temp != NULL){
		if(temp->next != NULL){
			printf("%d ",temp->value);
		}
		else{
			printf("%d\n",temp->value);
		}
		temp = temp->next;
	}
}

int main()
{
	int val;
	printf("Input -1 to stop\n");
	do{
		scanf("%d",&val);
		if(val == -1){
			printf("Program Done!\n");
			break;
		}
		else if(head == NULL){
			firstData(val);
		}
		else{
			midPush(val);
		}
		printList();
	}while(val != -1);
	
 	return 0;
}

