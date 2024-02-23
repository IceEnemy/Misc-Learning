#include <stdio.h>

int main()
{
	int dec;
	scanf("%d",&dec);
	while(dec>0){
	printf("%d",dec&1);
	dec>>=1;
	}
 	return 0;
}

