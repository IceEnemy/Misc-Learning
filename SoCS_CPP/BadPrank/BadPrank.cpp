#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int test;
	fscanf(fp,"%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		fscanf(fp,"%d\n",&n);
		char text[1010];
		fscanf(fp,"%[^\n]",text);
//		printf("Case #%d: %s\n",i,text);
		int len=strlen(text);
		for(int j=0;j<len;j++){
			if(text[j]=='0') text[j]='O';
			else if(text[j]=='1') text[j]='I';
			else if(text[j]=='3') text[j]='E';
			else if(text[j]=='4') text[j]='A';
			else if(text[j]=='5') text[j]='S';
			else if(text[j]=='6') text[j]='G';
			else if(text[j]=='7') text[j]='T';
			else if(text[j]=='8') text[j]='B';
			if(text[j]>='A' && text[j]<='Z'){
				text[j]-=n;
				if(text[j]<'A') text[j]+=26;	
			}
			
		}
		printf("Case #%d: %s\n",i,text);
	}
	fclose(fp);
	return 0;
}

