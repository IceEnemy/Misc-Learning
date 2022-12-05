#include <stdio.h>

int main()
{
	int num;
	scanf("%d",&num);
	for(int i=num+1;i<=num+10;i++){
		if(i%2==1) printf("%d\n",i);
	}
 	return 0;
}
/*
input num
for counter = num+1 to num+10
	if(num MOD 2 ==1)
		Display counter
	EndIf
Endfor

*/
