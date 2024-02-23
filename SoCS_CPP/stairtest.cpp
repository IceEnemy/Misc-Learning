#include <stdio.h>

int main()
{
	int size;
	scanf("%d",&size);
	int num[size];
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	for(int j=0;j<size;j++){
		if(j=size-1){
			printf("%d\n",num[j]);
		}
		else if(num[j] == '1'){
			printf("%d ",num[j-1]);
		}
	}
 	return 0;
}

