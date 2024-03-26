#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M, P;
	scanf("%d %d %d",&N, &M, &P);
	int mat1[N][M];
	int mat2[M][P];
//	int mat3[N][P];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<P; j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<P; j++){
			int total = 0;
			for(int k=0; k<M; k++){
				total+=mat1[i][k]*mat2[k][j];
			}
			printf("%d",total);
			if(j == P-1) printf("\n");
			else printf(" ");
		}
	}
 	return 0;
}

