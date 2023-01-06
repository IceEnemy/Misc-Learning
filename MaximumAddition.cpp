#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		long long int m;
		scanf("%d %lld",&n,&m);
		int num[n];
		for(int j=0;j<n;j++){
			scanf("%d",&num[j]);
		}
		int count=0;
		for(int j=0;j<n;j++){
			bool change=false;
			for(int k=0;k<n;k++){
				int how=0;
				long long int sum=0;
				if(k+count>n-1) continue;
				while(how<=count){
//					printf("%d ",num[k+how]);
					sum+=num[k+how];
					how++;
				}
//				printf("\n");
//				printf("sum = %d\n",sum);
				if(sum<=m){
					change = true;
					break;
				}
			}
			if(change == false){
				break;
			}
			count++;
		}
		if(count > 0){
			printf("Case #%d: %d\n",i,count);
		}
		else{
			printf("Case #%d: -1\n",i);
		}
	
	}
 	return 0;
}

