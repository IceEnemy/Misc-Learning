#include <stdio.h>

int main()
{
int test;
scanf("%d",&test);
for(int i=1;i<=test;i++){
	int full,need;
	scanf("%d %d",&full,&need);
	int total = full;
	int empty = full;
	while(empty >= need){
		empty = empty - need + 1;
		total++;
	}
	printf("Case #%d: %d\n",i,total);
}
return 0;
}

