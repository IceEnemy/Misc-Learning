#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s,int x, int y){
	if(x<y){
		if(s[x] == s[y]) return palindrome(s,x+1,y-1);
		return false;	
	}
	return true;
}

int main()
{
	string s;
	cin >> s;
	if(palindrome(s,0,(s.length()-1))) cout << "YA" << endl;
	else cout << "BUKAN" << endl;
 	return 0;
}

