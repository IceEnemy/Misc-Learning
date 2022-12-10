#include <stdio.h>
int res=0;
int team(int tree[],int index);

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int tre;
		res=0;
		scanf("%d",&tre);
		int ind=tre-1;
		int tree[tre];
		for(int j=0;j<tre;j++){
			scanf("%d",&tree[j]);
		}
		int sum=team(tree,ind);
		printf("Case #%d: %d\n",i,sum);
	}
 	return 0;
}

int team(int tree[],int index){
	if(index>=0){
		res+=tree[index];
		team(tree,index-1);	
	}
	else{
		return res;
	}
}

