#include <stdio.h>
#include <string.h>

int main()
{
	char yeet[110];
	char nyom;
	do{
		scanf("%s%c",yeet,&nyom);
		printf("Yeet %s \\(^-^)\n",yeet);
	}while(nyom != '\n');
 	return 0;
}

