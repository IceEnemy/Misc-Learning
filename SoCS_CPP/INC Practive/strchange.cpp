#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test); getchar();
	for(int i=0;i<test;i++){
		int n;
		char c;
		char str[30001];
		int pos = -1;
		scanf("%d %c\n",&n, &c);
		for(int j=0;j<n;j++){
			scanf("%c",&str[j]);
			if(str[j] != c) pos = 1;
		}
		fflush(stdin);
		
		if(pos == 1){
			for(int k=n-1;k>n/2;k--){
				if(str[k] == c){
					printf("1\n%d\n",k+1);
					return 0;
				}
			}
			printf("2\n%d %d\n",n,n-1);
		}
		else printf("0\n");
	}
 	return 0;
}

