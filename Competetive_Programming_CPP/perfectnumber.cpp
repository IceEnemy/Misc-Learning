#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int num;
		int sum=0;
		scanf("%d",&num);
		
		for(int j=1;j<num;j++){
			if(num%j==0) sum+=j;
		}
		if(sum==num) printf("Case #%d: Yes\n",i);
		else printf("Case #%d: No\n",i);
	}
 	return 0;
}

