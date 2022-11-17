#include <stdio.h>

int main(){
	int test,num,a,b,c,d;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int sum=0;
		scanf("%d %d %d %d %d",&num,&a,&b,&c,&d);
		for(int j=1;j<=num;j++){
		if(j%a==0)
		sum++;
		else if(j%b==0)
		sum++;
		else if(j%c==0)
		sum++;
		else if(j%d==0)
		sum++;
		}
	printf("Case #%d: %d\n",i,sum);
	}
return 0;
}

