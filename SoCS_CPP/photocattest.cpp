#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=0;i<test;i++){
		int size;
		int min=2000;
		scanf("%d",&size);
		int photo[size];
		for(int j=0;j<size;j++){
			scanf("%d",&photo[j]);
		}
		for(int j=0;j<size;j++){
			for(int k=j+1;k<size;k++){
				int dif=photo[j]-photo[k];
				if(dif<0) dif=-dif;
				if(min>dif){
					min=dif;
				}
			}
		}
		printf("%d\n",min);
	}
 	return 0;
}

