#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		char num[100010];
		scanf("%s",&num);
		int len=strlen(num);
		int check=0;
		for(int j=0;j<len;j++){
			if(j%2==0) check+=num[j]-'0';
			else check-=num[j]-'0';
		}
		if(check%11==0){
			printf("Case #%d: Yeah\n",i);
		}
		else{
			printf("Case #%d: Nah\n",i);
		}
	}
 	return 0;
}

