#include<stdio.h>

int main(){
	
	int testcase;
	scanf("%d", &testcase);
	for(int t = 0; t< testcase; t++)
	{
		int n;
		scanf("%d", &n);
		int x[n];
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
		}
		
		int check = 0;
		int z = 1;
		do{
			int left = 0;
			int right = 0;
			
			for(int i = 0; i < z; i++)
			{
				left += x[i];
			}
			for(int i = n-1; i >= z; i--)
			{
				right += x[i];
			}
			
			if(left == right)
			{
				check = 1;
				break;
			}
			
			z++;
		}while(z <= 4);
		
		
		if(check == 1)
		{
			printf("Case #%d: Yes\n", t+1);
		}
		else
		{
			printf("Case #%d: No\n", t+1);
		}
		
	}

	return 0;
}

