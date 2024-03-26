#include <stdio.h>
#include <string.h>

struct temperature{
	char city[1010];
	double tempy;
	char deg;
};

void FtoC(double *temp,char degree){
	if(degree=='F'){
		(*temp)-=32;
		(*temp)*=5;
		(*temp)/=9;
	}
}

void sort(struct temperature temp[],int left,int mid,int right){
	int lSize=mid-left+1;
	int rSize=right-mid;
	struct temperature lStruct[lSize],rStruct[rSize];
	for(int i=0;i<lSize;i++){
		lStruct[i]=temp[left+i];
	}
	for(int i=0;i<rSize;i++){
		rStruct[i]=temp[mid+i+1];
	}
	int lCount=0,rCount=0,sCount=left;
	double lC,rC;
	while(lCount<lSize && rCount<rSize){
		lC=lStruct[lCount].tempy;
		FtoC(&lC,lStruct[lCount].deg);
		rC=rStruct[rCount].tempy;
		FtoC(&rC,rStruct[rCount].deg);
		if(lC<rC) {
			temp[sCount++]=lStruct[lCount++];
		}
		else if(lC>rC){
			temp[sCount++]=rStruct[rCount++];
		} 
		else{
			if(strcmp(lStruct[lCount].city,rStruct[rCount].city) < 0){
				temp[sCount++]=lStruct[lCount++];
			} 
			else{
				temp[sCount++]=rStruct[rCount++];
			} 
		}
	}
	while(lCount<lSize){
		temp[sCount++]=lStruct[lCount++];
	}
	while(rCount<rSize){
		temp[sCount++]=rStruct[rCount++];
	}
}

void mergeSort(struct temperature temp[],int left, int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(temp,left,mid);
		mergeSort(temp,mid+1,right);
		sort(temp,left,mid,right);
	}
}

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int n=0;
	struct temperature temp[110];
	while(fscanf(fp,"%[^#]#%lf#%c\n",temp[n].city,&temp[n].tempy,&temp[n].deg) != EOF){
		n++;
//		FtoC(&temp[n].tempy,temp[n].deg);
	}
//	printf("%d\n",n);
//	for (int i=0;i<n;i++){
//		printf("%s is %.2lf%c\n",temp[i].city,temp[i].tempy,temp[i].deg);
//	}
//	printf("=====================\n");
	mergeSort(temp,0,n-1);
	for (int i=0;i<n;i++){
		printf("%s is %.2lf%c\n",temp[i].city,temp[i].tempy,temp[i].deg);
	}
	
	fclose(fp);
 	return 0;
}

