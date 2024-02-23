#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//struct Name{
//	char name[30];
//};

struct information{
	char name[100];
	char title[50];
	char publisher[30];
	int year;
};

struct Node{
	struct information info;
	struct Node *next;
	struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *addNode(struct information info){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->info = info;
	newNode->next = newNode->prev = NULL;
	return newNode;
}

void insert(struct information info){
	struct Node *newNode = addNode(info);
	if(head == NULL) head = tail = newNode;
	else if(head->info.year <= info.year){
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if(tail->info.year >= info.year){
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else{
		struct Node *temp = head;
		while(temp != NULL && temp->info.year >= info.year) temp = temp->next;
		temp->prev->next = newNode;
		newNode->prev = temp->prev;
		newNode->next = temp;
		temp->prev = newNode;
	}
}

void delFunc(struct Node *temp){
	if(head == NULL){
		return;
	}
	else if(head == tail){
		head = tail = NULL;
	}
	else if(temp == head){
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
	else if(temp == tail){
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
	}
	else{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
}

void del(char op,int year){
	struct Node *temp = head;
	if(op == '='){
		while(temp != NULL){
			if(temp->info.year == year){
				delFunc(temp);
			}
			temp = temp->next;
		}
	}
	else if(op == '>'){
		while(temp != NULL){
			if(temp->info.year > year){
				delFunc(temp);
			}
			temp = temp->next;
		}
	}
	else if(op == '<'){
		while(temp != NULL){
			if(temp->info.year < year){
				delFunc(temp);
			}
			temp = temp->next;
		}
	}
}


int nameVal(char str[], int len){
	int count = 0;
	int hash = 1;
	for(int i=0; i<len; i++){
		if(isalpha(str[i]) != 0) hash = 0;
		else if(str[i] == '#' && hash == 0){
			hash = 1;
			count++;	
		} 
		else if(str[i] == '#' && hash == 1) return -1;
	}
	if(count > 2) return -1;
	else return count;
}

void printName(char str[]){
	int len = strlen(str);
	int hash = nameVal(str,len);
	int tag = 1;
	int count = 0;
	int first = 1;
	for(int i=0; i<len; i++){
		if(str[i] == ' ' && tag == 1) continue;
		if(first == 1 && tag == 1){
			printf("%c.",str[i]);
			tag = 0;
		}
		else if(first == 1 && str[i] != ' ') continue;
		else if(str[i] == ' '){
			printf(" ");
			first = 0;
		}
		else if(str[i] == '#' && count == hash - 2){
			first = 1;
			tag = 1;
			count++;
			printf(", ");
		}
		else if(str[i] == '#' && count == hash - 1){
			if(hash == 2) printf(", and ");
			else if(hash == 1) printf(" and ");
			first = 1;
			tag = 1;
		}
		else{
			tag = 0;
			printf("%c",str[i]);
		}
	}
	printf(", ");
}

void update(char str[]){
	struct Node *temp = head;
	while(temp != NULL){
		if(strstr(temp->info.title,str) != NULL){
			printf("-----------------------------------------------------------------------\n");
			printName(temp->info.name);
			printf("\"%s\", %s, %d\n",temp->info.title, temp->info.publisher, temp->info.year);
			printf("-----------------------------------------------------------------------\n");
			printf("Insert New Title: ");
			char newTitle[50];
			scanf("%[^\n]",newTitle); getchar();
			strcpy(temp->info.title,newTitle);
			return;
		}
		temp = temp->next;
	}
	printf("Journal Not Found!\n");
	printf("Press Enter to Continue . . ."); getchar();
}

void view(){
	int flag = 0;
	struct Node *temp = head;
	while(temp != NULL){
		if(flag == 0){
			printf("Journal Library\n");
			printf("=======================================================================\n");
			flag = 1;
		}
		printName(temp->info.name);
		printf("\"%s\", %s, %d\n",temp->info.title, temp->info.publisher, temp->info.year);
		printf("-----------------------------------------------------------------------\n");
		temp = temp->next;
	}
	if(flag == 0){
		printf("Journal Library is Currently Empty\n");
		printf("=======================================================================\n");
	} 
	printf("\n");
}

int main()
{
	int opt;
	while(1){
		struct information info;
		int hashtag;
		int len;
		system("cls");
		view();
		printf("==============================\n");
		printf("| Journal Library            |\n");
		printf("==============================\n");
		printf("| 1. Insert                  |\n");
		printf("| 2. Delete                  |\n");
		printf("| 3. Update                  |\n");
		printf("| 4. Exit                    |\n");
		printf("==============================\n");
		scanf("%d",&opt);
		getchar();
		switch(opt){
			case 1:
				do{
					printf("Input Authors[Seperate by #, max 3]: ");
					scanf("%[^\n]",info.name); getchar();
					len = strlen(info.name);
				}while(nameVal(info.name,len) == -1);
				printf("Input Journal title: ");
				scanf("%[^\n]",info.title); getchar();
				printf("Input Journal publisher: ");
				scanf("%[^\n]",info.publisher); getchar();
				printf("Input Publication Year: ",info.year);
				scanf("%d",&info.year); getchar();
				insert(info);
				break;
			case 2:
				char op;
				int year;
				do{
					printf("Which Years do you want to delete[=|>|<(year)]: ");
					scanf("%c%d",&op,&year); getchar();
				}while(op != '=' && op != '>' && op != '<');
				del(op,year);
				break;
			case 3:
				char search[50];
				printf("Input the Journal Title to Search: ");
				scanf("%[^\n]",search); getchar();
				update(search);
				break;
			case 4:
				printf("Program Finished!\n");
				return 0;
		}
	}
 	return 0;
}

