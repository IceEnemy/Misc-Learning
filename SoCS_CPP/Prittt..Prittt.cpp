#include <stdio.h>

void merge(int num[],int left,int mid,int right){
	int lSize=mid-left+1;
	int rSize=right-mid;
	int lArr[lSize],rArr[rSize];
	for(int i=0;i<lSize;i++){
		lArr[i]=num[left+i];
	}
	for(int i=0;i<rSize;i++){
		rArr[i]=num[mid+1+i];
	}
	int lCount=0,rCount=0,sCount=left;
	while(lCount<lSize && rCount<rSize){
		if(lArr[lCount]<rArr[rCount]){
			num[sCount++]=lArr[lCount++];
		}
		else{
			num[sCount++]=rArr[rCount++];
		}
	}
	while(lCount<lSize){
		num[sCount++]=lArr[lCount++];
	}
	while(rCount<rSize){
		num[sCount++]=rArr[rCount++];
	}
}

void mergeSort(int num[],int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(num,left,mid);
		mergeSort(num,mid+1,right);
		merge(num,left,mid,right);
	}
}

int binarySearch(int num[],int height,int left,int right){
	while(left<=right){
		int mid=left+(right-left)/2;
//		printf("%d",num[mid]);
		if(num[mid]==height){
			return mid;
		}
		else if(num[mid]<height){
			left=mid+1;
		}
		else if(num[mid]>height){
			right=mid-1;
		}
	}
	return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	mergeSort(num,0,n-1);
//	for(int i=0;i<n;i++){
//		printf("%d ",num[i]);
//	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int height;
		scanf("%d",&height);
		int res=binarySearch(num,height,0,n-1);
		if(res>=0){
			res++;
		}
		printf("%d\n",res);
	}
 	return 0;
}

