#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, MIN, MAX;
	int inp;
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		scanf("%d",&inp);
		if(i == 0){
			MIN = MAX = inp;
		}
		else if(inp > MAX) MAX = inp;
		else if(inp < MIN) MIN = inp;
	}
	printf("%d %d\n",MAX,MIN);
 	return 0;
}

