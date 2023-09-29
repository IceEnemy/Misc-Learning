#include <bits/stdc++.h>
using namespace std;

int main()
{
	int M,N;
	scanf("%d %d",&M, &N);
	int mat[M][N];
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(int j=0; j<N; j++){
		for(int i=M-1; i>=0; i--){
			printf("%d", mat[i][j]);
			if(i != 0) printf(" ");
			else printf("\n");
		}
	}
 	return 0;
}

