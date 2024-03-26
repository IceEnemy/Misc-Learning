#include <bits/stdc++.h>
//#include <algorithm>
//#include <iostream>

using namespace std;

int main()
{
	long long int A,B,C,D;
	
	cin >> A >> B >> C >> D;
	
	long long int num,denom;
	
	num = (A*D) + (C*B);
	denom = B * D;
	
	long long int GCD = gcd(num,denom);
	
	printf("%lld %lld\n",num/GCD,denom/GCD);
 	return 0;
}

