#include <stdio.h>
#include <string.h>

struct studentData{
	char ID[25];
	char name[110];
	char score[5];
};

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	struct studentData data[n];
	for(int i=0;i<n;i++){
		scanf("%s",data[i].ID); getchar();
		scanf("%[^\n]",data[i].name); getchar();
		scanf("%s",data[i].score); getchar();
	}
	int q;
	scanf("%d",&q);
	getchar();
	for(int i=1;i<=q;i++){
		int query;
		scanf("%d",&query);
		getchar();
		printf("Query #%d:\n",i);
		printf("ID: %s\n",data[query-1].ID);
		printf("Name: %s\n",data[query-1].name);
		printf("Score: %s\n",data[query-1].score);
	}
 	return 0;
}

