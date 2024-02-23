#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=0;i<test;i++){
		int pas,enc;
		scanf("%d %d",&pas,&enc);
		int pass[pas],key[enc];
		for(int j=0;j<pas;j++){
			scanf("%d",&pass[j]);
		}
		for(int j=0;j<enc;j++){
			scanf("%d",&key[j]);
		}
		int var=0;
		int dif=pas-enc;
		for(int j=0;j<=dif;j++){
			int sum=0;
			for(int k=0;k<enc;k++){
				sum+=pass[k+var]^key[k];
			}
			if(j<dif){
				printf("%d ",sum);
			}
			else{
				printf("%d\n",sum);
			}
			var++;
		}
	}
 	return 0;
}

