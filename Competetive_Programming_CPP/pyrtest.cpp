#include <stdio.h>

int main()
{
	int size;
	scanf("%d",&size);
	for(int i=1;i<=size;i++){
		int var = 0;
		for(int j=1;j<=size-i;j++){
			printf(".");
		}
		while(var < 2*i - 1){
			printf("*");
			var++;
		}
		for(int j=1;j<=size-i;j++){
			printf(".");
		}
		printf("\n");
	}
 	return 0;
}

