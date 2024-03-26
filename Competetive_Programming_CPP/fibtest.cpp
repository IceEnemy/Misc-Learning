#include <stdio.h>
#include <string.h>

long long int fib(int n){
	if(n<=1){
		return n;
	}
	else{
		return fib(n-1) + fib(n-2);
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %lld\n",i,fib(n));
	}
 	return 0;
}

