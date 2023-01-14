#include <stdio.h>
#include <string.h>

struct table{
	char loc1[50];
	char loc2[50];
	int price;
	char room[5];
	char bathrooms[5];
	char carparks[5];
	char type[50];
	int area;
	char furnish[50];
};

//void sort(struct table data[],int l,int m,int r){
//	int lS=l-m+1;
//	int rS=r-m;
//	struct table left[lS], right[rS];
//	for(int i=0;i<lS;i++){
//		left[i]=data[l+i];
//	}
//	for(int i=0;i<rS;i++){
//		right[i]=data[m+1+i];
//	}
//	int lC=0,rC=0,sC=l;
//	while(lC<lS && rC<rS){
//		if(strcmp(left[lC].loc1,right[rC].loc1)<0){
//			data[sC++]=left[lC++];
//		}
//		else{
//			data[sC++]=right[rC++];
//		}
//	}
//	while(lC<lS){
//		data[sC++]=left[lC++];	
//	}
//	while(rC<rS){
//		data[sC++]=right[rC++];
//	}
//}
//
//void mergeSort(struct table data[],int l,int r){
//	if(l<r){
//		int m=l+(r-l)/2;
//		mergeSort(data,l,m);
//		mergeSort(data,m+1,r);
//		sort(data,l,m,r);
//	}
//}

int main()
{
	FILE *fp=fopen("file.csv","r");
	char header[110];
	fscanf(fp,"%[^\n]\n",header);
	struct table data[3950];
	int n=0;
	while(!feof(fp)){
		fscanf(fp,"%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%d,%[^\n]\n",data[n].loc1,data[n].loc2,&data[n].price,data[n].room,data[n].bathrooms,data[n].carparks,data[n].type,&data[n].area,data[n].furnish);
		n++;
	}
//	mergeSort(data,0,n-1); --> doesn't work in Dev C++
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(strcmp(data[j].loc1,data[j+1].loc1)>0){
				struct table temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
	}
 	return 0;
}

