#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string str,rvr;
	cin >> N;
	cin >> str;
	int Q;
	cin >> Q;
	for(int i=0; i<Q; i++){
		cin >> rvr;
		bool pos = true;
		string temp;
		int idx = 0;
		for(int j=0; j<N; j++){
			temp += rvr[j];
			if(str[N-idx-1] == rvr[j]){
				if(str.substr(N-j-1,j-idx+1) == temp){
					idx = j+1;
					temp = "";
				} 
			}
			if(j == N-1 && temp != ""){
				pos = false;
//				printf("hey\n");
			} 
		}
		if(pos) printf("YES\n");
		else printf("NO\n");
	}
 	return 0;
}

