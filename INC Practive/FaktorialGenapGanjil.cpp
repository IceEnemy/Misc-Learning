#include <bits/stdc++.h>
using namespace std;

int factorial(int x){
	if(x == 1) return 1;
	else if(x%2==1) return x*factorial(x-1);
	else return x/2 * factorial(x-1);
}

int main()
{
	int n;
	cin >> n;
	cout << factorial(n);
 	return 0;
}

