#include <stdio.h>
#include <string.h>

struct grade{
	char name[15];
	int score;
};

void sort(grade data[],int l,int m,int r){
	int lS=m-l+1;
	int rS=r-m;
	grade left[lS],right[rS];
	for(int i=0;i<lS;i++){
		left[i]=data[l+i];
	}
	for(int i=0;i<rS;i++){
		right[i]=data[m+1+i];
	}
	int lC=0,rC=0,sC=l;
	while(lC < lS && rC < rS){
		if(left[lC].score>right[rC].score) data[sC++]=left[lC++];
		else if(left[lC].score<right[rC].score) data[sC++]=right[rC++];
		else{
			if(strcmp(left[lC].name,right[rC].name)<0) data[sC++]=left[lC++];
			else data[sC++]=right[rC++];
		}
	}
	while(lC < lS){
		data[sC++]=left[lC++];
	}
	while(rC < rS){
		data[sC++]=right[rC++];
	}
}

void mergeSort(grade data[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergeSort(data,l,m);
		mergeSort(data,m+1,r);
		sort(data,l,m,r);
	}
}

int main()
{
	int test;
	scanf("%d",&test); getchar();
	for(int i=1;i<=test;i++){
		int n;
		scanf("%d",&n);
		getchar();
		grade data[n];
		for(int j=0;j<n;j++){
			scanf("%[^#]#%d",data[j].name,&data[j].score);
			getchar();
		}
		mergeSort(data,0,n-1);
		char target[15];
		scanf("%[^\n]",target);
		getchar();
		for(int j=0;j<n;j++){
			if(strcmp(data[j].name,target)==0){
				printf("Case #%d: %d\n",i,j+1);
				break;
			}
		}
	}
 	return 0;
}

