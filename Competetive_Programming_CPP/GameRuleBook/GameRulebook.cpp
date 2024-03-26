#include <stdio.h>
#include <string.h>

struct book{
	char page[10010];
};

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int n,line;
	fscanf(fp,"%d %d\n",&n,&line);
	struct book reading[110];
	for(int i=1;i<=n;i++){
		fscanf(fp,"%[^#]#\n",reading[i].page);
	}
	int which;
	fscanf(fp,"%d\n",&which);
	printf("%s",reading[which].page);
	fclose(fp);
 	return 0;
}

