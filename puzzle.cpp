#include <stdio.h>

int main()
{
	int s,tst=1;
	scanf("%d",&s);
	int mat[100][100];
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			if(mat[i][j] != mat[j][i]){
				tst=0;
				break;
			}
		}
	}
	if(tst==1){
		printf("Yay\n");
	}
	else{
		printf("Nay\n");
	}
 	return 0;
}

