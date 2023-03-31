#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

const int MAX = 1007; 
int randNum;
int data = 0; 

struct Node{
	char title[30];
	char author[30];
	char isbn[30];
	int page;
	char id[30]; 
	Node* next;
};
Node* head[MAX];
Node* tail[MAX];

Node* createNode(char title[], char author[], char isbn[], int page, char id[]){
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->title, title);
	strcpy(newNode->author, author);
	strcpy(newNode->isbn, isbn);
	strcpy(newNode->id, id);
	newNode->page = page;
	newNode->next = NULL;
	return newNode; 
}

int hashing(char id[]){
	int length = strlen(id); 
	int hash = 0; 
	for(int i = 0; i < length; i++){
		hash += id[i];
	}
	return hash%MAX; 
}

void pushTail(char title[], char author[], char isbn[], int page, char id[]){
	int idx = hashing(id);
	Node* newNode = createNode(title, author, isbn, page, id); 
	if(head[idx] == NULL){
		head[idx] = tail[idx] = newNode;
	}
	else{
		tail[idx]->next = newNode; 
		tail[idx] = newNode; 
	}
}

void pop(char target[]){ //3 anak, 3 cucu
	int idx = hashing(target);
	if(head[idx] == NULL){ //no node
		puts("There is no books(s)!"); return; 
	}
	else if(head[idx] == tail[idx] && (strcmp(head[idx]->id, target) == 0)){ //one node
		head[idx] = tail[idx] = NULL;
		free(head[idx]); 
	}
	else{
		Node* curr = head[idx]; 
		while(curr != NULL){
			if(strcmp(curr->id, target) == 0){
				//pop mid : 3 conditions 
				if(curr == head[idx]){ //pop head[idx] 
					Node* temp = head[idx]->next; 
					head[idx]->next = NULL;
					free(head[idx]);
					head[idx] = temp; 
				}
				else if(curr == tail[idx]){ //pop tail[idx] 
					Node* temp = head[idx]; 
					while(temp != tail[idx]){
						temp = temp->next; 
					}
					temp->next = NULL; 
					free(tail[idx]);
					tail[idx] = temp; 
				}
				else{//pop mid
					Node* temp = head[idx]; 
					while(temp != curr){
						temp = temp->next; 
					}
					temp->next = curr->next;
					temp->next = NULL; 
					free(curr); 
				}
			}
			curr = curr->next;
		}
	}
}

void view(){
	int val = 0;
	for(int i = 0; i < MAX; i++){
		if(head[i] != NULL){
			Node* curr = head[i]; 
			if(val == 0) 
			printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "id", "title", "author", "isbn", "page"); 
			val = 1; 
			
			while(curr != NULL){
				printf("| %-20s | %-20s | %-20s | %-20s | %-20d |\n", curr->id, curr->title, curr->author, curr->isbn, curr->page); 
				curr = curr->next; 
			}
		}
	}puts("");
	
	if(val == 0) puts("There is no book!"); 
	puts("");
	printf("Press ENTER to continue...\n"); getchar();
}

int search(char target[]){
	int flag = 0;
	for(int i = 0; i < MAX; i++){
		Node* curr = head[i]; 
			while(curr != NULL){
				if(strcmp(target, curr->id) == 0){
					flag = 1; return 1; 
					printf(" id:%s\n title:%s\n author:%s\n isbn:%s\n page:%d\n", curr->id, curr->title, curr->author, curr->isbn, curr->page); 
				}
				curr = curr->next;
			}
		}
	
	if(flag == 0) puts("Book not found !"); 
}

void menu(){
	puts(""); 
	puts("Bluejack Library");
	puts("===================");
	puts("1. View Book"); 
	puts("2. Insert Book"); 
	puts("3. Remove Book"); 
	puts("4. Exit");
	printf(">> ");  
}

void idGen(char id[], char isbn[], char author[], char title[]){
	srand(time(NULL));
	author[0] = toupper(author[0]); 
	title[0] = toupper(title[0]);
	
	if(data == 0){
		randNum = rand() % 999 + 1; 
		sprintf(id, "B%03d-%s-%c%c", randNum++, isbn, author[0], title[0]);
	}
	else{
		sprintf(id, "B%03d-%s-%c%c", randNum++, isbn, author[0], title[0]);
	}
}

int titleVal(char title[]){
	int len = strlen(title); 
	if(len < 5 || len > 50) return 1; 

	for(int i = 0; i < MAX; i++){
		Node* curr = head[i]; 
			while(curr != NULL){
				if(strcmp(curr->id, title) == 0){
					return 1; 
				}
				curr = curr->next;
			}
		}

	return 0; 
}

int autVal(char author[], char name[]){
	if((strcmp(author, "Mr.") != 0) && (strcmp(author, "Mrs.") != 0)) return 1; 
	int len = strlen(name); 
	if(len < 3 || len > 25) return 1;
	
	sprintf(author, "%s %s", author, name);
	return 0; 
}

int isbnVal(char isbn[]){
	int len = strlen(isbn); 
	for(int i = 0; i < len; i++){
		if(isbn[i] < '1' && isbn[i] > '9') return 1;
		if (len < 10 || len > 13) return 1; 
	}
	return 0;
}

int pageVal(int page){
	if(page < 16) return 1; 
}

int main(){
	
	while(1){
		menu();
		int option;
		scanf(" %d", &option); getchar(); 
		
		if(option == 1){
			view(); 
		}
		else if(option == 2){
			char title[30];
			char author[30], name[30];
			char isbn[30];
			int page;
			char id[30];
			
			do{
				printf("Title :"); 
				scanf(" %s", title); getchar();
			}while(titleVal(title) == 1); 
			
			do{
				printf("Author :"); 
				scanf(" %s %[^\n]", author, name); getchar();
			}while(autVal(author, name) == 1); 
			
			do{
				printf("ISBN :"); 
				scanf(" %s", isbn); getchar();
			}while(isbnVal(isbn) == 1); 
			
			do{
				printf("Page:"); 
				scanf(" %d", &page);  getchar();
			}while(pageVal(page) == 1); 
			
			idGen(id, isbn, author, title); 
			pushTail(title, author, isbn, page, id); data++; 
			puts("Insert success !");
		}
		else if(option == 3){
			char ans; char bookid[30];
			printf("Input book id to delete: ");
			scanf(" %s", bookid); getchar(); 
			puts("");
			search(bookid); 
			printf("Are you sure [y|n]? ");
			scanf(" %c", &ans); getchar();
			if(tolower(ans) == 'y') pop(bookid); data--; 
			puts("Delete success !");
		}
		else if(option == 4){
			break; 
		}
		else if(option == 5){
			char debugsearch[50];
			scanf(" %s", debugsearch); getchar();
			search(debugsearch); 
		}
	}
	
	return 0;
}

