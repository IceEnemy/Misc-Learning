#include <bits/stdc++.h>
using namespace std;

int main()
{
	int powers[210000];
	memset(powers,0,sizeof(powers));
	int N;
	scanf("%d",&N);
	getchar();
	vector<int> visit;
	int MAX = -1;
	int MIN = 300000;
	for(int i=0; i<N; i++){
		int x;
		char op;
		scanf(" %c %d",&op,&x);
		if(op == '-') {
			powers[x]--;
			if(x < MIN) MIN = x;
			while(powers[x] == -2){
				powers[x]+=2;
				if(x == MIN) MIN = 300000;
				if(x == MAX) MAX = -1;
				x++;
				powers[x]-=1;
			}
			if(x > MAX) MAX = x;
		}
		else{
			powers[x]++;
			if(x < MIN) MIN = x;
			while(powers[x] == 2){
				powers[x]-=2;
				if(x == MIN) MIN = 300000;
				if(x == MAX) MAX = -1;
				x++;
				powers[x]+=1;
			}
			if(x>MAX) MAX = x;
		}
		if(powers[x] == 0){
			if(x == MIN) MIN = 300000;
			if(x == MAX) MAX = -1;
		}
		if(MAX == -1 && MIN == 300000){
			printf("YES\n");
		} 
		else printf("NO\n");
	}
 	return 0;
}

