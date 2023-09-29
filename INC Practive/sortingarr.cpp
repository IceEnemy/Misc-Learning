#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[101];
	int i=0;
	while(scanf("%d",&arr[i]) != EOF){
		i++;
	}
	for(int j=i-1;j>=0;j--){
		printf("%d\n",arr[j]);
	}
 	return 0;
}

