#include <stdio.h>

void swapRef(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int arr[],int left,int right){ // swapping by value
	int temp=arr[right];
	arr[right]=arr[left];
	arr[left]=temp;
}

void bubbleSort(int arr[],int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
				//swapRed(&num[j],&num[j+1]);
			}
		}
	}
}

void printArr(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void selectionSort(int arr[],int size){
	for(int i=0;i<size-1;i++){
		int min=i;
		printf("initial index: %d\n",min);
		for(int j=i+1;j<size;j++){
			if(arr[min]>arr[j]){
				min=j;
				printf("index changed: %d\n",min);
			}
		}
		swapRef(&arr[i],&arr[min]);
		printArr(arr,size);
	}
}

int main()
{
	/*
	
	Sorting types:
	- Simple Sorting --> less code, less time complexity, 
	- Bubble Sort 
	- Selection Sort
	- Insertion Sort
	
	given an array:
	{5,3,19,1,27,13}
	Ascending Order : 1,3,5,13,19,27
	Descending Order: 27,19,13,5,3,1
	
	
	bubble sort example, maybe?
	counter =1;
	do
	swapped = false
	for(int i=0;i<max-counter,i++){
	if left>right --> arr[i]>arr[i+1]
	swap(left,right)
	counter++;
	swapped = true;
	while swapped==true
	
	
	*/
	int arr[]={5,3,19,1,27,13};
	int size = sizeof(arr)/sizeof(arr[0]);
//	for(int i=0;i<size;i++){
//		scanf("%d",&arr[i]);
//	}
	printArr(arr,size);
//	bubbleSort(arr,size);
//	printArr(arr,size);
	selectionSort(arr,size);
	
	
 	return 0;
}

