#include <stdio.h>

int main()
{
	int row,col;
	scanf("%d %d",&row,&col);
	int gar[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%d",&gar[i][j]);
		}
	}
	int change;
	scanf("%d",&change);
	int a,b,plant;
	for(int i=0;i<change;i++){
		scanf("%d %d %d",&a,&b,&plant);
		gar[a-1][b-1]=plant;
	}
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(j<col-1) printf("%d ",gar[i][j]);
			else printf("%d\n",gar[i][j]);
		}
	}
 	return 0;
}

