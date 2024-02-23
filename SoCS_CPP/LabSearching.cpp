#include <stdio.h>

void printArr(int arr[],int l,int r){
	for(int i=l;i<=r;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void bubbleSort(int arr[],int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
// iterative function for binarySearch
int binarySearch(int arr[],int target,int l,int r){
	while(l<=r){
		printArr(arr,l,r);
		int m=l+(r-l)/2;
		printf("mid %d: %d\n",m,arr[m]);
		if(arr[m]==target){
			return m;
		}
		else if(arr[m]>target){
			r=m-1;
		}
		else if(arr[m]<target){
			l=m+1;
		}
	}
	return -1;
}

int recBinarySearch(int arr[],int target,int l,int r){
	if(l>r) return -1;
	printArr(arr,l,r);
	int m=l+(r-l)/2;
	printf("mid %d: %d\n",m,arr[m]);
	if(arr[m]==target){
		return m;
	}
	else if(arr[m]>target){
		return recBinarySearch(arr,target,l,m-1);
	}
	else if(arr[m]<target){
		return recBinarySearch(arr,target,m+1,r);
	}
}

int interpolationSearch(int arr[],int target,int l,int r){
	if(arr[l] == target){
		return l;
	} 
	else if(arr[r] == target){
		return r;
	} //--> incase there are repeat elements
	while(l<=r && target<=arr[r] && target>=arr[l]){
		printArr(arr,l,r);
		int m=l+((target-arr[l])*(r-l))/(arr[r]-arr[l]);
		printf("mid %d: %d\n",m,arr[m]);
		if(arr[m]==target){
			return m;
		}
		else if(arr[m]>target){
			r=m-1;
		}
		else if(arr[m]<target){
			l=m+1;
		}
	}
	return -1;
}

int main()
{
	int arr[]={10,3,19,45,16,11,9};
	int size=sizeof(arr)/sizeof(arr[0]);
	int target = 16;
//	int idx=-1;
	/*
	Linear Search (Unsorted) --> loop thru the arr and check
	whether the target is equal to the value of the index
	*/
//	for(int i=0;i<size;i++){
//		printf("%d == index %d, is it %d?\n",arr[i],i,target);
//		if(arr[i]==target){
//			idx=i;
//			break;
//		}
//	}
//	if(idx==-1){
//		printf("not found xddd\n");
//	}
//	else{
//		printf("The Element in on index %d",idx);
//	}
	
	// sorted linear search
	bubbleSort(arr,size);
//	int z;
//	for(z=0;z<size;z++){
//		printf("%d == index %d, is it %d?\n",arr[z],z,target);
//		if(arr[z]==target){
//			printf("Value at index %d\n",z);
//			break;
//		}
//	}
//	if(z==size){
//		printf("lol xdd\n");
//	}
	
	// looks easy but the time needed to search (time complexity) is too big
	// time complexity of unsorted linear search --> n
	// time complexity for sorted linear search --> ?
	
	/*
	Binary search and the other one needs to be sorted first
	the time complexity -> ^2log(n) 
	*/
	//iterative method
	
	int idx=binarySearch(arr,target,0,size-1);
	if(idx==-1){
		printf("not found xddd\n");
		printf("================\n");
	}
	else{
		printf("The Element in on index %d\n",idx);
		printf("============================\n");
	}
	int recidx=recBinarySearch(arr,target,0,size-1);
	if(recidx==-1){
		printf("recursion not found xddd\n");
		printf("========================\n");
	}
	else{
		printf("The Element in on index %d(recursion)\n",recidx);
		printf("=====================================\n");
	}
	
	int interidx=interpolationSearch(arr,target,0,size-1);
	if(interidx==-1){
		printf("interpolation not found xddd\n");
		printf("============================\n");
	}
	else{
		printf("The Element in on index %d(interpolation)\n",interidx);
		printf("=========================================\n");
	}
	
	/*
	interpolation search
	pretty much the advanced binary search
	formula:
		mid=left+(target-arr[left]) * ((right-left)/(arr[right]-arr[left]))
	the time complexity -> ^2log(^2log(n)) 
	*/
	
	
	
 	return 0;
}

