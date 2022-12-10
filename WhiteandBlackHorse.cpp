#include <stdio.h>

void horsey(int x1,int y1,int x2,int y2,int move,bool *check){
	if(x1<0 || x1>=8 || y1<0 || y1>=8) return;
	if(x1==x2 && y1==y2) (*check)==true;
	if(move>0){
		horsey(x1+1,y1+2,x2,y2,move-1,check);
		horsey(x1-1,y1+2,x2,y2,move-1,check);
		horsey(x1+1,y1-2,x2,y2,move-1,check);
		horsey(x1-1,y1-2,x2,y2,move-1,check);
		horsey(x1+2,y1+1,x2,y2,move-1,check);
		horsey(x1-2,y1+1,x2,y2,move-1,check);
		horsey(x1+2,y1-1,x2,y2,move-1,check);
		horsey(x1-2,y1-1,x2,y2,move-1,check);
	}
}


int main()
{
	int test;
	scanf("%d",&test);
	getchar();
	for(int i=1;i<=test;i++){
		int moves;
		scanf("%d",&moves);
		getchar();
		char c1,c2;
		int y1,y2;
		scanf("%c%d %c%d",&c1,&y1,&c2,&y2);
		getchar();
		int x1=c1%'A';
		int x2=c2%'A';
		bool check=false;
		horsey(x1,y1,x2,y2,moves*2,&check);
		if (check==false) printf("Case #%d: NO\n",i);
		else  printf("Case #%d: YES\n",i);
	}
 	return 0;
}

