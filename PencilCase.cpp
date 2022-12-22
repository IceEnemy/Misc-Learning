#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		double r,h;
		scanf("%lf %lf",&r,&h);
		double pi=3.14;
		double res=2*pi*r*(r+h);
		printf("Case #%d: %.2lf\n",i,res);
	}
 	return 0;
}

