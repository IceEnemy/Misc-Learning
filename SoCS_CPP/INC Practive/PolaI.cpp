#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n;i++){
		if(i % k != 0) printf("%d",i);
		else printf("*");
		if(i==n) printf("\n");
		else printf(" ");
	}
 	return 0;
}

