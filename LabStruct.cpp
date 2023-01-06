#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Movie{
	char name[100];
	int rating;
	char year[10];
};

union User{
	char firstName[50];
	char lastName[50];
	int age;
};

/*
	Static memory allocation is less efficient than dynamic
 	
*/

int main()
{
	Movie movie[10];
	//Movie is now a data type
//	movie[0].rating = 9;
//	strcpy(movie[0].name,"Black Panther");
//	strcpy(movie[0].year,"2022");
//	
//	movie[1].rating = 20;
//	strcpy(movie[1].name,"hem");
//	strcpy(movie[1].year,"2022");
	
//	for(int i=0;i<2;i++){
//		scanf("%d",&movie[i].rating); getchar();
//		scanf("%[^\n]",movie[i].name); getchar();
//		scanf("%[^\n]",movie[i].year); getchar();
//	}
//	for(int i=0;i<2;i++){
//		printf("%d\n",movie[i].rating);
//		printf("%s\n",movie[i].name);
//		printf("%s\n",movie[i].year);	
//		puts("");
//	}
	
	
	User user;
	user.age=10;
	
//	printf("FN: %s\n",user.firstName);
//	printf("LN: %s\n",user.lastName);
//	printf("Age: %d\n",user.age);
//	
	strcpy(user.firstName,"Bobi");
	
//	printf("FN: %s\n",user.firstName);
//	printf("LN: %s\n",user.lastName);
//	printf("Age: %d\n",user.age);
//	
	strcpy(user.lastName,"Bola");
	
//	printf("FN: %s\n",user.firstName);
//	printf("LN: %s\n",user.lastName);
//	printf("Age: %d\n",user.age);
	
	// Union can't be switched one by one, they have 1 member
	
//	int a=10;
//	int *ptr=&a;
//	int n=10;
//	Movie *mov = (Movie*)malloc(n*sizeof(Movie));
//	strcpy((mov+2)->name,"Hello Kiti");
//	strcpy((mov+2)->year,"2007");
//	(mov+2)->rating = 5;
//	// mov+2 is the same as mov[2], for dynamic memory thing
//	printf("%d\n",(mov+2)->rating);
//	printf("%s\n",(mov+2)->name);
//	printf("%s\n",(mov+2)->year);
	
	/*
	Tugas: simpan data dri 10 movies
	char name [10][100];
	int rating[10];
	int year[10];
	not struct jadi ribet
	*/
	//data.csv to make an excel file, pindah table with the delimiter(either ; or , depends on the excel) like Bobi,9,2022
//	FILE *fptr = fopen("data.txt","w");
//	fprintf(fptr,"Tes ini Data\n");
//	fclose(fptr);
	
	FILE *fptr = fopen("data.txt","r");
	int counter=0;
	while(!feof(fptr)){
		char temp[150];
		fscanf(fptr,"%[^\n]\n",temp);
		printf("%d %s\n",++counter,temp);
	}
//	fprintf(fptr,"Tes ini Data\n");
	fseek(fptr,0,SEEK_SET); //ulang dari awal
	while(!feof(fptr)){
		char temp[150];
		fscanf(fptr,"%[^\n]\n",temp);
		printf("%d %s\n",++counter,temp);
	}
	fclose(fptr);
	
	
 	return 0;
}

