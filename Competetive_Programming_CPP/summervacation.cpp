#include<stdio.h>

int main(){
	
	int testcase;
	scanf("%d", &testcase);
	
	for(int t = 0; t < testcase; t++)
	{
		int n;
		scanf("%d", &n);
		
		int x[n+10];
		
		int temp[n];
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
			temp[i] = -1;
		}
		
		
		
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					if(x[j] + x[k] == x[i] && j != k && j != i && k != i)
					{
						for(int p = 0; p <= n; p++)
						{
							if(x[j] + x[k] == temp[p])
							{
								break;
							}
							else if(temp[p] == -1)
							{
								temp[p] = x[j] + x[k];
								count++;
								break;
							}
						}
					}
				}
			}
		}
		
		printf("Case #%d: %d\n", t+1, count);
		
		
	}
	

	return 0;
}

