#include <stdio.h>

long long int jobonachi(int n){
	if(n<=1) return n;
	if(n%2==1) return 1;
	return jobonachi(n-1) + jobonachi(n-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",jobonachi(n));
	
 	return 0;
}

