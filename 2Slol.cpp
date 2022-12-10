#include <stdio.h>

void flood(char map[][101],int y,int x,int row,int col,int *counter){
	if(y<0 || x<0 || y==row || x==col) return;
	if(map[y][x]=='S' && *counter==0){
		flood(map,y+1,x,row,col,counter);
		flood(map,y-1,x,row,col,counter);
		flood(map,y,x+1,row,col,counter);
		flood(map,y,x-1,row,col,counter);
	}
	else if(map[y][x]=='.'){
		(*counter)++;
		map[y][x]='0';
		flood(map,y+1,x,row,col,counter);
		flood(map,y-1,x,row,col,counter);
		flood(map,y,x+1,row,col,counter);
		flood(map,y,x-1,row,col,counter);
	}
	else return;
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int row,col;
		int count=0;
		scanf("%d %d",&row,&col);
		char map[row+1][101];
		int y,x;
		for(int j=0;j<row;j++){
			for(int k=0;k<col;k++){
				scanf(" %c",&map[j][k]);
				if(map[j][k]=='S'){
					y=j;
					x=k;
				}
			}
		}
		flood(map,y,x,row,col,&count);
		printf("Case #%d: %d\n",i,count);
	}
 	return 0;
}

