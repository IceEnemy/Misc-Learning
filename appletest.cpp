#include <stdio.h>

int main()
{
	int up,low;
	int min=104;
	scanf("%d %d",&low,&up);
	while(min<low){
		min+=105;
	}
	printf("%d\n",min);
	while(min<=up-105){
		min+=105;
		printf("%d\n",min);
	}
 	return 0;
}

