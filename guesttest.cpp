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

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int num[25];
		int result[5];
		for(int j=0;j<25;j++){
			scanf("%d",&num[j]);
		}
		mergeSort(num,0,24);
//		for(int j=0;j<25;j++){
//			printf("%d ",num[j]);
//		}
//		printf("\n");
		result[0]=num[0]/2;
		result[4]=num[24]/2;
		result[1]=num[1]-result[0];
		result[3]=num[23]-result[4];
		result[2]=num[4]-result[0];
		
		printf("Case #%d: ",i);
		for(int j=0;j<5;j++){
			if(j<4) printf("%d ",result[j]);
			else printf("%d\n",result[j]);
		}
//		printf("\n");
	}
 	return 0;
}

