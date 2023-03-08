#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	int op;
	struct Node *next;
};

//struct Node *head = NULL;
//struct Node *tail = NULL;
struct Node *top = NULL;

struct Node *addNode(int val){
	struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
	curr->op = val;
	curr->next = NULL;
	return curr;
}

void firstData(int val){
	struct Node *curr = addNode(val);
	top = curr;
}

void addStack(int val){
	if(top == NULL){
		firstData(val);
	}
	else{
		struct Node *curr = addNode(val);
		curr->next = top;
		top = curr;
	}
	
}

int rmvStack(){
	if(top == NULL){
//		printf("top is null\n");
		return NULL;
	}
	int num = top->op;
	if(top->next == NULL){
		top = NULL;
		free(top);
	}
	else{
		struct Node *curr = top->next;
		top->next = NULL;
		free(top);
		top = curr;
	}
	return num;
}

void rmvAll(){
	while(top->next != NULL){
		struct Node *curr = top->next;
		top->next = NULL;
		free(top);
		top = curr;	
	}
	top = NULL;
	free(top);
}

void postfix(char str[]){
	int len = strlen(str);
	for(int i=0;i<len;i++){
		int temp, temp2;
		if(str[i] == ' ') continue;
		else if(str[i] >= '0' && str[i] <= '9'){
			int mult = 10;
			int val = int(str[i++] - '0');
			while(i != len && str[i] >= '0' && str[i] <= '9'){
//				printf("val: %d\n",val);
				val *= mult;
				val+= (int(str[i++]) - '0');
			}
			addStack(val);
		} 
		else if(str[i] == '+'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2+temp);
		}
		else if(str[i] == '-'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2-temp);
		}
		else if(str[i] == '*'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2*temp);
		}
		else if(str[i] == '/'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2/temp);
		}
		else if(str[i] == '^'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(pow(temp2,temp));
		}
		else{
			printf("Invalid Notation!\n");
			return;
		}
	}
	if(top->next == NULL){
		printf("Result : %d\n",top->op);
	}
	else{
		printf("Invalid Notation!\n");
	}
	rmvAll();
}

void prefix(char str[]){
	int len = strlen(str);
	for(int i=len-1;i>=0;i--){
		int temp, temp2;
		if(str[i] == ' ') continue;
		else if(str[i] >= '0' && str[i] <= '9'){
			int mult = 1;
			int val = 0;
			while(i != -1 && str[i] >= '0' && str[i] <= '9'){
				val += (int(str[i--]) - '0') * mult;
				mult *= 10;
			}
			addStack(val);
		} 
		else if(str[i] == '+'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2+temp);
		}
		else if(str[i] == '-'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2-temp);
		}
		else if(str[i] == '*'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2*temp);
		}
		else if(str[i] == '/'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(temp2/temp);
		}
		else if(str[i] == '^'){
			temp = rmvStack();
			temp2 = rmvStack();
			if(temp == NULL || temp2 == NULL){
				printf("Invalid Notation!\n");
				return;
			}
			addStack(pow(temp2,temp));
		}
		else{
			printf("Invalid Notation!\n");
			return;
		}
	}
	if(top->next == NULL){
		printf("Result : %d\n",top->op);
	}
	else{
		printf("Invalid Notation!\n");
	}
	rmvAll();
}

void par(char str[], int idx){
	
}

void infix(char str[]){
	
}

int main()
{
	printf("=============================\n");
	printf("| Which Notation?           |\n");
	printf("| (Seperate op with spaces) |\n");
	printf("=============================\n");
	printf("| 1. Prefix                 |\n");
	printf("| 2. Postfix                |\n");
	printf("| 3. Infix                  |\n");
	printf("| 4. Exit                   |\n");
	printf("=============================\n");
	
	int option;
	char operation[110];
	do{
		scanf("%d",&option);
		getchar();
		switch(option){
			case 1:
				printf("Enter The Prefix Notation:\n");
				scanf("%[^\n]",operation);
				getchar();
				prefix(operation);
				break;
			case 2:
				printf("Enter The Postfix Notation:\n");
				scanf("%[^\n]",operation);
				getchar();
				postfix(operation);
				break;
			case 3:
				printf("Enter The Infix Notation:\n");
				scanf("%[^\n]",operation);
				getchar();
//				infix(operation);
				break;
			case 4:
				printf("Program Finished\n");
				break;
			default:
				printf("Unknown Command, Try Again!\n");
				break;
		}	
	}while (option != 4);
	
 	return 0;
}

