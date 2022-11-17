#include<stdio.h>
#include<string.h>

int main(){
	
	char input[10000];
	
	scanf("%s", input); getchar();
	
	int length = strlen(input);
	
	int count = 0;
	for(int i = 0; i <= 26; i++)
	{
		for(int k = 0; k < 2; k++)
		{
			for(int j = 0; j < length; j++)
			{
				if(input[j] == 65+i && count == 0)
				{
					printf("%c", input[j]);
				}
				if(input[j] == 97+i && count == 1)
				{
					printf("%c", input[j]);
				}
			}
			if(count == 0)
			{
				count = 1;
			}
			else if(count == 1)
			{
				count = 0;
			}
			
		}
	}
	printf("\n");
	
	
	
	
	return 0;
}

