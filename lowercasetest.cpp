#include <stdio.h>
int main()
{
	long int test, length;
	scanf("%ld",&test);
	for(int i=1;i<=test;i++){
		scanf("%ld",&length);
		getchar();
		char text[length];
		scanf("%[^\n]",text);
		getchar();
		printf("Case #%d: ",i);
		for(int j=0;j<length;j++){
			if(text[j]>='a' && text[j]<='z'){
				printf("%c",text[j]);
			}
		}
		printf("\n");
	}
 	return 0;
}
