#include <bits/stdc++.h>
using namespace std;

int N, X;

struct rice{
	int kg;
	double price;
} bag[1010];

bool constraint(const rice& bag1, const rice& bag2){
	if(bag1.price > bag2.price) return true;
	return false;
}

int main()
{
	cin >> N >> X;
	for(int i=0; i<N; i++){
		cin >> bag[i].kg;
	}
	for(int i=0; i<N; i++){
		cin >> bag[i].price;
		bag[i].price /= bag[i].kg;
	}
	sort(bag,bag+N,constraint);
	double res = 0;
	int i = 0;
	while(X > 0 && i != N){
		if(X >= bag[i].kg){
			res += bag[i].kg*bag[i].price;
			X -= bag[i].kg;
		}
		else{
			res += X * bag[i].price;
			X = 0;
		}
		i++;
	}
	printf("%.5lf\n",res);
 	return 0;
}

