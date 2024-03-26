#include <stdio.h>

void fibstr(int n,char A,char B){
	if(n==0) printf("%c",A);
	else if(n==1) printf("%c",B);
	else{
	fibstr(n-1,A,B);
	fibstr(n-2,A,B);
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		char A,B;
		scanf("%d %c %c",&n,&A,&B);
		printf("Case #%d: ",i);
		fibstr(n,A,B);
		printf("\n");
	}
 	return 0;
}

