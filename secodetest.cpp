#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int change;
		char num[101000];
		scanf("%d %s",&change,num);
		for(int j=0;j<change;j++){
			int index,newnum;
			int temp;
			scanf("%d %d",&index,&newnum);
			int dif = newnum-index;
			if(dif<0) dif = -dif;
			for(int k=0;k<dif;k++){
				temp = num[index-1+k];
				num[index-1+k] = num[newnum-1-k];
				num[newnum-1-k] = temp;
				if(k>((dif/2)-1)) break;
			}
		}
		printf("%s\n",num);
	}
 	return 0;
}

