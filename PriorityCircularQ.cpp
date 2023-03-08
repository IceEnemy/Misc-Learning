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
	}
	printf("Added %d to Queue!\n",val);
}

void dq() {
    if (head == NULL) {
        printf("Queue is Already Empty!\n");
    } else if (head == tail) {
        printf("Removed %d\n", head->value);    
        head = tail = NULL;
        free(head);
    } else {
        int max = NULL;
        struct Node *temp = head;
        do {
            if (max == NULL || max < temp->value) {
                max = temp->value;
            }
            temp = temp->next;
        } while (temp != head);
        temp = tail;
        struct Node *temp2;
        do {
            if (temp->next->value == max) {
                if (temp->next == head) {
                    head = head->next;
                } else if (temp->next == tail) {
                    tail = temp;
                }
                temp2 = temp->next;
                temp->next = temp2->next;
                printf("Removed %d\n", temp2->value);
                free(temp2);
                return;
            }
            temp = temp->next;
        } while (temp != tail);
    }
}

void viewQ(){
	if(head == NULL){
		printf("Queue is Empty!\n");
	}
	else if(head == tail){
		printf("%d\n",head->value);
	}
	else{
		struct Node *temp = head;
		do{
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
	printf("| Priority: Largest int   |\n");
	printf("===========================\n");
	printf("| Commands:               |\n");
	printf("| \"q (int)\" to add        |\n");
	printf("| \"dq\" to dequeue         |\n");
	printf("| \"view\" to view queue    |\n");
	printf("| \"exit\" to stop          |\n");
	printf("===========================\n");

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


