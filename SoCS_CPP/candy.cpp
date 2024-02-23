#include <stdio.h>

int main(){
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int type,money;
		scanf("%d %d",&type,&money);
		int price[type];
		int smallest = 0,candy=0;
		for(int j=0;j<type;j++){
			scanf("%d", &price[j]);
			if(smallest == 0){
				smallest = price[j];
			}
			else if(price[j]<smallest && smallest != 0){
				smallest = price[j];
			}
		}
		while(money>=smallest){
			candy++;
			money-=smallest;
		}
		printf("Case #%d: %d\n",i,candy);
	}

return 0;
}

