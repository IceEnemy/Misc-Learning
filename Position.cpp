#include <stdio.h>

int binarySearch(int num[],int l,int r,int target){
	while(l<=r){
		int m=l+(r-l)/2;
		if(num[m-1]==target){
			r=m-1;
		}
		else if(num[m]>target){
			r=m-1;
		}
		else if(num[m]<target){
			l=m+1;
		}
		else{
			return m+1;
		}
	}
	return -1;
}

int main()
{
	int n;
	int tar;
	scanf("%d %d",&n,&tar);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<tar;i++){
		int target;
		scanf("%d",&target);
		printf("%d\n",binarySearch(num,0,n-1,target));
	}
 	return 0;
}

