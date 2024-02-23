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

void min(int *dif){
	if((*dif)<0){
		(*dif)*=-1;
	}
}

int minus(int n){
	if(n<0){
		n*=-1;
	}
	return n;
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
	int dif;
	int max=num[0]-num[1];
	int counter=1;
	min(&max);
	for(int i=1;i<n-1;i++){
		dif=num[i]-num[i+1];
		min(&dif);
		if(dif>max){
			max=dif;
			counter=1;
		}
		else if(dif==max) counter++;
	}
	for(int i=0;i<n-1;i++){
		dif=num[i]-num[i+1];
		min(&dif);
		if(dif==max){
			if(counter>1){
				printf("%d %d ",num[i], num[i+1]);
				counter--;
			}
			else printf("%d %d\n",num[i],num[i+1]);
		}
	}
//	for(int i=0;i<n;i++){
//		printf("%d ",num[i]);
//	}
	
 	return 0;
}

