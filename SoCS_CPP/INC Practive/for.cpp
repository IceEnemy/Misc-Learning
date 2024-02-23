#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test, plus, total;
	total = 0;
	scanf("%d",&test);
	for(int i=0; i<test;i++){
		scanf("%d",&plus);
		total += plus;
	}
	printf("%d\n",total);
 	return 0;
}

