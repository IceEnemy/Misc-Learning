#include <bits/stdc++.h>
using namespace std;

int main()
{
	int inp;
	scanf("%d",&inp);
	for(int i = inp; i > 0; i--){
		if(inp % i == 0) printf("%d\n",i);
	}
 	return 0;
}

