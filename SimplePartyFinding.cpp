#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int size;
		scanf("%d",&size);
		int num[size];
		for(int j=0;j<size;j++){
			scanf("%d",&num[j]);
		}
		int mmr;
		scanf("%d",&mmr);
		int lower=2999,higher=10000;
		bool check=false;
		for(int j=0;j<size;j++){
			if(num[j]==mmr){
				check=true;
			}
			else if(num[j]>lower && num[j]<mmr){
				lower=num[j];
			}
			else if(num[j]<higher && num[j]>mmr){
				higher=num[j];
			}
		}
		if(check==false){
			printf("CASE #%d: -1 -1\n",i);
		}
		else if(higher==10000){
			printf("CASE #%d: %d %d\n",i,lower,mmr);
		}
		else{
			printf("CASE #%d: %d %d\n",i,mmr,higher);
		}
	}
 	return 0;
}


