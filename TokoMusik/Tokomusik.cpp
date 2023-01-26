#include <stdio.h>
#include <string.h>

//struct product{
//	int amount;
//	char name[110];
//	int price;
//};

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int test;
	fscanf(fp,"%d\n",&test);
	for(int i=1;i<=test;i++){
		int n;
		double total=0;
		fscanf(fp,"%d\n",&n);
//		struct product data[n];
		int amount;
		char name[110];
		int price;
		for(int j=0;j<n;j++){
			fscanf(fp,"%d#%[^@]@%d\n",&amount,name,&price);
			total+=(amount*price);
		}
		total-=(total*15/100);
		printf("Customer #%d: Rp %.0lf\n",i,total);
	}
 	return 0;
}

