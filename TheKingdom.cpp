#include <stdio.h>
#include <string.h>

void hehe(char kingdom,int amount[],char map[][110],int y,int x, int size){
	if(y>=size || x>=size || y<0 || x<0) return;
	else if(map[y][x] == kingdom || map[y][x] == '.'){
		map[y][x]='#';
		amount[kingdom-'a']++;
		hehe(kingdom,amount,map,y+1,x,size);
		hehe(kingdom,amount,map,y-1,x,size);
		hehe(kingdom,amount,map,y,x+1,size);
		hehe(kingdom,amount,map,y,x-1,size);
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char map[110][110];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	int amount[26]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]>='a' && map[i][j]<='z'){
				hehe(map[i][j],amount,map,i,j,n);
			}
		}
	}
	
	for(int i=0;i<26;i++){
		if(amount[i] != 0){
			printf("%c %d\n",'a'+i,amount[i]);	
		}
	}
	
 	return 0;
}

