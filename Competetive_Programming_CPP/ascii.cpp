#include <stdio.h>

int main()
{
char a,b,c;
scanf("%c %c %c",&a,&b,&c);
if(a<b && b<c){
	printf("1 2 3\n");
}
else if(a<c && c<b){
	printf("1 3 2\n");
}
else if(b<a && a<c){
	printf("2 1 3\n");
}
else if(b<c && c<a){
	printf("2 3 1\n");
}
else if(c<b && b<a){
	printf("3 2 1\n");
}
else if(c<a && a<b){
	printf("3 1 2\n");
}
return 0;
}

