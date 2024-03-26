#include <stdio.h>

int main()
{
int test,success;
scanf("%d",&test);
for(int i=1;i<=test;i++){
	success=0;
	int ships;
	scanf("%d",&ships);
	int res[ships],req[ships];
	for(int j=0;j<ships;j++){
		scanf("%d",&res[j]);
	}
	for(int j=0;j<ships;j++){
		scanf("%d",&req[j]);
		if(res[j]<req[j])
		success++;
	}
	printf("Case #%d: %d\n",i,success);
}
return 0;
}

