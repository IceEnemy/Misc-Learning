#include <stdio.h>
#include <math.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int num;
		int pr=1;
		int sq=0;
		int cb=0;
		double a,b;
		int a1,b1;
		scanf("%d",&num);
		if(num==1 || num==0){
			printf("Case #%d : square cubic\n",i);
		}
		else{
			a=sqrt(num);
			a1=a;
			if(a1==a) sq=1;
			b=cbrt(num);
			b1=b;
			if(b1==b) cb=1;
			for(int j=2;j<num/2;j++){
				if(num%j==0){
					pr=0;
					break;
				}
			}
			if(cb==1 && sq==1) printf("Case #%d : square cubic\n",i);
			else if(cb==1) printf("Case #%d : cubic\n",i);
			else if(sq==1) printf("Case #%d : square\n",i);
			else if(pr==1) printf("Case #%d : prime\n",i);
			else printf("Case #%d : none\n",i);
		}
		
	}
 	return 0;
}

