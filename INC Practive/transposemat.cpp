#include <bits/stdc++.h>
using namespace std;

int main()
{
	int mat[4][4];
	for(int i=0; i<3;i++){
		for(int j=0; j<3;j++){
			scanf("%d", &mat[i][j]);
//			getchar();
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(j == 2){
				printf("%d\n",mat[j][i]);
			}
			else{
				printf("%d ",mat[j][i]);
			}
		}
	}
 	return 0;
}

