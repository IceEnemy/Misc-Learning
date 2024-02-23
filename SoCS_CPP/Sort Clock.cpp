#include <stdio.h>
#include <string.h>

struct time{
	int hour;
	int minute;
	char category[3];
};

void sort(struct time data[],int l,int m,int r){
	int lS = m-l+1;
	int rS = r-m;
	struct time left[lS], right[rS];
	for(int i=0;i<lS;i++){
		left[i] = data[l+i];
	}
	for(int i=0;i<rS;i++){
		right[i] = data[m+1+i];
	}
	int lC = 0, rC = 0, sC = l;
	while(lC < lS && rC < rS){
		if(left[lC].hour < right[rC].hour){
			data[sC++] = left[lC++];
		}
		else if(left[lC].hour > right[rC].hour){
			data[sC++] = right[rC++];
		}
		else{
			if(left[lC].minute < right[rC].minute){
				data[sC++] = left[lC++];
			}
			else{
				data[sC++] = right[rC++];	
			}
		}
	}
	while(lC < lS){
		data[sC++] = left[lC++];	
	}
	while(rC < rS){
		data[sC++] = right[rC++];
	}
}

void mergeSort(struct time data[],int l,int r){
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
	struct time clock[n];
	for(int i=0;i<n;i++){
		scanf("%d:%d %s",&clock[i].hour,&clock[i].minute,clock[i].category);
		if(strcmp(clock[i].category,"pm") == 0){
			clock[i].hour += 12;
			if(clock[i].hour == 24) clock[i].hour = 0;
		}
	}
	mergeSort(clock,0,n-1);
	for(int i=0;i<n;i++){
		printf("%02d:%02d\n",clock[i].hour,clock[i].minute);
	}
	
 	return 0;
}

