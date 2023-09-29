#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int amount = 0;
	int modus;
	int big = 0;
	int bigamnt = 0;
	for(int i=0; i<n; i++){
		if(arr[i] != big){
			if(bigamnt >= amount){
				modus = big;
				amount = bigamnt;	
			}
			big = arr[i];
			bigamnt = 1;
		}
		else bigamnt++;
		if(i == n-1){
			if(bigamnt >= amount){
				modus = big;
				amount = bigamnt;	
			}
		}
	}
	printf("%d\n",modus);
 	return 0;
}

