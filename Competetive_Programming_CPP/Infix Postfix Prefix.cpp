#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	int op;
	struct Node *next;
};

struct opNode{
	char opr;
	struct opNode *next;
};

//struct Node *head = NULL;
//struct Node *tail = NULL;
struct Node *top = NULL;

struct opNode *opTop = NULL;

struct Node *addNode(int val){
	struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
	curr->op = val;
	curr->next = NULL;
	return curr;
}

struct opNode *addNodeOp(char val){
	struct opNode *curr = (struct opNode *)malloc(sizeof(struct opNode));
	curr->opr = val;
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

void firstDataOp(char val){
	struct opNode *curr = addNodeOp(val);
	opTop = curr;
}

void addStackOp(char val){
	if(opTop == NULL){
		firstDataOp(val);
	}
	else{
		struct opNode *curr = addNodeOp(val);
		curr->next = opTop;
		opTop = curr;
	}
	
}

int rmvStack(){
	if(top == NULL){
//		printf("top is null\n");
		return NULL;
	}
	int num = top->op;
	if(top->next == NULL){
		free(top);
		top = NULL;
	}
	else{
		struct Node *curr = top->next;
		top->next = NULL;
		free(top);
		top = curr;
	}
	return num;
}

char rmvStackOp(){
	if(opTop == NULL){
//		printf("top is null\n");
		return NULL;
	}
	char num = opTop->opr;
	if(opTop->next == NULL){
		free(opTop);
		opTop = NULL;
	}
	else{
		struct opNode *curr = opTop->next;
		opTop->next = NULL;
		free(opTop);
		opTop = curr;
	}
	return num;
}

void rmvAll(){
	while(top != NULL){
		struct Node *curr = top->next;
		top->next = NULL;
		free(top);
		top = curr;	
	}
	top = NULL;
	free(top);
}

void rmvAllOp(){
	while(opTop != NULL){
		struct opNode *curr = opTop->next;
		opTop->next = NULL;
		free(opTop);
		opTop = curr;	
	}
	opTop = NULL;
	free(opTop);
}

int priority(char opr){
	switch(opr){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return 0;
}

int calc(int a, int b, char opr){
	switch(opr){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '^':
			return int(pow(a,b));
	}
}

void infix(char str[]){
	int len = strlen(str);
	int check = true;
//	printf("len: %d\n",len);
	int bracket = 0;
	for(int i=0;i<len;i++){
//		printf("i = %d\n",i);
//		printf("str[i] = \'%c\'\n",str[i]);
		if(str[i] == ' ') continue;
		else if(str[i] >= '0' && str[i] <= '9'){
			check = false;
			int mult = 10;
			int val = int(str[i++] - '0');
			while(i != len && str[i] >= '0' && str[i] <= '9'){
//				printf("val: %d\n",val);
				val *= mult;
				val+= (int(str[i++]) - '0');
			}
			i--;
//			printf("val: %d\n",val);
			addStack(val);
		}
		else if(str[i] == '('){
			check = false;
			bracket++;
			addStackOp(str[i]);
		} 
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			if(check == true){
				printf("Invalid Notation!\n");
				return;
			}
			check = true;
			if(opTop == NULL || opTop->next == NULL || priority(str[i]) >= priority(opTop->opr)){
//				printf("Opr : %c\n", str[i]);
				addStackOp(str[i]);
			}
			else{
				while(opTop != NULL && opTop->opr != '('){
					int temp = rmvStack();
					int temp2 = rmvStack();
					if(temp2 == NULL){
						printf("Invalid Notation!\n");
						return;
					}
					char oprtr = rmvStackOp();
					addStack(calc(temp2,temp,oprtr));
				}
			}
		}
		else if(str[i] == ')'){
			check = false;
			if(bracket < 1){
				printf("Invalid Notation!\n");
				return;
			}
			else{
				bracket--;
				while(opTop->opr != '('){
					int temp = rmvStack();
					int temp2 = rmvStack();
					if(temp2 == NULL){
						printf("Invalid Notation!\n");
						return;
					}
					char oprtr = rmvStackOp();
					addStack(calc(temp2,temp,oprtr));
				}
				rmvStackOp();
			}
		}
		else{
			printf("Invalid Notation!\n");
			return;
		}
		
	}
	while(opTop != NULL){	
				int temp = rmvStack();
				int temp2 = rmvStack();
				if(temp2 == NULL){
					printf("Invalid Notation!\n");
					return;
				}
				char oprtr = rmvStackOp();
				addStack(calc(temp2,temp,oprtr));
		}
	if(top->next == NULL){
		printf("Result : %d\n",top->op);
	}
	else{
		printf("Invalid Notation!\n");
		return;
	}
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
		return;
	}
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
				rmvAll();
				break;
			case 2:
				printf("Enter The Postfix Notation:\n");
				scanf("%[^\n]",operation);
				getchar();
				postfix(operation);
				rmvAll();
				break;
			case 3:
				printf("Enter The Infix Notation:\n");
				scanf("%[^\n]",operation);
				getchar();
				infix(operation);
				rmvAll();
				rmvAllOp();
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

