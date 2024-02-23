#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char op;
    struct Node *next;
};

struct Node *oprtr = NULL;

struct Node *addNode(char op){
    struct Node *curr = (struct Node*)malloc(sizeof(struct Node));
    curr->op = op;
    curr->next = NULL;
    return curr;
}


void firstData(char op){
	struct Node *curr = addNode(op);
	oprtr = curr;
}

void addStack(char op){
	if(oprtr == NULL){
		firstData(op);
	}
	else{
		struct Node *curr = addNode(op);
    	curr->next = oprtr;
    	oprtr = curr;
    }
}

char rmvStack(){
    if (oprtr == NULL) {
        printf("Invalid Expression\n");
        exit(1);
    }
    char val = oprtr->op;
    if(oprtr->next == NULL){
    	oprtr = NULL;
		free(oprtr);
	}
	else{
		struct Node *curr = oprtr->next;
		oprtr->next = NULL;
		free(oprtr);
		oprtr = curr;
	}
	return val;
}

int priority(char op){
    switch (op) {
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
        default:
            return 0;
    }
}

void infixPost(char str[]){
	int len = strlen(str);
	char *post = (char *)malloc(sizeof(char)*len);
	int j = 0;
	for(int i=0; i<len; i++){
		if(str[i] == ' '){
			continue;
		}
		else if(str[i] >= '0' && str[i] <= '9'){
			post[j++] = str[i];
		}
		else if(str[i] == '('){
			addStack(str[i]);
		}
		else if(str[i] == ')'){
			while(oprtr != NULL && oprtr->op != '('){
				char temp = rmvStack();
				post[j++] = temp;
			}
			if(oprtr == NULL){
				printf("No Opening Parenthesis\n");
				exit(1);
			}
			else{
				rmvStack();
			}
		}
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			while(oprtr != NULL && oprtr->op != '(' && priority(str[i]) <= priority(oprtr->op)){
                char temp = rmvStack();
                post[j++] = temp;
            }
            addStack(str[i]);
		}
	}
	while(oprtr != NULL){
		char temp = rmvStack();
		post[j++] = temp;
	}
	printf("Postfix: ");
	for(int i=0; i<=j; i++){
		printf("%c",post[i]);
	}
	printf("\n");
}

void infixPre(char str[]){
    int len = strlen(str);
    char *pre = (char *)malloc(sizeof(char)*len);
    int j = 0;
    for (int i=len-1; i>=0; i--){ 
        if(str[i] == ' '){
            continue;
        }
		else if(str[i] >= '0' && str[i] <= '9'){
            pre[j++] = str[i];
        }
		else if(str[i] == ')'){
            addStack(str[i]);
        }
		else if (str[i] == '('){
            while (oprtr != NULL && oprtr->op != ')'){
                char temp = rmvStack();
                pre[j++] = temp;
            }
            if(oprtr == NULL){
                printf("No Closing Parenthesis\n");
                exit(1);
            }
            else{
            	rmvStack();
			}
        } 
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
            while(oprtr != NULL && oprtr->op != ')' && priority(str[i]) < priority(oprtr->op)){
                char temp = rmvStack();
                pre[j++] = temp;
            }
            addStack(str[i]);
        }
    }
    while(oprtr != NULL){
        char temp = rmvStack();
        pre[j++] = temp;
    }
    printf("Prefix : ");
    for(int i=j-1; i>=0; i--){
        printf("%c", pre[i]);
    }
    printf("\n");
}


int main()
{
	char str[1000];
	printf("Input an Infix Expression (Single Digits)\n");
	scanf("%[^\n]", str);
	infixPost(str);
	infixPre(str);
 	return 0;
}

