#include <stdio.h>

//long long int slice;
//int count;
//
//void pancake(int n){
//	if(n<=1){
//		res++;
//	}
//}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int pancake;
		scanf("%d",&pancake);
		long long int slice=1;
		printf("Case %d: ",i);
		if(pancake==1){
			printf("1\n");
		}
		for(int j=1;j<pancake;j++){
			if(j==1) printf("1 ");
			slice+=j;
			if(j==pancake-1) printf("%lld\n",slice);
			else printf("%lld ",slice);
		}
	}
 	return 0;
}

