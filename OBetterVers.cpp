#include<stdio.h>
int main (){
	int n;
	scanf("%d",&n);
	int arr[n+1][n+1];
	int wrong = 0;
	for (int i=1;i<=n;i++)
	{	
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		int count =0;
		int count2= 0;
		for(int j=1;j<=n;j++)
		{
			if (arr[i][j] == i  ) // x
			{
				count++;
				if (count >1)
				{
					wrong = 1;
					break;
				}
			}
			if (arr[j][i] == i) // y
			{
				count2++;
				if (count2>1)
				{
					wrong =1;
					break;
				}
			}	
		}
	}
	if (wrong == 0)
	{	
		puts("Yay");
	}
	else puts("Nay");
return 0;
}
