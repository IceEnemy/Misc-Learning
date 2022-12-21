#include <stdio.h>
#include <string.h>

struct grade{
	char subject[15];
	int deadline;
};

void sort(struct grade data[],int left,int mid,int right){
	int lSize=mid-left+1;
	int rSize=right-mid;
	struct grade lStruct[lSize],rStruct[rSize];
	for(int i=0;i<lSize;i++){
		lStruct[i]=data[left+i];
	}
	for(int i=0;i<rSize;i++){
		rStruct[i]=data[mid+1+i];
	}
	int lCount=0,rCount=0,sCount=left;
	while(lCount<lSize && rCount<rSize){
		if(lStruct[lCount].deadline<rStruct[rCount].deadline) data[sCount++]=lStruct[lCount++];
		else if(lStruct[lCount].deadline>rStruct[rCount].deadline) data[sCount++]=rStruct[rCount++];
		else{
			if(strcmp(lStruct[lCount].subject,rStruct[rCount].subject) < 0) data[sCount++]=lStruct[lCount++];
			else data[sCount++]=rStruct[rCount++];
		}
	}
	while(lCount<lSize) data[sCount++]=lStruct[lCount++];
	while(rCount<rSize) data[sCount++]=rStruct[rCount++];
}

void mergeSort(struct grade data[],int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(data,left,mid);
		mergeSort(data,mid+1,right);
		sort(data,left,mid,right);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	struct grade data[n];
	for(int i=0;i<n;i++){
		scanf("%s %d",data[i].subject,&data[i].deadline);
	}
	
	mergeSort(data,0,n-1);
	
	for(int i=0;i<n;i++){
		printf("%s\n",data[i].subject);
	}
 	return 0;
}

