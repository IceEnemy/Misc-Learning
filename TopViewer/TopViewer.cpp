#include <stdio.h>
#include <string.h>

struct bee{
	char channel[1010];
	char name[1010];
	int view;
};

void sort(struct bee data[],int left, int mid, int right){
	int lSize=mid-left+1;
	int rSize=right-mid;
	struct bee lStruct[lSize], rStruct[rSize];
	for(int i=0;i<lSize;i++){
		lStruct[i]=data[left+i];
	}
	for(int i=0;i<rSize;i++){
		rStruct[i]=data[mid+1+i];
	}
	int lCount=0,rCount=0,sCount=left;
	while(lCount<lSize && rCount<rSize){
		if(lStruct[lCount].view>rStruct[rCount].view){
			data[sCount++]=lStruct[lCount++];
		}
		else if(lStruct[lCount].view<rStruct[rCount].view){
			data[sCount++]=rStruct[rCount++];
		}
		else{
			if(strcmp(lStruct[lCount].channel,rStruct[rCount].channel) < 0){
				data[sCount++]=lStruct[lCount++];
			}
			else{
				data[sCount++]=rStruct[rCount++];	
			}
		}
	}
	while(lCount<lSize) data[sCount++]=lStruct[lCount++];
	while(rCount<rSize) data[sCount++]=rStruct[rCount++];
}

void mergeSort(struct bee data[],int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(data,left,mid);
		mergeSort(data,mid+1,right);
		sort(data,left,mid,right);
	}
}

int main()
{
	FILE *fp = fopen("testdata.in","r");
	struct bee data[110];
	int n=0;
	while(fscanf(fp,"%[^#]#%[^#]#%d\n",data[n].channel,data[n].name,&data[n].view) != EOF){
		n++;
	}
//	printf("%d\n",n);
	mergeSort(data,0,n-1);
	
	
	for(int i=0;i<n;i++){
		printf("%s by %s - %d\n",data[i].channel,data[i].name,data[i].view);
	}
	
	fclose(fp);
 	return 0;
}

