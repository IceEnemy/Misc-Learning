#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[1010];
	scanf("%[^\n]",str);
	int pal=1;
	int varp=0;
	int varm=0;
	int space=1;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		str[i]=toupper(str[i]);
	}
	for(int i=0;i<len;i++){
		if(str[i]!=' ') space=0;
		if(str[i]==' ') varp++;
		if(str[len-1-i]==' ') varm++;
		if(str[i+varp]!=str[len-1-i-varm]){
			pal=0;
			break;
		}
		if(i>(len/2)) break;
	}
	if(space==1) printf("That's not a word those are just spaces lol\n");
	else if(pal==1) printf("Palindrome\n");
	else printf("Not Palindrome\n");
 	return 0;
}

