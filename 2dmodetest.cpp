#include <stdio.h>

int main()
{
	int size;
	int most=0;
	int mode[10010];
	int var=0;
	scanf("%d",&size);
	int mat[size][size];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			int amount=0;
			for(int k=0;k<size;k++){
				for(int l=0;l<size;l++){
					if(mat[i][j]==mat[k][l]) amount++;
				}
			}
			if(amount>most){
				most=amount;
				mode[var]=mat[i][j];
			}
			else if(amount=most)
		}
	}
	for(int i=0;i<var;i++){
		printf("Most common")
	}
 	return 0;
}

