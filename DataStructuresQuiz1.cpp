#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

/*
1. what is the difference and similiarities between arrays and pointers? give example

Difference:
pointers point to a certain value and provide the address while arrays store certain values of the same datatype.
Arrays have multiple values while pointers only store one value, which is the address of the value
Ex: 

int x = 2;
int *px = &x;
int arr[11];
for(int i=0;i<11;i++){
	arr[i] = x+i;
}

when you print,

printf("%d\n",px); --> this will print the address of x

for(int i=0;i<11;i++){
	printf("%d\n",arr[i]); --> this will print the values of the array one by one
}

Similiarities:
Arrays are a type of pointers
Ex:
when you scan a string, you don't have to use & [scanf("%s",string)]

2. if there is number
1, 5, 6, 7, 9, 12
push front,single pointer.
make the code. what is the output of the code?

3. Make a code that can do sort number while push
 if(lesser) push depan
 	if mid push tengtah
 		if bigger push tail

*/

struct Node{
	int value;
	struct Node *next;
};

int main()
{
	struct Node *head = NULL;
	struct Node *tail = NULL;
	
	struct Node *curr = (struct Node*)malloc(sizeof(struct Node));
	do{
		scanf("%d",&curr->value);
	if(head==NULL){
		head = curr;
		tail = curr;
		tail->next = NULL;
	}
	else{
		if(curr->value < head->value){
		curr->next=head;
		head=curr;
		}
		else if(curr->value > tail->value){
			tail->next = curr;
			tail = curr;
			tail->next = NULL;
		}
//		else{
//			struct Node *tempy = head;
//			while(tempy->next != NULL && tempy->next->value < curr->value){
//				tempy=tempy->next;
//				curr->next = tempy->next;
//				tempy->next = curr;
//			}
//		}
	
		
	}
	struct Node *temp = head;
		while(temp != NULL){
			printf("%d ",temp->value);
			temp = temp->next;
		}
	printf("\n");
	} while(curr->value != 0);
	
	
 	return 0;
}

