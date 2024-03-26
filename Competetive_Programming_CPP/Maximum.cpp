#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int size;
		scanf("%d",&size);
		int num[size];
		int max1=-1000001;
		int max2=-1000001;
		for(int j=0;j<size;j++){
			scanf("%d",&num[j]);
			if(num[j]>max1){
				max2=max1;
				max1=num[j];
			}
			else if(num[j]>max2){
				max2=num[j];
			}
		}
		printf("Case #%d: %d\n",i,max1+max2);
	}
 	return 0;
}

