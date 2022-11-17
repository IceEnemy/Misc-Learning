#include<stdio.h>

int main(){
	
	int testcase;
	scanf("%d", &testcase);
	
	for(int t = 0 ; t < testcase; t++)
	{
		int page, n;
		scanf("%d %d", &page, &n);
		
		int result = 0;
		int temp = 0;
		if(page % 2 == 0)
		{
			if(n > page/2)
			{
				if(n == page)
				{
					result = 0;
				}
				else
				{
					temp = (page-n) / 2;
					if(n % 2 == 0)
					{
						result = temp;
					}
					else
					{
						result = temp + 1;
					}
				}
			}
			else if(n <= page/2)
			{
				if(n == 1)
				{
					result = 0;
				}
				else
				{
					result = n/2;
				}
			}
		}
		
		if(page % 2 == 1)
		{
			if(n > page/2)
			{
				if(n >= page-1)
				{
					result = 0;
				}
				else
				{
					result = (page-n) / 2;
				}
			}
			else if(n <= page/2)
			{
				if(n == 1)
				{
					result = 0;
				}
				else
				{
					result = n/2;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, result);
	}
	
	return 0;
}

