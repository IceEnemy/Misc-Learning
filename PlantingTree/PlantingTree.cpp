#include <stdio.h>
#include <string.h>

struct plant{
	char name[45];
	char tree[45];
};

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int n;
	fscanf(fp,"%d\n",&n);
//	printf("%d\n",n);
	struct plant data[n];
	for(int i=0;i<n;i++){
		fscanf(fp,"%[^#]#%[^\n]\n",data[i].name,data[i].tree);
	}
//	for(int i=0;i<n;i++){
//		printf("%s %s\n",data[i].name,data[i].tree);
//	}
	int t;
	fscanf(fp,"%d\n",&t);
	char subject[45];
	for(int i=1;i<=t;i++){
		fscanf(fp,"%[^\n]\n",subject);
//		printf("%s\n",subject);
		for(int j=0;j<n;j++){
			if(strcmp(subject,data[j].name) == 0){
				printf("Case #%d: %s\n",i,data[j].tree);
				break;
			}
			else if(j==n-1){
				printf("Case #%d: N/A\n",i);
			}
		}
	}
	
	
	fclose(fp);
 	return 0;
}

