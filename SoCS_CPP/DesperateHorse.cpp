#include <stdio.h>


void horsey(int x1,int y1,int x2,int y2,int move,int count,int *temp){
	if(x1<0 || x1>8 || y1<0 || y1>8) return;
	if(x1==x2 && y1==y2 && count<*temp){
		*temp=count;
		return;	
	}
	if(count<6){
		horsey(x1+1,y1+2,x2,y2,move,count+1,temp);
		horsey(x1-1,y1+2,x2,y2,move,count+1,temp);
		horsey(x1+1,y1-2,x2,y2,move,count+1,temp);
		horsey(x1-1,y1-2,x2,y2,move,count+1,temp);
		horsey(x1+2,y1+1,x2,y2,move,count+1,temp);
		horsey(x1-2,y1+1,x2,y2,move,count+1,temp);
		horsey(x1+2,y1-1,x2,y2,move,count+1,temp);
		horsey(x1-2,y1-1,x2,y2,move,count+1,temp);
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	getchar();
	for(int i=1;i<=test;i++){
		int temp=6;
		char c1,c2;
		int y1,y2;
		scanf("%c%d %c%d",&c1,&y1,&c2,&y2);
		getchar();
		int x1=c1%'A';
		int x2=c2%'A';
		horsey(x1,y1,x2,y2,6,0,&temp);
		printf("Case #%d: %d\n",i,temp);
	}
 	return 0;
}

