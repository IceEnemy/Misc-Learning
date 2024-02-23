#include <stdio.h>
#include <string.h>

struct studentData{
	char NIM[15];
	char name[30];
};

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int n;
	fscanf(fp,"%d",&n);
//	printf("%d\n",n);
	struct studentData data[n];
	for(int i=0;i<n;i++){
		fscanf(fp,"%s %s",data[i].NIM,data[i].name);
	}
//	for(int i=0;i<n;i++){
//		printf("%s %s\n",data[i].NIM,data[i].name);
//	}
	int test;
	fscanf(fp,"%d",&test);
	for(int i=1;i<=test;i++){
		char target[15];
		fscanf(fp,"%s",target);
		for(int j=0;j<n;j++){
			if(strcmp(data[j].NIM,target)==0){
				printf("Case #%d: %s\n",i,data[j].name);
				break;
			}
			if(j==n-1) printf("Case #%d: N/A\n",i);
		}
	}
	
	fclose(fp);
 	return 0;
}

