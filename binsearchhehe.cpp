#include <stdio.h>
#include <string.h>

void binarySearch(int num[],int l,int r,int target){
//	printf("%d %d\n",l,r);
	while(l<=r){
//		printf("%d %d\n",l,r);
		int m=l+(r-l)/2;
		if(num[m-1] == target && m != 0){
			r = m-1;
		}
		else if(num[m] == target){
			int count=1;
			int idx=m;
			while(num[idx+1]==target){
				idx++;
				count++;
			}
			for(int i=m;i<m+count;i++){
				if(i<m+count-1){
					printf("%d ",i);
				}
				else{
					printf("%d\n",i);
				}
			}
			return;
		}
		else if(num[m] < target){
			l = m+1;
		}
		else if(num[m] > target){
			r = m-1;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	int target;
	scanf("%d",&target);
	binarySearch(num,0,n-1,target);
 	return 0;
}

