#include <stdio.h>
#include <string.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		char string[510];
		int check=1;
		scanf("%s",string);
		int len=strlen(string);
		for(int j=0;j<len;j++){
			if(string[j]!=string[len-1-j]){
				check=0;
				break;
			}
		}
		if(check==1){
			printf("Case #%d: Yay, it's a palindrome\n",i);
		}
		else{
			printf("Case #%d: Nah, it's not a palindrome\n",i);
		}
	}
 	return 0;
}

