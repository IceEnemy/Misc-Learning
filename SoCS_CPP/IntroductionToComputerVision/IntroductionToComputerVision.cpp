#include <stdio.h>
#include <string.h>

void sort(double data[],int l,int m,int r){
	int lS = m-l+1;
	int rS = r-m;
	double left[lS], right[rS];
	for(int i=0;i<lS;i++){
		left[i] = data[l+i];
	}
	for(int i=0;i<rS;i++){
		right[i] = data[m+1+i];
	}
	int lC = 0, rC = 0, sC = l;
	while(lC < lS && rC < rS){
		if(left[lC] < right[rC]){
			data[sC++] = left[lC++];
		}
		else if(left[lC] >= right[rC]){
			data[sC++] = right[rC++];
		}
	}
	while(lC < lS){
		data[sC++] = left[lC++];	
	}
	while(rC < rS){
		data[sC++] = right[rC++];
	}
}

void mergeSort(double data[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergeSort(data,l,m);
		mergeSort(data,m+1,r);
		sort(data,l,m,r);
	}
}

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int test;
	fscanf(fp,"%d\n",&test);
	for(int i=1;i<=test;i++){
		int row,col;
		fscanf(fp,"%d %d\n",&row,&col);
		int n = row*col;
		double num[n];
		for(int j=0;j<n;j++){
			fscanf(fp,"%lf",&num[j]);
		}
		
		mergeSort(num,0,n-1);
		int median;
		if(n%2 == 0){
			median = num[n/2];
		}
		else{
			median = (num[n/2] + num[n/2+1])/2;
		}
		printf("Case #%d: %d\n",i,median);
	}
	
	fclose(fp);
 	return 0;
}

