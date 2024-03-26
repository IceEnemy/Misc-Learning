#include <stdio.h>
#include <string.h>

void boom(char map[110][110],int y, int x, int *count, int n){
	if(y-1>=0){
		if(map[y-1][x]=='o'){
			map[y-1][x]='.';
			(*count)++;
		}
	}
	if(x-1>=0){
		if(map[y][x-1]=='o'){
			map[y][x-1]='.';
			(*count)++;
		}
	}
	if(y+1<n){
		if(map[y+1][x]=='o'){
			map[y+1][x]='.';
			(*count)++;
		}
	}
	if(x+1<n){
		if(map[y][x+1]=='o'){
			map[y][x+1]='.';
			(*count)++;
		}
	}
	if(y-1>=0 && x-1>=0){
		if(map[y-1][x-1]=='o'){
			map[y-1][x]='.';
			(*count)++;
		}
	}
	if(y-1>=0 && x+1<n){
		if(map[y-1][x+1]=='o'){
			map[y-1][x]='.';
			(*count)++;
		}
	}
	if(y+1<n && x+1<n){
		if(map[y+1][x+1]=='o'){
			map[y-1][x]='.';
			(*count)++;
		}
	}
	if(y+1<n && x-1>=0){
		if(map[y+1][x-1]=='o'){
			map[y-1][x]='.';
			(*count)++;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	char map[110][110];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='T'){
				boom(map,i,j,&count,n);
			}
		}
	}
	printf("%d\n",count);
	
 	return 0;
}

