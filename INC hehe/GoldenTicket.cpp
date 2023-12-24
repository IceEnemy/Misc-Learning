#include <bits/stdc++.h>
using namespace std;

int N,M,K;

struct teams{
	string name;
	string inst;
} compet[100];



int main()
{
	vector<string> gold;
	vector<string> already;
	cin >> N >> M >> K;
	int tickets = 0;
	for(int i=0; i<N; i++){
		if(tickets >= K) break;
		cin >> compet[i].name >> compet[i].inst;
		if(i<M) already.push_back(compet[i].inst);
		else{
			int alr = 0;
			int size = already.size();
			for(int j=0; j<size; j++){
//				cout << compet[i].inst << "=" <<already[j] << endl;
				if(compet[i].inst == already[j]){
					alr = 1;
					break;
				}
			}
			if(alr != 1){
//				cout << "hey" << endl;
				gold.push_back(compet[i].name);
				already.push_back(compet[i].inst);
				tickets++;
			}
		}
	}
	int size = gold.size();
	if(size == 0) cout << "0" << endl;
	else{
		cout << size << endl;
		for(int i=0; i<size; i++){
			cout << gold[i] << endl;
		}	
	}
 	return 0;
}

