#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m,a;
	
	cin >> n >> m >> a;
	int steps;
	
	if(n*m == a) steps = 0;
	else if(a % n == 0 || a % m == 0) steps = 1;
	else{
		int i;
		for(i=1; i<=n; i++){
			if(a % i == 0 && a/i <= m) break;
		}
		if(i <= n) steps = 2;
		else{
			a = n*m - a;
			for(i=1; i<=n; i++){
				if(a % i == 0 && a/i <= m) break;
			}
			if(i <= n) steps = 2;
			else steps = 3;
		}
	}
	cout << steps << endl;
 	return 0;
}

