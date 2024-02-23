#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char str[10010];
	char up[10010];
	scanf("%[^\n]",str);
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='a' && str[i]<='z') up[i]=str[i]-32;
		else up[i]=str[i];
		if(up[i]=='I') up[i]='1';
		else if(up[i]=='R') up[i]='2';
		else if(up[i]=='E') up[i]='3';
		else if(up[i]=='A') up[i]='4';
		else if(up[i]=='S') up[i]='5';
		else if(up[i]=='G') up[i]='6';
		else if(up[i]=='T') up[i]='7';
		else if(up[i]=='B') up[i]='8';
		else if(up[i]=='P') up[i]='9';
		else if(up[i]=='O') up[i]='0';
	}
	printf("%s\n",up);
 	return 0;
}

