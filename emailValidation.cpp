#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valEmail(char name[]){
	int len = strlen(name);
	if(len < 10 || len > 20){
		printf("Wrong Length\n");
		return 0;
	}
	int foundAt = 0;
	for(int i=0; i<len; i++){
		if(name[i] == '@'){
			if(foundAt){
				printf("Duplicate @\n");
				return 0;
			}
			else{
				foundAt = 1;
			}
		}
	}
	if(!foundAt){
		printf("@ not Found\n");
		return 0;
	}
	
	if(strstr(name,".com") != NULL && strcmp(strstr(name,".com"),".com") == 0){
		return 1;
	}
	if(strstr(name,".co.id") != NULL && strcmp(strstr(name,".co.id"),".co.id") == 0){
		return 1;
	}
	printf("Email must end with .com or .co.id\n");
	return 0;
}

int main()
{
	while(1){
		printf("Name:\n");
		char name[30];
		scanf("%[^\n]",name); getchar();
		if(valEmail(name)){
			printf("Valid email\n");
		}
	}
	
 	return 0;
}

