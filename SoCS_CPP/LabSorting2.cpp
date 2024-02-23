#include <stdio.h>

int n;

void print(int arr[]){
	for(int i=0;i<n;i++){
		if(i==n-1) printf("%d\n",arr[i]);
		else printf("%d ",arr[i]);
	}
}

void merge(int arr[],int left,int middle,int right){
	/*
	{31, 48, 30, 5, 24, 43, 22, 22, 45, 34, 3}
	 0   1   2   3  4   5   6   7   8   9  10
	 L                  M                  R
	 
	 leftN = M-L+1
	 = 5-0+1 =6;
	 
	 rightN = R-M
	 = 10-5 =5;
	*/
	int leftN = middle - left + 1; //2a kiri
	int rightN = right - middle; //2a kanan
	int leftArr[leftN], rightArr[rightN]; //2b
	
	/*
		{5, 24, 30, 31, 43, 48, 3, 22, 22, 34, 45}
		 0   1   2   3  4   5   6   7   8   9  10
	*/
	
	for(int i=0;i<leftN;i++){ //2c array kiri
		leftArr[i]=arr[left+i];
	}
	for(int i=0;i<rightN;i++){ //2c array kanan
		rightArr[i]=arr[middle+1+i];
	}
	
	int leftCounter=0, rightCounter=0, arrCounter=left; //arrCounter == left krn kita timpah arraynya gak dari index 0, tpi dari yang paling awal (2d)
	/*
		kalo yang diambil yang right, then rightcounter++ kalo left, leftcounter++
	*/
	while(leftCounter < leftN && rightCounter < rightN){ //2e
		if(leftArr[leftCounter] < rightArr[rightCounter]){
			arr[arrCounter++] = leftArr[leftCounter++];
		}
		else{
			arr[arrCounter++] = rightArr[rightCounter++];
		}
	}
	while(leftCounter < leftN){ //2f left
		arr[arrCounter++] = leftArr[leftCounter++];
	}
	
	while(rightCounter < rightN){ //2f right
		arr[arrCounter++] = rightArr[rightCounter++];
	}
}

void mergeSort(int arr[],int left,int right){
	//left and right are indexes
	if(left < right){
		/*
			Rumus middle
			------------
			{31, 48, 30, 5, 24, 43, 22, 22, 45, 34, 3}
			 0   1   2   3  4   5   6   7   8   9  10
			 L                  M                  R
			 i. L+(R-L)/2 -->pake ini untuk prevent melebihi int limit
			 ii. (L+R) /2
			 
			 i
			 0+(10-0)/2 = 5
			 ii
			 (0+10)/2 = 5
			 
			 {31, 48, 30, 5, 24, 43} {22, 22, 45, 34, 3}
			   0   1   2   3  4   5   6   7   8   9  10
			   L                  R   L       M      R
			   
			   i
			   kanan
			   6+(10-6)/2 = 8
			   
			   ii
			   kanan
			   (10+6)/2 = 8
		*/
		int middle = left+(right-left)/2; //---> 1a
		mergeSort(arr,left,middle); //kiri
		mergeSort(arr,middle+1,right); //kanan
		merge(arr,left,middle,right); //--> 1b
	}
}
//{31,48,30,5,24,43,22,22,45,34,3}

/*
	Task - MergeSort
	----------------
	1. split array to the smallest unit (till only 1 left)
	mergeSort(array,left,right) --> recursion
	a. Find the middle
	b. Merge the left side and the right (merge array)
	2. combine the arrays (sorting logic)
	merge(array,left,middle,right)
	a. fing the number of elements in the right and left arrays
	b. Declare a temporary array for the left and right
	c. Copy the data from the source to the temporary array
	d. Make a counter for 3 things:
		i. Left array
		ii. Right array
		iii. The source array
	e. Compare the left and right arrays to insert to the original array
	f. if there are leftover elements, we copy the leftovers to the original array
	----------------
	Done
*/



int main()
{
	int arr[]={31,48,30,5,24,43,22,22,45,34,3};
	printf("Original Array: ");
	n = sizeof(arr)/sizeof(arr[0]);
	print(arr);
	mergeSort(arr,0,n-1);
	printf("Sorted Array  : ");
	print(arr);
	
 	return 0;
}

