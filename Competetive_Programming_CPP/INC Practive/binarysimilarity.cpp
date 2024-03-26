#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	int n;
	scanf("%d",&test);
	for(int i=0;i<test;i++){
		char bin[101];
		char ans[51];
		char corr;
		scanf("%d",&n);
		scanf("%s",bin); getchar();
		if(bin[n-1] == '1') corr = '1';
		else corr = '0';
		for(int j = 0; j<n; j++){
//			ans[j] = corr;
			printf("%c",corr);
		}
		printf("\n");
	}
 	return 0;
}

