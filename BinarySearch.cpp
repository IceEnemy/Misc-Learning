#include <stdio.h>

unsigned long long int num[1442251];

int binarySearch(unsigned long long int num[],int l,int r,unsigned long long int target){
	if(target==1) return 1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(num[m]>=target && num[m-1]<target){
			return m;
		}
		else if(num[m]>target){
			r=m-1;
		}
		else if(num[m]<target){
			l=m+1;
		}
	}
}

int main()
{
	for(int i=1;i<=1442250;i++){
		num[i]=((unsigned long long int)i*((unsigned long long int)i+1)*(2*(unsigned long long int)i+1))/6;
//		printf("%d: %llu\n",i,num[i]);
	}
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		unsigned long long int target;
		scanf("%llu",&target);
		printf("Case #%d: %d\n",i,binarySearch(num,1,1442250,target));
	}
 	return 0;
}

