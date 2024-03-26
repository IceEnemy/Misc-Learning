#include <stdio.h>
#include <string.h>

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

void search(struct table data[],char key[50],int mode,int size){
	bool found=false;
	if(mode==1){
		for(int i=0;i<size;i++){
			if(strstr(data[i].loc1,key)!='\0'){
				printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
				if(found==false){
					found=true;
				}
			}
		}
	}
	else if(mode==2){
		for(int i=0;i<size;i++){
			if(strstr(data[i].loc2,key)!='\0'){
				printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
				if(found==false){
					found=true;
				}
			}
		}
	}
	else if(mode==3){
		for(int i=0;i<size;i++){
			if(strstr(data[i].room,key)!='\0'){
				printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
				if(found==false){
					found=true;
				}
			}
		}
	}
	else if(mode==4){
		for(int i=0;i<size;i++){
			if(strstr(data[i].bathrooms,key)!='\0'){
				printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
				if(found==false){
					found=true;
				}
			}
		}
	}
	else if(mode==5){
		for(int i=0;i<size;i++){
			if(strstr(data[i].carparks,key)!='\0'){
				printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
				if(found==false){
					found=true;
				}
			}
		}
	}
	else if(mode==6){
		for(int i=0;i<size;i++){
			if(strstr(data[i].type,key)!='\0'){
				printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
				if(found==false){
					found=true;
				}
			}
		}
	}
	else if(mode==7){
		for(int i=0;i<size;i++){
			if(strstr(data[i].furnish,key)!='\0'){
				printf("| %-25s | %s | %-8d | %s | %s | %s | %-9s | %-6d | %-11s |\n",data[i].loc1,data[i].loc2,data[i].price,data[i].room,data[i].bathrooms,data[i].carparks,data[i].type,data[i].area,data[i].furnish);
				if(found==false){
					found=true;
				}
			}
		}
	}
	if(found==false){
		printf("Data doesn't exist\n");
	}
}

int main()
{
	FILE *fp=fopen("file.csv","r");
	char header[110];
	fscanf(fp,"%[^\n]\n",header);
	struct table data[3950];
	int n=0;
	while(!feof(fp)){
		fscanf(fp,"%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%d,%[^\n]\n",data[n].loc1,data[n].loc2,&data[n].price,data[n].room,data[n].bathrooms,data[n].carparks,data[n].type,&data[n].area,data[n].furnish);
		n++;
	}
	printf("| loc1 | loc2 | room | bathrooms | carparks | type | furnish |\n\n");
	char key[50];
	char column[50];
	bool col=false;
	while(col==false){
		col=true;
		printf("What keyword and column would you like to search? (keyword in column)\n");
		scanf("%s in %s",key,column);
		if(strcmp(column,"loc1")==0){
			search(data,key,1,n);
		}
		else if(strcmp(column,"loc2")==0){
			search(data,key,2,n);
		}
		else if(strcmp(column,"room")==0){
			search(data,key,3,n);
		}
		else if(strcmp(column,"bathrooms")==0){
			search(data,key,4,n);
		}
		else if(strcmp(column,"carparks")==0){
			search(data,key,5,n);
		}
		else if(strcmp(column,"type")==0){
			search(data,key,6,n);
		}
		else if(strcmp(column,"furnish")==0){
			search(data,key,7,n);
		}
		else{
			printf("\n===============================\n");
			printf("Column does't exist! Try again!\n");
			printf("===============================\n\n");
			col=false;
		}
	}
	
	fclose(fp);
 	return 0;
}

