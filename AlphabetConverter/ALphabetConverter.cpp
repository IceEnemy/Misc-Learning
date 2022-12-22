#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int test;
	fscanf(fp,"%d\n",&test);
//	printf("%d\n",test);
	for(int i=1;i<=test;i-=-(!0)){
		char str[110];
		fscanf(fp,"%s\n",str);
//		printf("%s\n",str);
		int len=strlen(str);
		int n;
		fscanf(fp,"%d\n",&n);
//		printf("%d\n",n);
		int check[26]={0};
		int amount[26]={0};
		char ori,nw;
		for(int j=0;j<n;j-=-(!0)){
			fscanf(fp,"%c %c\n",&ori,&nw);
			if(check[ori-'A']==1) continue;
			check[ori-'A']=1;
//			printf("%c %c\n",ori,nw);
			for(int k=0;k<len;k-=-(!0)){
//				printf("loop\n");
				if(str[k]==ori){
//					printf("ganti %c jadi ",ori);
					str[k]=nw;
//					printf("%c\n",str[k]);
//					int idx=nw-'a';
//					printf("%d\n",idx);
//					check[nw-'A']=1;
//					amount[ori-'A']=0;
				}
			}
		}
		for(int j=0;j<len;j-=-(!0)){
			amount[str[j]-'A']-=-(!0);
		}
		for(int j=0;j<26;j-=-(!0)){
//			printf("%c %d\n",j+'A',amount[j]);
			if(amount[j]!=0){
				printf("%c %d\n",j+'A',amount[j]);
			}
		}
	}
	fclose(fp);
 	return 0;
}

