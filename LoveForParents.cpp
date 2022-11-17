#include <stdio.h>

int main()
{
	int size;
	scanf("%d",&size);
	int price[size];
	for(int i=0;i<size;i++){
		scanf("%d",&price[i]);
	}
	int num;
	scanf("%d",&num);
	for(int j=1;j<=num;j++){
		int pos,newP;
		scanf("%d %d",&pos,&newP);
		price[pos-1]=newP;
		printf("Case #%d: ",j);
		for(int k=0;k<size;k++){
			if(k<size-1){
				printf("%d ",price[k]);
			}
			else{
				printf("%d",price[k]);
			}	
		}
		printf("\n");
	}
 	return 0;
}

