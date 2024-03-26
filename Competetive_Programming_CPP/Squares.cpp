#include <stdio.h>
#include <string.h>

int main()
{
//	int arr[15] = {0};
//	for(int i=1;i<11;i++){
//		arr[i] = i*i + arr[i-1];
//	}
//	for(int i=1;i<11;i++){
//		printf("%d\n",arr[i]);
//	}
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int N,M;
		scanf("%d %d",&N,&M);
		int res=N*M;
		int max,min;
		if(N > M){
			max = N;
			min = M;
		}
		else{
			max = M;
			min = N;
		}
		for(int j=2;j<=min;j++){
			res += ((min-j+1)*(max-j+1));
		}
//		if(N == M){
//			printf("Case #%d: %d\n",i,arr[N]);
//		}
//		else if(N < M){
//			res = arr[N] + ((3*(N-1)) * (M-N));	
//			printf("Case #%d: %d\n",i,res);
//		}
//		else{
//			res = arr[M] + ((3*(M-1)) * (N-M));	
//			printf("Case #%d: %d\n",i,res);
//		}
		printf("Case #%d: %d\n",i,res);
	}
 	return 0;
}

