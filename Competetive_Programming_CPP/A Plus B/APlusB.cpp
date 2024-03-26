#include <stdio.h>

int main()
{
	FILE *lengfan = fopen("testdata.in","r");
	int a,b;
	fscanf(lengfan,"%d %d",&a,&b);
	printf("%d\n",a+b);
	fclose(lengfan);
 	return 0;
}

