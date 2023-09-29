#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0; j<i;j++){
			printf("%d",num%10);
			num++;
		}
		printf("\n");
	}
 	return 0;
}

