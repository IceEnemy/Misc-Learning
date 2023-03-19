#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char val;
	struct Node *next;
	struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *addNode(char value){
	struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
	curr->val = value;
	curr->next = curr->prev = NULL;
	return curr;
}

void firstData(char value){
	struct Node *curr = addNode(value);
	head = tail = curr;
}

void pushHead(char value){
	if(!head){
		firstData(value);
	}
	else{
		struct Node *curr = addNode(value);
		head->prev = curr;
		curr->next = head;
		head = curr;	
	}
}

void pushTail(char value){
	if(!head){
		firstData(value);
	}
	else{
		struct Node *curr = addNode(value);
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

void pushMid(char value){
	if(!head){
		firstData(value);
	}
	else if(value <= head->val){
		pushHead(value);
	}
	else if(value >= tail->val){
		pushTail(value);
	}
	else{
		struct Node *curr = addNode(value);
		struct Node *temp = head;
		while(temp->next != NULL && temp->next->val < value){
			temp = temp->next;
		}
		curr->next = temp->next;
		curr->next->prev = curr;
		temp->next = curr;
		curr->prev = temp;
	}
}

void popHead(){
	if(!head){
		printf("List Empty!\n");
		return;	
	} 
	if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	struct Node *temp = head;
	head = temp->next;
	head->prev = NULL;
	free(temp);
}

void popTail(){
	if(!head){
		printf("List Empty!\n");
		return;	
	} 
	if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	struct Node *temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	free(temp);
}

void popVal(char value){
	if(!head){
		printf("List Empty!\n");
		return;	
	} 
	struct Node *temp = head;
	while(temp != NULL){
		if(temp->val == value){
			struct Node *curr = temp->prev;
			curr->next = temp->next;
			temp->next->prev = curr;
			free(temp);
			return;
		}
		temp = temp->next;
	}
	printf("Value not found!\n");
}

void printList(){
	struct Node *temp = head;
	printf("NULL");
	while(temp != NULL){
		printf("<-%c->",temp->val);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main()
{
	char cmd[100];
	char input;
	do{
		
		scanf("%s",cmd);
		if(strcmp(cmd,"push") == 0){
			scanf(" %c",&input);
			pushMid(input);
		}
		else if(strcmp(cmd,"popV") == 0){
			scanf(" %c",&input);
			popVal(input);
		}
		else if(strcmp(cmd,"popH") == 0){
			popHead();
		}
		else if(strcmp(cmd,"popT") == 0){
			popTail();
		}
		else if(strcmp(cmd,"exit") == 0){
			printf("program finished\n");
			break;
		}
		else{
			printf("no command exists\n");
			continue;
		}
		printList();
	} while(true);
//	pushMid('1');
//	pushMid('6');
//	pushMid('4');
//	pushMid('3');
//	printList();
 	return 0;
}

