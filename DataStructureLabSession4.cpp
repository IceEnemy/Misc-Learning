#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



struct Node{
	char ID[7]; //ST001
	char name[30];
	int age;
	struct Node *next;
};

int inc = 1;
const int MAX_ELEMENT = 2;
Node *hashTable[MAX_ELEMENT];

Node *addNode(char name[], int age){
	Node *curr = (Node *)malloc(sizeof(Node));
	strcpy(curr->name,name);
	
	curr->age = age;
	//id is random or incremental
//	sprintf(curr->ID, "ST%03d", 1 + rand() % 100);
	//incremental
	
	sprintf(curr->ID, "ST%03d",inc++);
//	printf("%x\n",curr);
//	printf("addNode: %s\n",curr->name);
	curr->next = NULL;
	
	return curr;
}



void prepTable(){
	for(int i=0;i<MAX_ELEMENT;i++){
		hashTable[i] = NULL;
	}
}

int hashing(char str[]){
	int num = 0;
	for(int i=0;i<strlen(str); i++){
		num+= str[i];
	}
	return num % MAX_ELEMENT;
}

void insert(char name[],int age){
	Node *curr = addNode(name,age);
	int idx = hashing(curr->ID);
//	printf("What it should be: %s\n",curr->name);
//	printf("insert: %x\n",curr);
//	printf("%d",hashing(curr->ID));
	//Linked List
	if(hashTable[idx] == NULL){
		hashTable[idx] = curr;
	}
	else{
		Node *temp = hashTable[idx];
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = curr;
		
	}
}

void pop(char id[]){
	int idx = hashing(id);
	if(hashTable[idx] == NULL){
		return;
	}
	else if(strcmp(hashTable[idx]->ID, id) == 0){
		Node *temp = hashTable[idx]->next;
		free(hashTable[idx]);
		hashTable[idx] = temp;
	}
	else{
		Node *curr = hashTable[idx];
		while(curr->next != NULL){
			if(strcmp(curr->next->ID,id) == 0){
				Node *temp = curr->next->next;
				free(curr->next);
				curr->next = temp;
				return;
			}
			curr = curr->next;
		}
		
	}
}

void popAll(){
	for(int i=0;i<MAX_ELEMENT;i++){
		while(hashTable[i] != NULL){
			Node *temp = hashTable[i]->next;
			free(hashTable[i]);
			hashTable[i] = temp;
		}
	}
}

Node *searchID(char id[]){
	int idx = hashing(id);
	Node *curr = hashTable[idx];
	while(curr != NULL){
		if(strcmp(curr->ID,id) == 0){
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

Node *searchName(char name[]){
	for(int i=0;i<MAX_ELEMENT;i++){
		Node *curr = hashTable[i];
		while(curr != NULL){
			if(strcmp(curr->name,name) == 0){
				return curr;
			}
		curr = curr->next;
		}
	}
	
	return NULL;
}

void printList(){
	for(int i=0;i<MAX_ELEMENT;i++){
		printf("%d: ",i);
		Node *curr = hashTable[i];
		while(curr != NULL){
			printf("(%s): %s, %d ---> ",curr->ID,curr->name,curr->age);
			curr= curr->next;
		}
		printf("NULL\n");
	}
	printf("\n");
}

void printTidy(){
	printf("==================================");
	printf("| ID  | Name               | Age |");
	printf("==================================");
	for(int i=0;i<MAX_ELEMENT;i++){
		printf("|%-5d|")
	}
}

int main()
{
//	srand(time(NULL)); --> random every second
//	char test[5] = "test";
//	Node *a = addNode(test,9);
//	printf("%s\n", a->ID);
//	char test2[5] = "test";
//	Node *b = addNode(test2,9);
//	printf("%s\n", b->ID);
	prepTable();
	char test[5] = "test";
	insert(test, 5);
	printList();
//	printf("%s, %s\n",hashTable[0]->ID,hashTable[0]->name);
	insert("test2",9);
	printList();
	insert("test3",12);
	printList();
	pop("ST001");
	printList();
	printf("%d\n",searchID("ST003"));
	printf("%s\n",searchName("test2")->ID);
	popAll();
	printList();
 	return 0;
}

