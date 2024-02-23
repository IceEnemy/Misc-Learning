#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int flag = 0;
	while(s.find('_') != -1){
		int idx = s.find('_');
		s[idx+1] -= 'a' -'A';
		s.erase(s.find('_'),1);
		flag = 1;
	}
	if(flag == 0){
		for(int i=0; i<s.length(); i++){
			if(s[i] <= 'Z' && s[i] >= 'A'){
				s[i] += 'a' - 'A';
				string under = "_";
				s.insert(i,under);
			}
		}
	}
	cout << s;
 	return 0;
}

