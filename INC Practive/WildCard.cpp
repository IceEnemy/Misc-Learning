#include <bits/stdc++.h>
using namespace std;

int main()
{
	string sub;
	cin >> sub;
	int N;
	cin >> N;
	vector<string> strings(N,"");
	for(int i=0; i<N; i++){
		cin >> strings[i];
	}
	if(sub == "*"){
		for(int i=0; i<N; i++){
			cout << strings[i] << endl;
		}
	}
	else if(sub.find("*") == 0){
		sub.erase(0,1);
//		cout << sub;
		for(int i=0; i<N; i++){
			if(strings[i].find(sub) + sub.length() == strings[i].length()) cout << strings[i] << endl;
		}
	}
	else if(sub.find("*") == sub.length() - 1){
		sub.erase(sub.length() - 1);
		for(int i=0; i<N; i++){
			if(strings[i].find(sub) == 0) cout << strings[i] << endl;
		}
	}
	else{
		string endSub = sub.substr(sub.find("*")+1);
		sub.erase(sub.find("*"));
		for(int i=0; i<N; i++){
			if(strings[i].find(endSub) + endSub.length() == strings[i].length() && strings[i].find(sub) == 0) cout << strings[i] << endl;
		}
	}
	
 	return 0;
}

