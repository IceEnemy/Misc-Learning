#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test,n;
	scanf("%d",&test);
	for(int i=0;i<test;i++){
		int flag = 0;
		scanf("%d",&n);
		int count = n;
		for(int j=2;j<count;j++){
			if(n%j == 0){
				flag++;
				count = n/j;
			}
			if(flag > 1) break;
		}
		if(flag > 1) printf("BUKAN\n");
		else printf("YA\n");
	}
 	return 0;
}

