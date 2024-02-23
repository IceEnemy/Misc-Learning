#include <stdio.h>

int main()
{
int test,price,perc,maks;
scanf("%d", &test);
for(int i=1;i<=test;i++){
	scanf("%d %d %d",&price,&perc,&maks);
	if(price*perc/100 <= maks){
		printf("Case #%d: %d\n",i, price*perc/100);
	}
	else{
		printf("Case #%d: %d\n",i, maks);
	}
}
return 0;
}

