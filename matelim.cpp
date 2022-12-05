#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	
	for(int i=1;i<=test;i++){
		int row,col;
		scanf("%d %d",&row,&col);
		int mat[row][col];
		int max=0;
		int x,y;
		int check=1;
		int size=(row-1)*(col-1);
		
		for(int j=0;j<row;j++){
			for(int k=0;k<col;k++){
				scanf("%d",&mat[j][k]);
				
				if(mat[j][k]>max){
					max=mat[j][k];
					x=j;
					y=k;
				}				
			}
		}
		printf("Case #%d: ",i);
		for(int j=0;j<row;j++){
			for(int k=0;k<col;k++){
				
				if(x!=j && y!=k){
					if(check==size){
						printf("%d\n",mat[j][k]);
					}
					else{
						printf("%d ",mat[j][k]);
						check++;
					}
				}
			}
		}
		
	}
 	return 0;
}

