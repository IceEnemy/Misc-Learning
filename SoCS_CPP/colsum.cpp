#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int s;
		scanf("%d",&s);
		long long int mat[s][s];
		long long int sum[s];
		for(int j=0;j<s;j++){
			sum[j]=0;
		}
		for(int j=0;j<s;j++){
			for(int k=0;k<s;k++){
				scanf("%lld",&mat[j][k]);
			}
		}
		for(int j=0;j<s;j++){
			for(int k=0;k<s;k++){
				sum[j] += mat[k][j];
			}
		}
		printf("Case #%d: ",i);
		for(int j=0;j<s;j++){
			if(j<s-1){
				printf("%lld ",sum[j]);
			}
			else{
				printf("%lld\n",sum[j]);
			}
		}
	}
 	return 0;
}

