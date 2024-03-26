#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	char op;
	struct Node *next;
};

//struct opNode{
//	char opr;
//	struct opNode *next;
//};

//struct Node *head = NULL;
//struct Node *tail = NULL;
struct Node *top = NULL;

struct Node *opTop = NULL;

struct Node *postTop = NULL;

struct Node *addNode(char val){
	struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
	curr->op = val;
	curr->next = NULL;
	return curr;
}

void firstData(char val){
	struct Node *curr = addNode(val);
	top = curr;
}

void firstDataOp(char val){
	struct Node *curr = addNode(val);
	opTop = curr;
}

void firstDataPost(char val){
	struct Node *curr = addNode(val);
	postTop = curr;
}

void addStack(char val){
	if(top == NULL){
		firstData(val);
		printf("valfirst : %c\n",val);
	}
	else{
		printf("val : %c\n",val);
		struct Node *curr = addNode(val);
		curr->next = top;
		top = curr;
	}
}

void addStackOp(char val){
	if(opTop == NULL){
		firstDataOp(val);
	}
	else{
		struct Node *curr = addNode(val);
		curr->next = opTop;
		opTop = curr;
	}
}

void addStackPost(char val){
	if(postTop == NULL){
		firstDataPost(val);
	}
	else{
		struct Node *curr = addNode(val);
		curr->next = postTop;
		postTop = curr;
	}
	
}

char rmvStack(){
	if(top == NULL){
//		printf("top is null\n");
		return NULL;
	}
	char num = top->op;
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
	char num = opTop->op;
	if(opTop->next == NULL){
		free(opTop);
		opTop = NULL;
	}
	else{
		struct Node *curr = opTop->next;
		opTop->next = NULL;
		free(opTop);
		opTop = curr;
	}
	return num;
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

void pushPost(char n){
	
}

void calc(char a, char b, char opr){
	addStackPost(a);
	addStackPost(b);
	addStackPost(opr);
}

void print(){
	printf("num:{ ");
	struct Node *temp = top;
	while(temp != NULL){
		printf("%c ",temp->op);
		temp = temp->next;
	}
	printf("}\n");
	printf("Op:{ ");
	struct Node *tempOp = opTop;
	while(tempOp != NULL){
		printf("%c ",tempOp->op);
		tempOp = tempOp->next;
	}
	printf("}\n");
}

void print2(){
	struct Node *temp = postTop;
	printf("Postfix : [");
	while(temp != NULL){
		printf("%c ",temp->op);
		temp = temp->next;
	}
	printf("]\n");
}

void infix(char str[]){
	int len = strlen(str);
	int check = true;
	int bracket = 0;
	for(int i=0;i<len;i++){
		printf("i = %d\n",i);
		if(str[i] >= '0' && str[i] <= '9'){
			check = false;
			printf("%c\n",str[i]);
			addStack(str[i]);
		}
		else if(str[i] == '('){
			check = false;
			bracket++;
			addStackOp(str[i]);
		} 
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			if(check == true){
				printf("Can't have operator after operator!'!\n");
				return;
			}
			check = true;
			if(opTop == NULL || priority(str[i]) >= priority(opTop->op)){
//				printf("Opr : %c\n", str[i]);
				addStackOp(str[i]);
			}
			else{
				while(opTop != NULL && opTop->op != '('){
					char temp = rmvStack();
					char temp2 = rmvStack();
					if(temp2 == NULL){
						char oprtr = rmvStackOp();
						addStackPost(temp);
						addStackPost(oprtr);
					}
					char oprtr = rmvStackOp();
					calc(temp2,temp,oprtr);
				}
				addStackOp(str[i]);
			}
		}
		else if(str[i] == ')'){
			check = false;
			if(bracket < 1){
				printf("Not enough opening parenthesis!\n");
				return;
			}
			else{
				bracket--;
				while(opTop->op != '('){
					char temp = rmvStack();
					char temp2 = rmvStack();
					if(temp2 == NULL){
						char oprtr = rmvStackOp();
						addStackPost(temp);
						addStackPost(oprtr);
					}
					char oprtr = rmvStackOp();
					calc(temp2,temp,oprtr);
				}
				rmvStackOp();
			}
		}
		else{
			printf("Unknown Character Input!\n");
			return;
		}
		print();
	}
	while(opTop != NULL){	
				char temp = rmvStack();
				char temp2 = rmvStack();
				if(temp2 == NULL){
					char oprtr = rmvStackOp();
					addStackPost(temp);
					addStackPost(oprtr);
				}
				else{
					char oprtr = rmvStackOp();
					calc(temp2,temp,oprtr);
				}
				
		}
	if(top == NULL){
		print2();
	}
	else{
		printf("Not enough operators!\n");
		return;
	}
}



int main()
{
	printf("============================================\n");
	printf("| Enter an Infix Notation! (single digits) |\n");
	printf("============================================\n");

	char operation[110];
	scanf("%[^\n]",operation);
	infix(operation);
	
 	return 0;
}




