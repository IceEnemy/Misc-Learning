#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char hooho[10];
	char hehe[10]="hehe";
	sprintf(hooho,"\"%s\"",hehe);
	printf("%s\n",hooho);
 	return 0;
}

