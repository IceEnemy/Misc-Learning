#include <stdio.h>
#include <string.h>

int main()
{
	char str1[10000];
	char str2[10000];
	int pal = 1;
	int var=0;
	
	scanf("%[^\n]",str1);
	getchar();
	
	int len=strlen(str1);
	for(int i=0;i<len;i++){
		if(str1[i]!=' '){
			str2[var++]=str1[i];
//			var++;
		}
	}
//	printf("%s",str2);
	for(int i=0;i<var;i++){
		if(str2[i]!=str2[var-1-i]){
			pal=0;
			break;
		}
		if(i>(var/2)) break;
	}
	if(pal==1) printf("Palindrome\n");
	else printf("Not Palindrome\n");
 	return 0;
}

