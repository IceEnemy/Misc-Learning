#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
	srand(time(NULL));
	printf("%d\n",1+rand()%100);
	
	printf("Game Name: ");
	char name[30];
	scanf("%[^\n]",name); getchar();
	
	printf("Game Genre: ");
	char genre[10];
	scanf("%[^\n]",genre); getchar();
	
	char id[10];
	sprintf(id,"%c%c%03d",toupper(name[0]), toupper(genre[0]), 1+rand()%99);
	printf("%s\n",id);
	
 	return 0;
}

