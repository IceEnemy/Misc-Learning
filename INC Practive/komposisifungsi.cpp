#include <bits/stdc++.h>
using namespace std;

int f(int A, int B, int x, int K){
	if(K>1){
		return abs((A*f(A,B,x,K-1))+B);
	}
	else return abs((A*x)+B);
}

int main()
{
	int A,B,K,x;
	scanf("%d %d %d %d",&A, &B, &K, &x);
	
	printf("%d\n",f(A,B,x,K));
 	return 0;
}

