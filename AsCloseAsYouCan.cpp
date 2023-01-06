#include <stdio.h>

int binarySearch(long long int num[],int l,int r,long long int target){
	while(l<=r){
		int m=l+(r-l)/2;
//		printf("%d\n",m);
		if((num[m] <= target && num[m+1] > target) || m==r){
//			printf("%d\n",m);
			return m;
		}
		else if(num[m] < target){
			l=m+1;
		}
		else if(num[m] > target){
			r=m-1;
		}
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long int num[n+1]={0};
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		num[i]=num[i-1]+a;
//		printf("%lld\n",num[i]);
	}
	
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		long long int target;
		scanf("%lld",&target);
		if(target<num[1]){
			printf("Case #%d: -1\n",i);
		}
		else{
			printf("Case #%d: %d\n",i,binarySearch(num,1,n,target));
		}
	}
	
	
 	return 0;
}

