#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	int K;
	cin >> str >> K;
	int len = str.length();
	for(int i=0; i<len; i++){
		if(str[i]+K > 'z') str[i] = 'a'+K-('z'-str[i]+1);
		else str[i] += K;
	}
	cout << str;
 	return 0;
}

