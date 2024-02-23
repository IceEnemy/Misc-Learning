#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int money,mon;
		double perc;
		scanf("%d %lf %d",&money,&perc,&mon);
		perc/=100;
		double tax=0.8;
		for(int j=1;j<=mon;j++){
			int interest=money*(perc/12)*tax;
			money+=interest;
			printf("%d %d\n",j,money);
		}
	}
 	return 0;
}

