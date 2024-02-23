#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=0;i<test;i++){
		char text[1010];
		scanf("%s",text);
		printf("Case #%d : ",i+1);
		int length = strlen(text);
		for(int j=1;j<=length;j++){
			printf("%c",text[length-j]);
		}
		printf("\n");
	}
 	return 0;
}

