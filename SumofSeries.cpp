#include <stdio.h>
#include <string.h>

int main()
{
	long long int res=0;
	long long int start,end;
	scanf("%d %d",&start,&end);
	for(int i=start;i<=end;i++){
		res+=i;
	}
	printf("%lld\n",res);
 	return 0;
}

