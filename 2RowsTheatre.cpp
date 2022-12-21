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

void min(int *num){
	if((*num)<0) (*num)*=-1;
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		scanf("%d",&n);
		int num[n];
		for(int j=0;j<n;j++){
			scanf("%d",&num[j]);
		}
		mergeSort(num,0,n-1);
		int max=0;
		int dif;
//		for(int j=0;j<n;j++){
//			printf("%d ",num[j]);
//		}
		for(int j=0;j<n/2-1;j++){
			dif=num[j]-num[j+1];
			min(&dif);
//			printf("dif: %d\n",dif);
			if(dif>max){
				max=dif;
			}
		}
		for(int j=n/2;j<n-1;j++){
			dif=num[j]-num[j+1];
			min(&dif);
//			printf("dif: %d\n",dif);
			if(dif>max){
				max=dif;
			}
		}
		printf("Case #%d: %d\n",i,max);
	}
 	return 0;
}

