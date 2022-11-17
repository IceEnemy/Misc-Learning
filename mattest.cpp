#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++){
		int n;
	scanf("%d",&n);
	int mat1[n][n];
	int mat2[n][n];
	int mat3[n][n];
	int res1[n][n];
	int res2[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			res1[i][j]=0;
			res2[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	scanf("\n");
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				res1[i][k]+=mat1[i][j]*mat2[j][k];
			}
		}
	}
	scanf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat3[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				res2[i][k]+=res1[i][j]*mat3[j][k];
			}
		}
	}
	printf("Case #%d:\n",t);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j<n-1){
			printf("%d ",res2[i][j]);
		}
			else{
			printf("%d",res2[i][j]);
		}
			
		}
		printf("\n");
	}
	}
	return 0;
}

