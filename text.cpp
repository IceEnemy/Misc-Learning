#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	getchar();
	for(int i=1;i<=test;i++){
		char text[1010];
		scanf("%[^\n]",text);
		getchar();
		int len=strlen(text);
		printf("Case #%d: ",i);
		for(int j=0;j<len;j++){
			if(text[j]!='a' && text[j]!='i' && text[j]!='u' && text[j]!='e' && text[j]!='o' && text[j]!='A' && text[j]!='I' && text[j]!='U' && text[j]!='E' && text[j]!='O'){
				printf("%c",text[j]);
			}
		}
		printf("\n");
	}
 	return 0;
}

