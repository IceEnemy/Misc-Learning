#include <stdio.h>
#include <string.h>

struct code{
	char txt[10001];
};

void count(int *res, char data[]){
	int len = strlen(data);
	for(int i=0;i<len;i++){
		if(data[i] >='a' && data[i] <='z'){
			(*res)+=data[i]-'a'+1;
		}
		else if(data[i] >='A' && data[i] <='Z'){
			(*res)+=data[i]-'A'+1;
		}
		if((*res) > 180) (*res)-=180;
//		printf("%c\n",data[i]);
	}
}

int main()
{
	int h1,h2;
	int m11,m12,m21,m22;
	int x=0,y=0;
	struct code data1[10];
	struct code data2[10];
	int n=0,m=0;
	char nom;
	scanf("%d:%1d%1d>",&h1,&m11,&m12);
	do{
		scanf("%s%c",data1[n].txt,&nom);
		n++;
	}while(nom != '\n');
	if(m11 < n){
		count(&x,data1[m11].txt);
	}
	if(m12 < n){
		count(&x,data1[m12].txt);
	}
	if((h1 > 12) || (h1 == 12 && (m11 > 0 || m12 > 0))){
		x*=-1;
	}
	
	nom = ' ';
	scanf("%d:%1d%1d>",&h2,&m21,&m22);
	do{
		scanf("%s%c",data2[m].txt,&nom);
		m++;
	}while(nom != '\n');
	if(m21 < n){
		count(&y,data2[m21].txt);
	}
	if(m22 < n){
		count(&y,data2[m22].txt);
	}
	if((h2 > 12) || (h2 == 12 && (m21 > 0 || m22 > 0))){
		y*=-1;
	}
	printf("Case #1: %d,%d\n",x,y);
	
 	return 0;
}

