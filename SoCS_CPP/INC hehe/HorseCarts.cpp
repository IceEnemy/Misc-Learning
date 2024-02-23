#include <bits/stdc++.h>
using namespace std;

struct treasure{
	long long weight;
	long long price;
//	double ratio;
} chest[100010];

bool customComp(treasure a, treasure b){
	if(a.price == b.price) return a.price < b.price;
	return a.price > b.price;
}

int binarySearch(vector<long long>& cap, long long weight) {
    int left = 0;
    int right = cap.size() - 1;
    int result = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(cap[mid] >= weight){
            result = mid;
            right = mid - 1;
        } 
		else{
            left = mid + 1;
        }
    }
	if(result != -1){
		cap.erase(cap.begin()+result);
	}
    return result;
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<long long> cap (M);
	for(int i=0; i<N; i++){
		scanf("%lld %lld",&chest[i].weight, &chest[i].price);
//		chest[i].ratio = (double)chest[i].price/chest[i].weight;
	}
	sort(chest,chest+N,customComp);
//	for(int i=0; i<N; i++){
//		printf("%lld %lld %lf\n",chest[i].weight, chest[i].price, chest[i].ratio);
//	}
	for(int i=0; i<M; i++){
		scanf("%lld",&cap[i]);
	}
	sort(cap.begin(),cap.end());
	long long total = 0;
	int i = 0;
	int size = cap.size();
	while(i < N && size > 0){
		int binIdx = binarySearch(cap,chest[i].weight);
		if(binIdx != -1){
			total+= chest[i].price;
			size--;
		}
		i++;
	}
		
	
	cout << total << endl;
 	return 0;
}

