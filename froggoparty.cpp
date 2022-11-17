#include <stdio.h>

int main()
{
float a,b,c,d;
scanf("%f", &a);

for(int i = 1; i<=a; i++){
	scanf("%f %f",&b,&c);
	d = ((b+c)/2)+b*c/2;
	printf("%f", d);
//	int e = d;
//	if(e % 2 == 0){
//		printf("Case #%d: Party time!\n", i);
//	}
//	else{
//		printf("Case #%d: Need more frogs\n", i);
//	}
}
return 0;
}

