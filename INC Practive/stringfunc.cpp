#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str, substr;
	cin >> str >> substr;
	while(str.find(substr) != -1){
		str.erase(str.find(substr), substr.length());
	}
	cout << str;
 	return 0;
}

