#include <stdio.h>
#include <string.h>

void sort(int data[],int l,int m,int r){
	int lS = m-l+1;
	int rS = r-m;
	int left[lS], right[rS];
	for(int i=0;i<lS;i++){
		left[i]=data[l+i];
	}
	for(int i=0;i<rS;i++){
		right[i]=data[m+1+i];
	}
	int lC=0,rC=0,sC=l;
	while(lC < lS && rC < rS){
		if(left[lC]<right[rC]){
			data[sC++]=left[lC++];
		}
		else if(left[lC]>=right[rC]){
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

void mergeSort(int data[],int l,int r){
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
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int n;
		scanf("%d",&n);
		int num[n];
		for(int j=0;j<n;j++){
			scanf("%d",&num[j]);
		}
		mergeSort(num,0,n-1);
		int max=0;
		int number=num[0];
		int smallest;
		int count=0;
		for(int j=0;j<n;j++){
			if(num[j]==number){
//				printf("%d\n",num[j]);
				count++;
//				printf("%d\n",count);
			}
			else if(num[j]!=number){
//				printf("%d changed to %d\n",smallest,number);
				if(count>max){
					smallest=number;
					max=count;
//					printf("%d\n",max);
				}
				number=num[j];
				count=1;
			}
			if(j==n-1){
				if(count>max){
//					printf("%d changed to %d\n",smallest,number);
					smallest=number;
					max=count;
				}	
			}
		}
		printf("Case #%d: %d\n%d\n",i,max,smallest);
	}
 	return 0;
}

