#include <stdio.h>

int main()
{
	int num;
	scanf("%d",&num);
	int bol;
	if(num<0){
		bol=0;
	}
	else{
		bol=1;
	}
	
	if(bol==1){
		printf("positif");
	}
	else{
		printf("negatif");
	}
 	return 0;
}

