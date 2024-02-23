#include <stdio.h>

int main()
{
	int size;
	scanf("%d",&size);
	int pres[size];
	int max = 0;
	int jumlah = 0;
	for(int i=0;i<size;i++){
		scanf("%d",&pres[i]);
		if(pres[i]>max){
			max = pres[i];
			jumlah = 1;
		}
		else if(max==pres[i]){
			jumlah++;
		}
	}
	printf("%d",jumlah);
 	return 0;
}

