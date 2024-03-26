#include <bits/stdc++.h>
using namespace std;

bool pattern(string substr, string str){
	int lenSub = substr.length();
	int len = str.length();
	if(lenSub-1 > len) return false;
	for(int i=0; substr[i] != '*'; i++){
		if(substr[i] != str[i]) return false;
	}
	for(int i=1; substr[lenSub-i] != '*'; i++){
		if(substr[lenSub-i] != str[len-i]) return false;
	}
	return true;
}

int main()
{
	string substr,str;
	int N;
	cin >> substr >> N;
	for(int i=0; i<N; i++){
		cin >> str;
		if(pattern(substr,str)) cout << str << endl;
	}
 	return 0;
}

