#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int proceed;
	
	do{
		char str[100];
		char sub[100];
		printf("Input String:\n");
		scanf("%s",str);
		printf("Input Substring:\n");
		scanf("%s",sub);
		
		if(strstr(str,sub) == NULL){
			printf("Substring Not Found!\n");
		}
		else if(strcmp(strstr(str,sub),sub) == 0){
			printf("SubString is in the back of the string\n");
			printf("%s\n",strstr(str,sub));
		}
		else if(strcmp(strstr(str,sub),str) == 0){
			printf("SubString is in the front of the string\n");
			printf("%s\n",strstr(str,sub));
		}
		else{
			printf("Substring is in the middle of the string\n");
			printf("%s\n",strstr(str,sub));
		}
		
		printf("Proceed? [0] | [1]\n");
		scanf("%d",&proceed);
			
	}while(proceed != 0);
 	return 0;
}

