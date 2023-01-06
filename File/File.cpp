#include <stdio.h>
#include <string.h>

struct text{
	char str[110];
};

struct change{
	char shrt[110];
	char ori[110];
};

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int n;
	fscanf(fp,"%d\n",&n);
//	printf("%d\n",n);
	struct change words[n];
	for(int i=0;i<n;i++){
		fscanf(fp,"%[^#]#%s\n",words[i].shrt,words[i].ori);
	}
//	for(int i=0;i<n;i++){
//		printf("%s#%s\n",words[i].shrt,words[i].ori);
//	}
	int t;
	fscanf(fp,"%d\n",&t);
//	printf("%d\n",t);
	for(int i=1;i<=t;i++){
		struct text arr[110];
		char nom=' ';
		int count=0;
		while(nom!='\n'){
			fscanf(fp,"%s%c",arr[count].str,&nom);
			count++;
		}
		for(int j=0;j<count;j++){
			for(int k=0;k<n;k++){
//				printf("%s == %s?\n",arr[j].str,words[k].shrt);
				if(strcmp(arr[j].str,words[k].shrt) == 0){
					strcpy(arr[j].str,words[k].ori);
//					printf("New String : %s\n",arr[j].str);
					break;
				}
			}
		}
		printf("Case #%d:\n",i);
		for(int j=0;j<count;j++){
			if(j<count-1){
				printf("%s ",arr[j].str);
			}
			else{
				printf("%s\n",arr[j].str);
			}
		}
	}
	fclose(fp);
 	return 0;
}

