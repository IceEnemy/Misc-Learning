#include <stdio.h>

int main()
{
	int size;
	scanf("%d",&size);
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			int check=i-size+j-1;
			if(check<0){
				printf("-");
			}
			else{
				printf("*");
			}
			
		}
		printf("\n");
	}
 	return 0;
}

