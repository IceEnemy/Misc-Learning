#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
//	char hehe[100];
////	int id;
//	char mr[100];
//	scanf("%[^\n]",mr); getchar();
//	sprintf(hehe,"Mr.%s",mr);
//	printf("%s",hehe);
	
	char test1[10],test2[10];
	strcpy(test1,"Hey");
	strcpy(test2,"hey");
	
	int check = strcmp(test1,test2);
	printf("strcmp:\n");
	if(check == 0){
		printf("same\n");
	}
	else{
		printf("Different\n");
	}
	
	check = strcmpi(test1,test2);
	printf("strcmpi:\n");
	if(check == 0){
		printf("same\n");
	}
	else{
		printf("Different\n");
	}
	
	for(int i=0; i<strlen(test1); i++){
		test1[i] = tolower(test1[i]);
	}
	printf("%s\n",test1);
	
 	return 0;
}

