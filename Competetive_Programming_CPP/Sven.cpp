#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		scanf("%d",&n);
		int res=0;
		int num;
		for(int j=0;j<n;j++){
			scanf("%d",&num);
			res+=num;
		}
		printf("Case #%d: %d\n",i,res);
	}
 	return 0;
}

