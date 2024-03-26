#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,T;
	cin >> N >> T;
	int num[N];
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
	sort(num,num+N);
	int MAX = 0;
	int counter = 0;
	for(int i=0; i<N-2; i++){
		for(int j=i+2; j<N; j++){
			if(num[j]-num[i] > T) break;
			MAX = num[i] + num[j-1] + num[j];
			counter += j-i-1;
		}
	}
	if(counter == 0) cout << "-1" << endl;
	else cout << counter << " " << MAX << endl;
 	return 0;
}

