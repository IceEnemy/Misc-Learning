#include <stdio.h>
#include <string.h>

struct plantData{
	int num;
	char plant[50];
};

void merge(struct plantData data[],int left,int mid,int right){
	int lSize=mid-left+1;
	int rSize=right-mid;
	struct plantData lStruct[lSize],rStruct[rSize];
	for(int i=0;i<lSize;i++){
		lStruct[i]=data[left+i];
	}
	for(int i=0;i<rSize;i++){
		rStruct[i]=data[mid+1+i];
	}
	int lCount=0,rCount=0,sCount=left;
	while(lCount<lSize && rCount<rSize){
		if(strcmp(lStruct[lCount].plant,rStruct[rCount].plant) < 0){
			data[sCount++]=lStruct[lCount++];
		}
		else{
			data[sCount++]=rStruct[rCount++];
		}
	}
	while(lCount < lSize){
		data[sCount++]=lStruct[lCount++];
	}
	while(rCount < rSize){
		data[sCount++]=rStruct[rCount++];
	}
}

void mergeSort(struct plantData data[],int left, int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(data,left,mid);
		mergeSort(data,mid+1,right);
		merge(data,left,mid,right);
	}
}


int main()
{
	FILE *fp = fopen("testdata.in","r");
	int amount;
	fscanf(fp,"%d",&amount);
//	printf("%d\n",amount);
	struct plantData data[1010];
	for(int i=0;i<amount;i++){
		fscanf(fp,"%d#%[^\n]",&data[i].num,data[i].plant);
	}
	
	mergeSort(data,0,amount-1);
	
	for(int i=0;i<amount;i++){
		printf("%d %s\n",data[i].num,data[i].plant);
	}
	fclose(fp);
 	return 0;
}

