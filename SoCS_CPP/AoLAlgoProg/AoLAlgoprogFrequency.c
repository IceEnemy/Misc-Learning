#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct temp{
	char str[50];
};

struct table{
	char loc1[50];
	char loc2[50];
	int price;
	char room[5];
	char bathrooms[5];
	char carparks[5];
	char type[50];
	int area;
	char furnish[50];
};

struct amount{
	char str[50];
	int amount;
};

int main()
{
	FILE *fp=fopen("file.csv","r");
	char header[110];
	fscanf(fp,"%[^\n]\n",header);
	struct table data[3950];
	int n=0;
//	fscanf(fp,"%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%d,%[^\n]\n",data[n].loc1,data[n].loc2,&data[n].price,data[n].room,data[n].bathrooms,data[n].carparks,data[n].type,&data[n].area,data[n].furnish);
//	printf("%s,%s,%d,%s,%s,%s,%s,%d,%s\n",data[n].loc1,data[n].loc2,data[n].price,data[n].room,data[n].bathrooms,data[n].carparks,data[n].type,data[n].area,data[n].furnish);
	while(!feof(fp)){
		fscanf(fp,"%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%d,%[^\n]\n",data[n].loc1,data[n].loc2,&data[n].price,data[n].room,data[n].bathrooms,data[n].carparks,data[n].type,&data[n].area,data[n].furnish);
//		printf("%s,%s,%d,%s,%s,%s,%s,%d,%s\n",data[n].loc1,data[n].loc2,data[n].price,data[n].room,data[n].bathrooms,data[n].carparks,data[n].type,data[n].area,data[n].furnish);
		n++;
	}
	
	int menu;
	do{
		printf("Which collumn do you want to see?\n");
		printf("1. loc1\n");
		printf("2. loc2\n");
		printf("3. price\n");
		printf("4. room\n");
		printf("5. bathrooms\n");
		printf("6. carparks\n");
		printf("7. type\n");
		printf("8. area\n");
		printf("9. furnish\n");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				struct temp tempy[n];
				for(int i=0;i<n;i++){
					strcpy(tempy[i].str,data[i].loc1);
					printf("%s",tempy[i].str);
				}
		}
	}while(menu<1 || menu>9);
	
	
	fclose(fp);
 	return 0;
}

