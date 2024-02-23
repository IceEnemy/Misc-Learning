#include <stdio.h>
#include <string.h>

struct studentData{
	char code[10];
	char day[20];
	int time;
};

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	struct studentData data[n];
	for(int i=0;i<n;i++){
		scanf("%s",data[i].code); getchar();
		scanf("%s",data[i].day); getchar();
		scanf("%d",&data[i].time); getchar();
	}
	int q;
	scanf("%d",&q);
	getchar();
	for(int i=1;i<=q;i++){
		int query;
		scanf("%d",&query);
		getchar();
		printf("Query #%d:\n",i);
		printf("Code: %s\n",data[query-1].code);
		printf("Day: %s\n",data[query-1].day);
		printf("Time: %02d:00\n",data[query-1].time);
	}
 	return 0;
}

