#include <bits/stdc++.h>
using namespace std;

int main()
{
	int inp;
	scanf("%d",&inp);
	int square = sqrt(inp);
	int ans = square * 4;
	
	if(inp>square*square){
		inp-=(square*square);
		if(inp>square){
			ans+=4;
		}
		else ans+=2;
	}


	printf("%d\n",ans);
 	return 0;
}

