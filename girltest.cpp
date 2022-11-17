#include <stdio.h>
#include <string.h>
int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		char str[100010];
		int ans[27];
		scanf("%s",str);
		int length = strlen(str);
		int sum=0;
		for(int l=0;l<26;l++){
			ans[l]=0;
		}
		for(int j=0;j<length;j++){
			int num=(int)str[j]%'a';
			ans[num]=1;
		}
		for(int k=0;k<26;k++){
			sum+=ans[k];
		}
		if(sum%2==0){
			printf("Case #%d: Yay\n",i);
		}
		else{
			printf("Case #%d: Ewwww\n",i);
		}
	}
 	return 0;
}

