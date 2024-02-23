#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int target){
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target){
            return mid;
        } 
		else if (arr[mid] < target){
            left = mid + 1;
        } 
		else{
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
	long long int res = 0;
	int powers[210000];
	memset(powers,0,sizeof(powers));
	int N;
	scanf("%d",&N);
	getchar();
	vector<int> visit;
	int MAX = 0;
	for(int i=0; i<N; i++){
		bool even = true;
		int x;
		char op;
		scanf(" %c %d",&op,&x);
		if(op == '-') {
			powers[x]--;
			if(powers[x] == 0){
				int bin = binarySearch(visit,x);
				if(bin != -1){
					visit.erase(visit.begin()+bin);
				}
			}
			while(powers[x] == -2){
				powers[x]+=2;
				int bin = binarySearch(visit,x);
				if(bin != -1){
					visit.erase(visit.begin()+bin);
				}
				x++;
				powers[x]-=1;
			}
			if(powers[x] == 0){
				int bin = binarySearch(visit,x);
				if(bin != -1){
					visit.erase(visit.begin()+bin);
				}
			}
			if(x > MAX) MAX = x;
		}
		else{
			powers[x]++;
			if(powers[x] == 0){
				int bin = binarySearch(visit,x);
				if(bin != -1){
					visit.erase(visit.begin()+bin);
				}
			}
			while(powers[x] == 2){
				powers[x]-=2;
				int bin = binarySearch(visit,x);
				if(bin != -1){
					visit.erase(visit.begin()+bin);
				}
				x++;
				powers[x]+=1;
			}
			if(powers[x] == 0){
				int bin = binarySearch(visit,x);
				if(bin != -1){
					visit.erase(visit.begin()+bin);
				}
			}
			if(x>MAX) MAX = x;
			
		}	
		if(powers[x] != 0){
			if(binarySearch(visit,x) == -1){
				visit.push_back(x);	
				sort(visit.begin(),visit.end());
			}	
		}
		int size = visit.size();
		
//		printf("\n");
		if(size == 0){
			printf("YES\n");
		} 
		else printf("NO\n");
	}
 	return 0;
}

