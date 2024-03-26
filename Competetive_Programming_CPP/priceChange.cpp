#include <stdio.h>

int main()
{
	int items,num,newPrice;
	scanf("%d",&items);
	int price[items];
	for(int i=0;i<items;i++){
		scanf("%d",&price[i]);
	}
	int ctlg;
	scanf("%d",&ctlg);
	for(int j=1;j<=ctlg;j++){
		scanf("%d %d",&num,&newPrice);
		price[num-1]=newPrice;
		printf("Case #%d: %d",j,price[j-1]);
	}
	return 0;
}

