#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		long int num,var=0;
		scanf("%ld",&num);
		char bin[10000];
		while(num>0){
			bin[var]=num&1;
			num>>=1;
			var++;
		}
		printf("Case #%d: ",i);
		for(int j=var-1;j>=0;j--){
			printf("%d",bin[j]);
		}
		printf("\n");
	}
 	return 0;
}
