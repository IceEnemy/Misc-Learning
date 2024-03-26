#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		char text[1010];
		scanf("%s",text);
		printf("Case %d: ",i);
		for(int j=0;j<strlen(text);j++){
			if(j<strlen(text)-1){
				printf("%d-",text[j]);
			}
			else{
				printf("%d\n",text[j]);
			}
		}
	}
 	return 0;
}

