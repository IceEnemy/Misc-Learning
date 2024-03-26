#include <bits/stdc++.h>
using namespace std;

struct murid{
	int x,y;
};

int T(int x1, int y1, int x2, int y2, int d){
	return pow(abs(x2-x1),d) + pow(abs(y2-y1),d);
}

int main()
{
	int N,D;
	scanf("%d %d",&N, &D);
	murid deket[N+1];
	int max = -1;
	int min = INT_MAX;
	for(int i=0; i<N; i++){
		scanf("%d %d",&deket[i].x,&deket[i].y);
		for(int j=i-1; j>=0; j--){
//			printf("%d %d\n",i,j);
			int pdkt = T(deket[i].x,deket[i].y,deket[j].x,deket[j].y,D);
			if(pdkt > max) max = pdkt;
			if(pdkt < min) min = pdkt;
		}
	}
	
	printf("%d %d\n",min,max);
 	return 0;
}

