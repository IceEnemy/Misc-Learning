#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int test;
	fscanf(fp,"%d",&test);
	for(int i=1;i<=test;i++){
		int len,min,max;
		int count=0;
		int lightning=0;
		fscanf(fp,"%d %d %d",&len,&min,&max);
		char sound[len+10];
		for(int j=0;j<len;j++){
			fscanf(fp," %c",&sound[j]);
			if(sound[j]=='0'){
				if(count>=min && count<=max) lightning++;
				count=0;
			}
			else if(sound[j]=='1'){
				count++;
			}
			if(j>=len-1){
				if(count>=min && count<=max) lightning++;
			}
		}
		printf("Case #%d: %d\n",i,lightning);
	}
	fclose(fp);
 	return 0;
}

