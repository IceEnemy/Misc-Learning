#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n,time;
		scanf("%d %d",&n,&time);
		int train[n];
		for(int j=0;j<n;j++){
			scanf("%d",&train[j]);
		}
		bool swap;
		int count=0;
		for(int j=0;j<n-1;j++){
			swap=false;
			for(int k=0;k<n-1;k++){
				if(train[k]>train[k+1]){
					int temp=train[k];
					train[k]=train[k+1];
					train[k+1]=temp;
					count+=time;
					swap = true;
				}	
			}
			if(swap==false) break;
		}
		printf("Case #%d: %d\n",i,count);
	}
 	return 0;
}

