#include <bits/stdc++.h>
using namespace std;

int main()
{
	int inp;
	scanf("%d",&inp);
	while(inp != 1 && inp % 2 != 1){
		inp/=2;
	}
	if(inp == 1) printf("ya\n");
	else printf("bukan\n");
 	return 0;
}

