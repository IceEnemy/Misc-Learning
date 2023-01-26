#include <stdio.h>
#include <string.h>

long long int seq(int n,int *count){
	if(n<=1){
		return n+1;
	}
	else if(n%3==0){
		if(n==3) (*count)++;
		return seq(n-(n/3),count) + 1;
	}
	else{
		if(n==4) (*count)++;
		return seq(n-1,count) + n + seq(n-2,count) + 1;
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int count=0;
		int n;
		scanf("%d",&n);
//		printf("%d %d\n",n,count);
		long long int res=seq(n,&count);
		printf("Case #%d: %lld %d\n",i,res,count);
	}
 	return 0;
}

