#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test); getchar();
	for(int i=0;i<test;i++){
		char str[1010];
		char reverse[1010]={00};
		scanf("%[^\n]",str); getchar();
		int len=strlen(str);
		for(int j=0;j<len;j++){
			reverse[j]=str[len-1-j];
		}
		printf("%s\n",reverse);
	}
 	return 0;
}

