#include <stdio.h>

long long int factorial(int n){
	if(n==1) return 1;
	if(n>1){
		return (n*factorial(n-1))%1000000007;
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int num;
		long long int result=1;
		scanf("%d",&num);
		int number[num];
		for(int j=0;j<num;j++){
			scanf("%d",&number[j]);
			result*=factorial(number[j]);
			result%=1000000007;
		}
		printf("Case #%d: %lld\n",i,result);
	}
 	return 0;
}

