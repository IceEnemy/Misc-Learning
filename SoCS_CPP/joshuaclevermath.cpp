#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int a,b;
		int digit,total=0;
		int mult=1;
		scanf("%d %d",&a,&b);
		while(a != 0 || b != 0){
			digit=((a%10)+(b%10))%10;
			total+=digit*mult;
			a/=10;
			b/=10;
			mult*=10;
		}
		printf("Case #%d: %d\n",i,total);
	}
 	return 0;
}

