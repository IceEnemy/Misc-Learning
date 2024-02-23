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
		scanf("%lld",&m);
		if(m<min){
			printf("Case #%d: -1\n",i);
			continue;
		}
		else if(m>=total){
			printf("Case #%d: %d\n",i,n);
			continue;
		}
		int count=n;
		for(int j=0;j<n;j++){
			bool change=false;
			for(int k=0;k<n;k++){
				int how=count-1;
				long long int sum=0;
				if(k+count>n) continue;
				while(how>=0){
//					printf("%d ",num[k+how]);
					sum+=num[k+how];
					how--;
				}
//				printf("\n");
//				printf("sum = %lld smaller than %lld?\n",sum,m);
				if(sum<=m){
//					printf("yes it is count is %d\n",count);
					change = true;
					break;
				}
			}
			if(change == true) {
				break;
			}
			count--;
		}
		printf("Case #%d: %d\n",i,count);
	}
 	return 0;
}

