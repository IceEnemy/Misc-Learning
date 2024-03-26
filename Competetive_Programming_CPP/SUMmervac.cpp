#include <stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int size,cool=0;
		scanf("%d",&size);
		int num[size];
		for(int j=0;j<size;j++){
			scanf("%d",&num[j]);
		}
		for(int k=0;k<size;k++){
			int check=0;
			for(int l=0;l<size;l++){
				for(int m=l+1;m<size;m++){
					if(num[k]==num[l]+num[m]){
						check=1;
						break;
					}
				}
				if(check==1){
					break;
				}
			}
			if(check==1){
				cool++;
			}
		}
		printf("Case #%d: %d\n",i,cool);	
	}
 	return 0;
}

