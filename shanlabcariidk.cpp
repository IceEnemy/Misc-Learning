#include <stdio.h>
#include <string.h>

struct words{
	char text[110];
};

void sort(struct words data[],int l,int m,int r){
	int lS=m-l+1;
	int rS=r-m;
	struct words left[lS], right[rS];
	for(int i=0;i<lS;i++){
		left[i]=data[l+i];
	}
	for(int i=0;i<rS;i++){
		right[i]=data[m+1+i];
	}
	int lC=0,rC=0,sC=l;
	
	while(lC < lS && rC < rS){
		if(strcmp(left[lC].text,right[rC].text)<0){
			data[sC++]=left[lC++];
		}
		else{
			data[sC++]=right[rC++];	
		}
	}
	while(lC < lS){
		data[sC++]=left[lC++];
	}
	while(rC < rS){
		data[sC++]=right[rC++];
	}
}

void mergeSort(struct words data[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergeSort(data,l,m);
		mergeSort(data,m+1,r);
		sort(data,l,m,r);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	struct words data[n];
	for(int i=0;i<n;i++){
		scanf("%s",data[i].text);
	}
	mergeSort(data,0,n-1);
	int page;
	char keyword[110];
	scanf("%d",&page);
	scanf("%s",keyword);
	int find=-1;
	
	for(int i=0;i<n;i++){
		if(strcmp(data[i].text,keyword)==0){
			find = i/page+1;
			break;
		}
	}
	if(find == -1){
		printf("masa ga ketemu parah sih\n");
	}
	else{
		printf("dia di halaman %d ok?\n",find);
	}
 	return 0;
}

