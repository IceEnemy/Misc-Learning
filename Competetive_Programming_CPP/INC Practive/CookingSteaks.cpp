#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int N;
	cin >> N;
	long long int time[N];
	long long int stock[N];
	long long int orders[N];
	long long int total = 0;
	
	for(int i=0; i<N-1; i++){
		cin >> time[i];
	}
	for(int i=0; i<N; i++){
		cin >> stock[i];
	}
	for(int i=0; i<N; i++){
		cin >> orders[i];
	}
	for(int i=N-1; i>=0;i--){
		if(stock[i]<orders[i]){
			long long int cooking = 0;
			for(int j=i-1; j>=0;j--){
				if(stock[i]>=orders[i]) break;
				else if(stock[j] == 0) continue;
				cooking+=time[j];
				if(stock[j]+stock[i]>=orders[i]){
					int diff = orders[i]-stock[i];
					stock[j] -= diff;
					stock[i] += diff;
					total+= (diff*cooking);
				}
				else{
					stock[i]+= stock[j];
					total += (stock[j]*cooking);
					stock[j] = 0;
				}
			}
		}
		if(stock[i]<orders[i]){
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << total << endl;
 	return 0;
}

