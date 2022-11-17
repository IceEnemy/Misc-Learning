#include <stdio.h>
#include <string.h>
int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		char num1[10],num2[10];
		int res[10];
		scanf("%s %s",num1,num2);
		int len1=strlen(num1);
		int len2=strlen(num2);
		int var=0;
		int check=0;
		int dif;
		if(len1>len2){
//			for(int j=len2;j<len1;j++){
//				num2[j]='0';
//				len2++;
//			}
			dif=len1-len2;
			len2=len1;
			for(int j=len2-1;j>=0;j--){
				if(j-dif>=0) num2[j]=num2[j-dif];
				else num2[j]='0';
			}
		}
		else if(len2>len1){
//			for(int j=len1;j<len2;j++){
//				num1[j]='0';
//				len1++;
//			}
			dif=len2-len1;
			len1=len2;
			for(int j=len1-1;j>=0;j--){
				if(j-dif>=0) num1[j]=num1[j-dif];
				else num1[j]='0';
			}
		}
		for(int j=0;j<len1;j++){
			res[j]= num1[j] + num2[j] - 96;
			if(res[j]>=10) res[j]-=10;
		}
		printf("Case #%d: ",i);
		for(int j=0;j<len1;j++){
			if(res[j]!=0 || check==1){
				printf("%d",res[j]);
				check=1;
			}
			else if(j==len1-1) printf("%d",res[j]);
		}
		printf("\n");
	}
 	return 0;
}
