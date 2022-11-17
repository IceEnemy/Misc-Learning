#include <stdio.h>
int main()
{
	int s;
	scanf("%d",&s);
	int team[s][s];
	int inc[110];
	int sum=0;
	for(int i=0;i<=s;i++){
		inc[i]=0;
	}
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			scanf("%d",&team[i][j]);
			inc[team[i][j]]++;
		}
	}
	for(int i=1;i<=s;i++){
		if(inc[i]<s){
			sum++;
		}
	}
	printf("%d\n",sum);
 	return 0;
}
