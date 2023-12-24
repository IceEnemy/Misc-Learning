#include <bits/stdc++.h>
// #include <iostream>
using namespace std;

int N, M ,K;

int main()
{
	cin >> N >> M >> K;
	int res = 0;
	int day = 0;
	int num[N] = {0};
	priority_queue<int> MAX;
	if(K >= N) {
		for(int i=0; i<N; i++){
			scanf("%d",&num[i]);
		}
		day = N;	
	}
	else{
		for(int i=0; i<N; i++){
			scanf("%d",&num[i]);
			res+=num[i];
			MAX.push(num[i]);
			if(res > M && K > 0){
				res-=MAX.top();
				MAX.pop();
				day++;
				K--;
			}
			else if(res > M && K <= 0){
				break;
			}
			else{
				day++;
			}
		}
	}
	cout << day << endl;
 	return 0;
}

