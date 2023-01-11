#include <stdio.h>
#include <string.h>

//struct temp{
//	char str[50];
//};

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
	int total;
};

void unique(struct table data[],int size,int mode){
	struct amount much[size];
	int count=1;
	if(mode==1){
		strcpy(much[0].str,data[0].loc1);
		much[0].total=1;
		for(int i=1;i<size;i++){
			for(int j=0;j<count;j++){
				if(strcmp(much[j].str,data[i].loc1)==0){
					much[j].total++;
					break;
				}
				else if(j==count-1){
					strcpy(much[count].str,data[i].loc1);
					much[count].total=1;
					count++;
					break;
				}
			}
		}
	}
	else if(mode==2){
		strcpy(much[0].str,data[0].loc2);
		much[0].total=1;
		for(int i=1;i<size;i++){
			for(int j=0;j<count;j++){
				if(strcmp(much[j].str,data[i].loc2)==0){
					much[j].total++;
					break;
				}
				else if(j==count-1){
					strcpy(much[count].str,data[i].loc2);
					much[count].total=1;
					count++;
					break;
				}
			}
		}
	}
	else if(mode==4){
		strcpy(much[0].str,data[0].room);
		much[0].total=1;
		for(int i=1;i<size;i++){
			for(int j=0;j<count;j++){
				if(strcmp(much[j].str,data[i].room)==0){
					much[j].total++;
					break;
				}
				else if(j==count-1){
					strcpy(much[count].str,data[i].room);
					much[count].total=1;
					count++;
					break;
				}
			}
		}
	}
	else if(mode==5){
		strcpy(much[0].str,data[0].bathrooms);
		much[0].total=1;
		for(int i=1;i<size;i++){
			for(int j=0;j<count;j++){
				if(strcmp(much[j].str,data[i].bathrooms)==0){
					much[j].total++;
					break;
				}
				else if(j==count-1){
					strcpy(much[count].str,data[i].bathrooms);
					much[count].total=1;
					count++;
					break;
				}
			}
		}
	}	
	else if(mode==6){
		strcpy(much[0].str,data[0].carparks);
		much[0].total=1;
		for(int i=1;i<size;i++){
			for(int j=0;j<count;j++){
				if(strcmp(much[j].str,data[i].carparks)==0){
					much[j].total++;
					break;
				}
				else if(j==count-1){
					strcpy(much[count].str,data[i].carparks);
					much[count].total=1;
					count++;
					break;
				}
			}
		}
	}
	else if(mode==7){
		strcpy(much[0].str,data[0].type);
		much[0].total=1;
		for(int i=1;i<size;i++){
			for(int j=0;j<count;j++){
				if(strcmp(much[j].str,data[i].type)==0){
					much[j].total++;
					break;
				}
				else if(j==count-1){
					strcpy(much[count].str,data[i].type);
					much[count].total=1;
					count++;
					break;
				}
			}
		}
	}
	else if(mode==9){
		strcpy(much[0].str,data[0].furnish);
		much[0].total=1;
		for(int i=1;i<size;i++){
			for(int j=0;j<count;j++){
				if(strcmp(much[j].str,data[i].furnish)==0){
					much[j].total++;
					break;
				}
				else if(j==count-1){
					strcpy(much[count].str,data[i].furnish);
					much[count].total=1;
					count++;
					break;
				}
			}
		}
	}
	int min=-1;
	int max=-1;
	int minidx,maxidx;
	for(int i=0;i<count;i++){
		if(max==-1 && min==-1){
			max=much[i].total;
			min=much[i].total;
			minidx=i;
			maxidx=i;
		}
		else if(much[i].total<=min){
			min=much[i].total;
			minidx=i;
		}
		else if(much[i].total>=max){
			max=much[i].total;
			maxidx=i;
		}
	}
	for(int i=0;i<count;i++){
		printf("%s : %d\n",much[i].str,much[i].total);
	}
	printf("Maximum value: %s with a frequency of : %d\n",much[maxidx].str,max);
	printf("Minimum value: %s with a frequency of : %d\n",much[minidx].str,min);	
}

void number(struct table data[],int size,int mode){
	double avrg=0;
	int min=-1;
	int max=-1;
	if(mode==3){
		for(int i=0;i<size;i++){
			if(min==-1 && max==-1){
				min=data[i].price;
				max=data[i].price;
			}
			else if(data[i].price<min){
				min=data[i].price;
			}
			else if(data[i].price>max){
				max=data[i].price;
			}
			avrg+=data[i].price;
		}
	}
	else if(mode==8){
		for(int i=0;i<size;i++){
			if(min==-1 && max==-1){
				min=data[i].area;
				max=data[i].area;
			}
			else if(data[i].area<min){
				min=data[i].area;
			}
			else if(data[i].area>max){
				max=data[i].area;
			}
			avrg+=data[i].area;
		}
	}
	avrg/=3939;
	printf("Maximum value: %d\n",max);
	printf("Minimum value: %d\n",min);
	printf("Average value: %.2lf\n",avrg);
}

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
				unique(data,n,1);
				break;
			case 2:
				unique(data,n,2);
				break;
			case 3:
				number(data,n,3);
				break;
			case 4:
				unique(data,n,4);
				break;
			case 5:
				unique(data,n,5);
				break;
			case 6:
				unique(data,n,6);
				break;
			case 7:
				unique(data,n,7);
				break;
			case 8:
				number(data,n,8);
				break;
			case 9:
				unique(data,n,9);
				break;
		}
	}while(menu<1 || menu>9);
	
	
	fclose(fp);
 	return 0;
}

