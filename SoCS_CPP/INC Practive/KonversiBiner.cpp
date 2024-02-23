#include <bits/stdc++.h>
using namespace std;

string bin(int dec){
	if(dec == 1) return "1";
	else if(dec % 2 == 1) return bin(dec/2) + "1";
	else return bin(dec/2) + "0";
}

int main()
{
	int dec;
	cin >> dec;
	cout << bin(dec);
 	return 0;
}

