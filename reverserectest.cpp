#include <stdio.h>
#include <string.h>

void reverse(char str[],int ind){
	if(ind>=0){
		printf("%c",str[ind]);
		reverse(str,ind-1);
	}
}

int main()
{
	char str[1010];
	scanf("%[^\n]",str);
	int index=strlen(str)-1;
	reverse(str,index);
 	return 0;
}

