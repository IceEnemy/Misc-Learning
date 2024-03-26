#include <stdio.h>

void mergeSort(int data[], int left, int mid, int right)
{
	int leftcount = 0, rightcount = 0, count = left;
	int leftsize = mid-left+1;
	int rightsize = right-mid;
	int leftstruct[leftsize], rightstruct[rightsize];
	
	for(int i = 0; i < leftsize; i++)
	{
		leftstruct[i] = data[left+i];
	}
	for(int i = 0; i < rightsize; i++)
	{
		rightstruct[i] = data[mid+1+i];
	}
	
	while(leftcount < leftsize && rightcount < rightsize)
	{
		if(leftstruct[leftcount] > rightstruct[rightcount])
		{
			data[count++] = rightstruct[rightcount++];
		}
		else
		{
			data[count++] = leftstruct[leftcount++];
		}
	}
	
	while(leftcount < leftsize)
	{
		data[count++] = leftstruct[leftcount++];
	}
	while(rightcount < rightsize)
	{
		data[count++] = rightstruct[rightcount++];
	}
	
}

void merge(int data[], int left, int right)
{
	if(left < right)
	{
		int mid = left + (right-left)/2;
		merge(data, left, mid);
		merge(data, mid+1, right);
		mergeSort(data, left, mid, right);
	}
}

int main()
{
	int array[5] = {7,4,5,3,1};
	merge(array, 0, 4);
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
	
	return 0;
}
