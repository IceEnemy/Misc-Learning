#include <stdio.h>

int count;

int func(int n){
	if(n<=1) return n+1;
	else if(n%5==0){
		if(n%3==0) count++;
		return n*2;
	}
	else {
		if(n%3==0) count++;
		return func(n-1)+n+func(n-2)+n-2;
	}

}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int number;
		count=0;
		scanf("%d",&number);
		int result = func(number);
		printf("Case #%d: %d %d\n",i,result,count);
	}
 	return 0;
}
