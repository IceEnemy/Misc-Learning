#include <stdio.h>

int main()
{
	int size;
	scanf("%d",&size);
	int final[size];
	int pos[size];
	for(int i=0;i<size;i++){
		scanf("%d",&pos[i]);
	}
	int newN[size];
	for(int i=0;i<size;i++){
		scanf("%d",&newN[i]);
		final[pos[i]]=newN[i];
	}
	for(int i=0;i<size;i++){
		if(i<size-1){
			printf("%d ",final[i]);
		}
		else{
			printf("%d\n",final[i]);
		}
	}
	
 	return 0;
}

