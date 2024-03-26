#include <bits/stdc++.h>
using namespace std;

void fractal(int n){
	if(n == 0) return;
	fractal(n-1);
	for(int i=0; i<n; i++){
		printf("*");
	}
	printf("\n");
	fractal(n-1);
}

int main()
{
	int size;
	cin >> size;
	fractal(size);
 	return 0;
}

