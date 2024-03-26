#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
	char character;
	struct Node *next;
	struct Node *prev;
};

struct Node *addNode(char str){
	struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
	curr->next = curr->prev = NULL;
	curr->character = str;
	//strcpy(curr->character,str);
	return curr;
}

void firstData(char str, struct Node **head, struct Node **tail){
	struct Node *curr = addNode(str);
	(*head) = (*tail) = curr;
	(*head)->prev = (*tail)->next = NULL;
}

void frontPush(char str, struct Node **head, struct Node **tail){
//	if((*head) == NULL){
//		firstData(str,head,tail);
//	}
//	else{
		struct Node *curr = addNode(str);
		curr->next = (*head);
		(*head)->prev = curr;
		(*head) = curr;
//	}
	
}

void backPush(char str, struct Node **head, struct Node **tail){
//	if((*head) == NULL){
//		firstData(str,head,tail);
//	}
//	else{
		struct Node *curr = addNode(str);
		(*tail)->next = curr;
		curr->prev = (*tail);
		(*tail) = curr;
//	}
	
}

void midPush(char str, struct Node **head, struct Node **tail){
	if(str < (*head)->character){
//		printf("front");
		frontPush(str,head,tail);
	}
	else if(str > (*tail)->character){
//		printf("back");
		backPush(str,head,tail);
	}
	else{
//		printf("mid");
		struct Node *curr = addNode(str);
		struct Node *temp = (*head);
		while(temp->next->character < curr->character && temp->next != NULL){
			temp = temp->next;
		}
		curr->next = temp->next;
		curr->prev = temp;
		curr->next->prev = curr;
		temp->next = curr;
	}
//	printf("hehe\n");
}

void popSwitch(struct Node **head1, struct Node **tail1, struct Node **head2, struct Node **tail2){
	struct Node *temp = (*tail1);
	while(temp->prev != NULL){
		temp = (*tail1)->prev;
		(*tail1)->prev = NULL;
		temp->next = NULL;
		free((*tail1));
		(*tail1) = temp;
		backPush(temp->character,head2,tail2);
	}
//	backPush(temp->character,head2,tail2);
	(*head1) = (*tail1) = NULL;
}

void printList(struct Node *head, struct Node *tail){
	struct Node *temp = head;
	while(temp != NULL){
		printf("%c",temp->character);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	struct Node *head1 = NULL;
	struct Node *tail1 = NULL;
	struct Node *head2 = NULL;
	struct Node *tail2 = NULL;
	
//	firstData('e',&head1,&tail1);
//	frontPush('m',&head1,&tail1);
	char text[100];
//	firstData('1',&head1,&tail1);
//	midPush('0',&head1,&tail1);
	scanf("%[^\n]",text);
	int len = strlen(text);
	for(int i=0;i<len;i++){
		if(text[i] == ' '){
//			printf("ye\n");
			if(head2 == NULL){
				firstData(tail1->character, &head2, &tail2);
			}
			else{
				backPush(tail1->character,&head2, &tail2);
			}
			popSwitch(&head1,&tail1,&head2,&tail2);
			backPush(text[i],&head2,&tail2);
//			printList(head2,tail2);
		}
		else{
			if(head1 == NULL){
				firstData(tolower(text[i]),&head1,&tail1);
			}
			else{
				midPush(tolower(text[i]),&head1,&tail1);
			}
		}
		
		
	}
	if(head2 == NULL){
		firstData(tail1->character, &head2, &tail2);
	}
	else{
		backPush(tail1->character,&head2, &tail2);
	}
	popSwitch(&head1,&tail1,&head2,&tail2);
	
	printList(head2,tail2);
 	return 0;
}

