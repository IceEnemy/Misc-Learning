#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int s;
		scanf("%d",&s);
		int mat[s][s];
		int sum[s];
		for(int j=0;j<s;j++){
			sum[j]=0;
		}
		for(int j=0;j<s;j++){
			for(int k=0;k<s;k++){
				scanf("%d",&mat[j][k]);
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
				printf("%d ",sum[j]);
			}
			else{
				printf("%d\n",sum[j]);
			}
		}
	}
 	return 0;
}

