#include <bits/stdc++.h>
using namespace std;

int n, k;
bool used[9];
int num[9];

void perm(int depth){
	if(depth >= k){
		for(int i=0; i<k-1; i++){
			if(num[i] > num[i+1]) return;
		}
		for(int i=0; i<k; i++){
			if(i == k-1){
				printf("%d\n",num[i]);	
			}
			else{
				printf("%d ",num[i]);
			}
		}
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
	cin >> n >> k;
	perm(0);
 	return 0;
}

