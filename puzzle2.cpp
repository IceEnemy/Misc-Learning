#include <stdio.h>
int main()
{
    int size;
    scanf("%d",&size);
    int mat[size][size];
    int sum=0;
    for(int t=0;t<size;t++){
    	for(int u=0;u<size;u++){
    		scanf("%d",&mat[t][u]);
		}
	}
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(mat[i][i]==mat[i][j] || mat[i][i]==mat[j][i]){
            	sum++;
			}
        }
    }
	if(sum==0){
		printf("Yay\n");
	}
	else{
		printf("Nay\n");
	}
     return 0;
}
