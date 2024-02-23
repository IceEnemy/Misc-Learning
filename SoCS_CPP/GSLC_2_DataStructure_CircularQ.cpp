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
	curr->next = NULL;
	curr->value = val;
	return curr;
}

void firstData(int val){
	struct Node *curr = addNode(val);
	head = tail = curr;
	head->next = tail;
}

void q(int val){
	if(head == NULL){
		firstData(val);
	}
	else{
		struct Node *curr = addNode(val);
		tail->next = curr;
		curr->next = head;
		tail = curr;
//		tail->next = head;	
	}
	printf("Added %d to Queue!\n",val);
}

void dq(){
	if(head == NULL){
		printf("Queue is Already Empty!\n");
	}
	else if(head == tail){
		printf("Removed %d\n",head->value);	
		head = tail = NULL;
		free(head);
	}
	else{
		int max = NULL;
		struct Node *temp = head;
		while(true){
			if(max == NULL || max < temp->value){
				max = temp->value;
			}
				
			if(temp == tail) break;
			temp = temp->next;
		}
//		temp = head;
		struct Node *temp2;
		do{
			if(temp->next->value == max){
				if(temp->next == head){
					temp->next = head->next;
					
					head->next = NULL;
					printf("Removed %d\n",head->value);
					free(head);
					head = temp->next;
				}
				else if(temp->next == tail){
					temp->next = head;
					
					tail->next = NULL;
					printf("Removed %d\n",tail->value);
					free(tail);
					tail = temp;
				}
				else{
					temp2 = temp->next;
					temp->next = temp2->next;
//					temp2->next = NULL;
					printf("Removed %d\n",temp2->value);
					
					free(temp2);
					temp2 = NULL;
					return;
				}
			}
			temp = temp->next;
		}while(temp->value != max);
	}
}

void viewQ(){
	if(head == NULL){
		printf("Queue is Empty!\n");
	}
	else if(head == tail){
//		printf("head = tail\n");
		printf("%d\n",head->value);
	}
	else{
		struct Node *temp = head;
		do{
//			printf("printnode\n");
			if(temp->next == head){
				printf("%d\n",temp->value);
			}
			else{
				printf("%d ",temp->value);
			}
			temp = temp->next;
		}while(temp != head);
	}
}

int main()
{
	printf("===========================\n");
	printf("| Commands:               |\n");
	printf("| \"q (int)\" to add        |\n");
	printf("| \"dq\" to dequeue         |\n");
	printf("| \"view\" to view queue    |\n");
	printf("| \"exit\" to stop          |\n");
	printf("===========================\n");
//	dq();
//	q(1);
//	q(3);
//	q(3);
//	viewQ();
	char cmd[100];
	do{
		
		scanf("%s",cmd);
		if(strcmp(cmd,"q") == 0){
			int add;
			scanf("%d",&add);
			q(add);
		}
		else if(strcmp(cmd,"dq") == 0){
			dq();
		}
		else if(strcmp(cmd,"view") == 0){
			viewQ();
		}
		else if(strcmp(cmd,"exit") == 0){
			printf("Application Finished\n");
			break;
		}
		else{
			printf("Unknown Command, Try Again!\n");
		}
	}while(strcmp(cmd,"exit")!=0);
 	return 0;
}

