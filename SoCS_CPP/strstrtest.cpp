#include <stdio.h>
#include <string.h>

int main()
{
	char str1[]="i want ns goreng";
	char str2[]="ns";
	char *p = strstr(str1,str2);
	
	if(p){
		printf("%s\n",p);
		strcpy(p,"nasi");
	}
	printf("%s\n",str1);
 	return 0;
}

