#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		long long int mult=1;
		char num[15];
		char rev[15];
		scanf("%s",num);
		int len=strlen(num);
		for(int j=0;j<len;j++){
			rev[j]=num[len-1-j];
			if(j>0) mult*=10;
		}
		long long int res=0;
		printf("Case #%d: ",i);
		for(int j=0;j<len;j++){
			res+=(rev[j]+num[j]-96) * mult;
			mult/=10;
		}
		printf("%lld\n",res);
	}
 	return 0;
}

