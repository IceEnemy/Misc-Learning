#include <stdio.h>

int main()
{
	char word1[25];
	char word2[25];
	char word3[25];
	for(int i=0;i<2;i++){
		scanf("%s %s %s",word1,word2,word3);
		printf("%sszs %sszs %sszs\n",word1,word2,word3);
	}
	
 	return 0;
}

