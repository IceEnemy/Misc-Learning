#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n,min;
		scanf("%d %d",&n,&min);
		int count=0;
		int b;
		for(int j=0;j<n;j++){
			scanf("%d",&b);
			if(b>=min) count++;
		}
		printf("Case #%d: %d\n",i,count);
	}
 	return 0;
}

