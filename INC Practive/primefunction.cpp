#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
bool isPrime[MAX];

void primeStore(){
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i=2;i*i<MAX;i++){
		if(isPrime[i]){
			for(int j=i*i;j<MAX;j+=i){
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	primeStore();
	int test,n;
	scanf("%d",&test);
	for(int i=0; i<test;i++){
		scanf("%d",&n);
		if(isPrime[n] == true){
			printf("YA\n");
		}
		else{
			printf("BUKAN\n");
		}
	}

 	return 0;
}

