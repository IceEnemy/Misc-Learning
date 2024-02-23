#include <bits/stdc++.h>
using namespace std;

void swap(int &A, int &B){
	int temp = A;
	A = B;
	B = temp;
}

int main()
{
	int N;
	scanf("%d",&N);
	int A[N], B[N];
	
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d",&B[i]);
	}
	
	int T;
	scanf("%d",&T); getchar();
	char P,Q;
	int x,y;
	for(int i=0; i<T; i++){
		scanf("%c %d %c %d", &P, &x, &Q, &y);
		x--;
		y--;
		if(P == 'A'){
			if(Q == 'A') swap(A[x],A[y]);
			else swap(A[x],B[y]);
		}
		if(P == 'B'){
			if(Q == 'B') swap(B[x],B[y]);
			else swap(B[x],A[y]);
		}
	}
	
	for(int i=0; i<N; i++){
		if(i != N-1) printf("%d ",A[i]);
		else printf("%d\n",A[i]);
	}
	for(int i=0; i<N; i++){
		if(i != N-1) printf("%d ",B[i]);
		else printf("%d\n",B[i]);
	}
 	return 0;
}

