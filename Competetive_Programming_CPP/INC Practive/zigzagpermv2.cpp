#include <bits/stdc++.h>
using namespace std;

int n;
bool used[9];
int num[9];

void perm(int depth){
	if(depth >= n){
		for(int i=1; i<n-1; i++){
			if((num[i] > num[i-1] && num[i] < num[i+1]) || (num[i] < num[i-1] && num[i] > num[i+1])) return;
		}
		for(int i=0; i<n; i++){
			printf("%d",num[i]);
		}
		printf("\n");
	}
	else{
		for(int i=1; i<=n; i++){
			if(!used[i-1]){
				used[i-1] = true;
				num[depth] = i;
				perm(depth+1);
				used[i-1] = false;
			}
		}
	}
}

int main()
{
	memset(used,false,sizeof(used));
	cin >> n;
	perm(0);
 	return 0;
}

