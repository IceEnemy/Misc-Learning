#include <stdio.h>
#include <string.h>

int main()
{
	long long int count[81];
	count[1]=1;
	count[2]=3;
	int x;
	scanf("%d",&x);
	for(int i=3;i<=x;i++){
		count[i]=count[i-1]+i+count[i-2];
	}
	printf("%lld\n",count[x]);
 	return 0;
}

