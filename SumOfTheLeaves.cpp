#include <stdio.h>

void tree(int branch[],int n,int amount,int res){
//	if(n>=amount) return;
	res+=branch[n];
	if ((n*2)>amount && (n*2+1)>amount){
		printf("%d\n",res);
		return;
	}
	tree(branch,n*2,amount,res);
	if(n*2+1>amount)  return;
	tree(branch,n*2+1,amount,res);
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int num;
		scanf("%d",&num);
		int branch[num+1];
		for(int j=1;j<=num;j++){
			scanf("%d",&branch[j]);
		}
		printf("Case #%d:\n",i);
		tree(branch,1,num,0);
	}
 	return 0;
}

