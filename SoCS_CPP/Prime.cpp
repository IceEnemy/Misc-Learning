#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		bool prime = true;
		scanf("%d",&n);
		if(n<=1) prime = false;
//		else{
//			if((n%2==0 || n%3==0 || n%5==0 || n%7==0) && n!=2 && n!=3 && n!=5 && n!=7) prime=false;
//		}
		for(int j=2;j<=sqrt(n);j++){
			if(n%j==0){
				prime = false;
				break;
			}
		}
		if(prime == true) printf("Case #%d: prime\n",i);
		else printf("Case #%d: not prime\n",i);
	}
 	return 0;
}

