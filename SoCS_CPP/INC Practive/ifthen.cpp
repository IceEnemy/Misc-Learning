#include <bits/stdc++.h>
using namespace std;

int main()
{
	int inp;
	scanf("%d",&inp);
	if(inp >= 10000) printf("puluhribuan\n");
	else if(inp >= 1000) printf("ribuan\n");
	else if(inp >= 100) printf("ratusan\n");
	else if(inp >= 10) printf("puluhan\n");
	else printf("satuan\n");
 	return 0;
}

