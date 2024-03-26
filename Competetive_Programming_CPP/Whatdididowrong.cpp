#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int num;
		scanf("%d",&num);
		int arr1[num];
		for(int j=0;j<num;j++){
			scanf("%d",&arr1[j]);
		}
		int arr2[num];
		int arr3[num];
		for(int j=0;j<num;j++){
			scanf("%d",&arr2[j]);
			arr3[j]=arr1[j]-arr2[j];
		}
		printf("Case #%d: ",i);
		for(int j=0;j<num;j++){
			if(j<num-1){
				printf("%d ",arr3[j]);
			}
			else{
				printf("%d\n",arr3[j]);
			}
		}
	}
 	return 0;
}

