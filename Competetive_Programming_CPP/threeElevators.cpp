#include <stdio.h>

int main()
{
int up,down,stay,i=0;
scanf("%d %d %d",&up,&down,&stay);
while(up<stay && down>stay){
	++i;
	++up;
	--down;
}
if(up == stay && down == stay){
	printf("%d\n", i);
}
else{
	printf("-1\n");
}
return 0;
}

