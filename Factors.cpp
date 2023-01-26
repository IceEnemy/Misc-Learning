#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		int count=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			if(n%j==0) count++;
		}
		printf("Case #%d: %d\n",i,count);
	}
 	return 0;
}

