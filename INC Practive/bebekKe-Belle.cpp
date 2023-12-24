#include <bits/stdc++.h>
using namespace std;

int N,K;

int main()
{
	cin >> N >> K;
	int num[N];
	
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
	sort(num,num+N);
	cout << num[K-1] << endl;
 	return 0;
}

