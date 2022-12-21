#include <stdio.h>
#include <string.h>

struct studentData{
	char NIM[15];
	char name[30];
};

void sort(struct studentData data[],int left,int mid,int right){
	int lSize=mid-left+1;
	int rSize=right-mid;
	struct studentData lStruct[lSize],rStruct[rSize];
	for(int i=0;i<lSize;i++){
		lStruct[i]=data[left+i];
	}
	for(int i=0;i<rSize;i++){
		rStruct[i]=data[mid+1+i];
	}
	int lCount=0,rCount=0,sCount=left;
	while(lCount<lSize && rCount<rSize){
		if(strcmp(lStruct[lCount].NIM,rStruct[rCount].NIM) < 0){
			data[sCount++]=lStruct[lCount++];
		}
		else{
			data[sCount++]=rStruct[rCount++];	
		}
	}
	while(lCount<lSize){
		data[sCount++]=lStruct[lCount++];
	}
	while(rCount<rSize){
		data[sCount++]=rStruct[rCount++];
	}
}

void mergeSort(struct studentData data[],int left,int right){
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
	int amount;
	fscanf(fp,"%d",&amount);
//	printf("%d\n",amount);
//	printf("==========\n");
	struct studentData data[1010];
//	int amnt=0;
//	while(fscanf(fp,"%s %s\n",data[amnt].NIM,data[amnt].name) != EOF){
//		amnt++;
//	}
//	printf("%d\n",amnt);
	for(int i=0;i<amount;i++){
		fscanf(fp,"%s %s",data[i].NIM,data[i].name);
	}

//	mergeSort(data,0,amount-1);
	for(int i=0;i<amount-1;i++){
		for(int j=0;j<amount-1;j++){
			if(strcmp(data[j].NIM,data[j+1].NIM) > 0){
				struct studentData temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<amount;i++){
		printf("%s %s\n",data[i].NIM,data[i].name);
	}
//	while(fscanf("%"))
	fclose(fp); 
 	return 0;
}

