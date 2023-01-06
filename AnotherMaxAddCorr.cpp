#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int num[n];
	long long int total=0;
	int min=-1;
	for(int j=0;j<n;j++){
		scanf("%d",&num[j]);
		total+=num[j];
		if(min==-1){
			min=num[j];
		}
		else if(num[j]<min){
			min=num[j];
		}
	}
	
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		long long int m;
		int count;
		scanf("%lld",&m);
		if(m<min){
			count=-1;
		}
		else if(m>=total){
			count=n;
		}
		else{
			count=n-1;
			long long int sum=total;
			while(count>0){
				sum-=num[count];
//				printf("\n%d. %lld\n",count,sum);
				if(sum<=m) break;
				long long int temp=sum;
				for(int j=0;j<n-count;j++){
//					if(j==0){
//						printf("%lld\n",temp);
//					}
//					printf("temp = %lld+%d-%d ",temp,num[count+j],num[j]);
					temp+=num[count+j]-num[j];
//					printf("[%lld]\n",temp);
					if(temp<=m) break;
				}
				if(temp<=m) break;
				count--;
			}	
		}
		printf("Case #%d: %d\n",i,count);
	}
 	return 0;
}
