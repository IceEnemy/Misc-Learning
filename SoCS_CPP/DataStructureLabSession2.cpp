#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// linked lists are used to store values

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

void sortPush(int val){
	if(val < head->value){
		frontPush(val);
	}
	else if(val > tail->value){
		backPush(val);
	}
	else{
		struct Node *curr = addNode(val);
		struct Node *temp = head;
		while(temp->next->value < val && temp->next != NULL){
			temp=temp->next;
		}
		curr->next = temp->next;
		temp->next = curr;
	}
}

void frontPop(){
	if(head == NULL){
		printf("List is empty!\n");
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		struct Node *temp = head->next;
		free(head);
		head = temp;
	}
	
}

void backPop(){
	if(tail == NULL){
		printf("List is empty!\n");
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		struct Node *temp = head;
		while(temp->next != tail){
			temp = temp->next;
		}
		temp->next = NULL;
		free(tail);
		tail = temp;
//		tail->next = NULL;
	}
}

void valPop(int val){
	if(head->value == NULL){
		printf("List is empty!\n");
	}
	else if(head->value == val){
		frontPop();
	}
	else if(tail->value == val){
		backPop();
	}
	else{
		struct Node *temp = head;
		while(temp->next != NULL){
			if(temp->next->value == val){
				struct Node *temp2 = temp->next;
				temp->next = temp->next->next;
				free(temp2);
				return;
			}
			temp = temp->next;
		}
	}
	
}

void search(int val){
	struct Node *temp = head;
	while(temp != NULL){
		if(temp->value == val){
			printf("%d is found on the list!\n", val);
			return;
		}
		temp = temp->next;
	}
	printf("%d is not found on the list!\n",val);
}

/*
	stack
	first in, first out
	pretty much the concept below
	VVVV
*/

void pushStack(int val){
	frontPush(val);
}

void popStack(int val){
	frontPop(val);
}

void printList(){
	struct Node *temp = head;
	while(temp != NULL){
		printf("%d->",temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
	if(head != NULL){
		printf("head : %d\n",head->value);
//		printf("??\n");
	}
	else{
		printf("head : NULL\n");
	}
	if(tail != NULL){
		printf("tail : %d\n",tail->value);
	}
	else{
		printf("tail : NULL\n");
	}
}

int main()
{
//	backPop();
//	printList();
	firstData(1);
	printList();
	backPush(3);
	printList();
	backPush(5);
	printList();
	sortPush(4);
	printList();
	frontPush(0);
	printList();
	frontPop();
	printList();
	backPop();
	printList();
	valPop(3);
//	backPush(10);
	printList();
	search(4);
	search(5);
//	printf("hehehe\n\n");
//	printf("\n\n");
 	return 0;
}

