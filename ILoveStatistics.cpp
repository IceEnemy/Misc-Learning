#include <stdio.h>

void merge(double num[],int left,int mid,int right){
	int lSize=mid-left+1;
	int rSize=right-mid;
	double lArr[lSize],rArr[rSize];
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

void mergeSort(double num[],int left,int right){
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
		int n;
		scanf("%d",&n);
		double num[n];
		double res=0;
		for(int j=0;j<n;j++){
			scanf("%lf",&num[j]);
			res+=num[j];
		}
		mergeSort(num,0,n-1);
//		for(int j=0;j<n;j++){
//			printf("%d ",num[j]);
//		}
		double mean=res/n;
		double median;
		if(n%2==1){
			median=num[n/2];
		}
		else{
			median=(num[n/2]+num[n/2-1])/2;
		}
		printf("Case #%d:\n",i);
		printf("Mean : %.2lf\n",mean);
		printf("Median : %.2lf\n",median);
	}
 	return 0;
}

