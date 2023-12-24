#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000001;
bool isPrime[maxN];

//void prime(){
//	memset(isPrime, true, sizeof(isPrime));
//	isPrime[0] = false;
//	isPrime[1] = false;
//	for(int i=0; i*i < maxN; i++){
//		if(isPrime[i] == true){
//			for(int j=i*i; j<maxN; j+=i){
//				isPrime[j] = false;
//			}
//		}
//	}
//}

int factors(int num, int div){
	int rank = 0;
	while(num%div == 0){
		num/=div;
		rank++;
	}
	printf("%d",div);
	if(rank > 1) printf("^%d",rank);
	return num;
}

int main()
{
//	prime();
	int n;
	scanf("%d",&n);
	int flag = 0;
	for(int i=2; i<=n; i++){
		if(n%i == 0){
			if(flag == 1) printf(" x ");
			else flag = 1;
			n = factors(n,i);
		}
	}
	printf("\n");
 	return 0;
}

