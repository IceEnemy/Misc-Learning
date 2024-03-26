#include <stdio.h>

int main(){
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int num;
		scanf("%d",&num);
		int sum = 0;
		for(int j=2;j<=num;j++){
			if(num%j==0){
				sum+=j;
				for(int k=2;k<=j/2;k++){
					if(j%k==0){
						sum-=j;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n",i,sum);
	}

return 0;
}

