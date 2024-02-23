#include <bits/stdc++.h>
using namespace std;

void permutation(int arr[], int l, int r){
	if(l == r){
		for(int i=1; i<r; i++){
			if((arr[i] > arr[i-1] && arr[i] < arr[i+1]) || (arr[i] < arr[i-1] && arr[i] > arr[i+1])) return;
		}
		for(int i=0; i<=r; i++){
			cout << arr[i];
		}
		printf("\n");
	}
	else{
		for(int i=l; i<=r; i++){
			swap(arr[l],arr[i]);
			
			permutation(arr,l+1,r);
			
			swap(arr[l],arr[i]);
		}	
	}
}


int main(){
	int N;
	cin >> N;
	int arr[N];
	for(int i=0; i<N; i++){
		arr[i] = i+1;
	}
	permutation(arr,0,N-1);
	
 	return 0;
}

