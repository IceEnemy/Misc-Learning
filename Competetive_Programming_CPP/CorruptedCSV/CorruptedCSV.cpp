#include <stdio.h>
#include <string.h>
// 1000000007
int main()
{
	FILE *fp = fopen("testdata.csv","r");
	long long int pos=1;
	char data[5];
	int count=1;
	while(!feof(fp)){
//		printf("%d\n",count);
		fscanf(fp,"%[^;];",data);
		printf("%s\n",data);
		if(strcmp(data," ") == 0 || strcmp(data,"\n") == 0){
			printf("%s is corrupt\n",data);
			pos *= 101;
			pos %= 1000000007;
		}
		count++;
	}
	if(pos==1){
		printf("0\n");
	}
	else{
		printf("%lld\n",pos);
	}
	fclose(fp);
 	return 0;
}

