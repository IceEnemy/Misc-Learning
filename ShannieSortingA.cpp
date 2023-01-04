#include <stdio.h>

void mergeSort(int data[], int left, int mid, int right)
{
	int leftcount = 0, rightcount = 0, count = left;
	int leftsize = mid - left + 1;
	int rightsize = right - mid;
	int leftstruct[leftsize], rightstruct[rightsize];
	
	for(int i = 0; i < leftsize; i++)
	{
		leftstruct[i] = data[left+i];
	}
	for(int i = 0 ; i < rightsize; i++)
	{
		rightstruct[i] = data[mid+i+1];
	}
	
	while(leftcount < leftsize && rightcount < rightsize)
	{
		if(leftstruct[leftcount] < rightstruct[rightcount])
		{
			data[count++] = leftstruct[leftcount++];
		}
		else if(leftstruct[leftcount] > rightstruct[rightcount])
		{
			data[count++] = rightstruct[rightcount++];
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



int main ()
{
	int size;
	scanf("%d", &size);
	int num[size];
	int selisih[size-1];
	
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &num[i]);
	}
	
	merge(num, 0, size-1);
	
	int min = num[0] - num[1];
	int reset = 0;
	int beda;
	
	if(min < 0)
	{
		min = -min;
	}
	
	for(int i = 1; i < size-1; i++)
	{
		
		beda = num[i]- num[i+1];
		
		if(beda < 0)
		{
			beda = -beda;
		}
		
		if (beda > min)
		{
			min = beda;
			reset = 0;
		}
		else if (beda == min)
		{
			reset++;
		}
	}
	
	
	for(int i = 0; i < size-1; i++)
	{	
		beda = num[i] - num [i+1];
		if(beda < 0)
		{
			beda = -beda;
		}
		
		if(beda == min)
		{
			if(reset == 0)
			{
				printf("%d %d\n", num[i], num[i+1]);
			}
			else
			{
				printf("%d %d ", num[i], num[i+1]);
				reset--;
			}
		}
	}	
	
	return 0;
}

