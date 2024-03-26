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
		int res[5];	
		for(int j=0;j<25;j++){
			scanf("%d",&num[j]);
		}
		mergeSort(num,0,24);
//		for(int j=0;j<25;j++){
//			printf("%d ",num[j]);
//		}
//		printf("\n");
		res[0]=num[0]/2;
		res[1]=num[1]-res[0];
		res[4]=num[24]/2;
		res[3]=num[23]-res[4];
		
		if(num[3]==res[1]*2){
			res[2]=num[4]-res[0];
		}
		else{
			res[2]=num[3]-res[0];	
		}
		
		printf("Case #%d: ",i);
		
		for(int j=0;j<5;j++){
			if(j<4) printf("%d ",res[j]);
			else printf("%d\n",res[j]);
		}
	}
	
 	return 0;
}

