#include <stdio.h>

struct student{
	char nim[11];
	char name[50];
	double gpa;
};

struct studentFile{
	char name[50];
	char gender[50];
	int score;
};

int main()
{
//	struct student gr[100];
//	int test;
//	scanf("%d",&test); getchar();
//	for(int i=0;i<test;i++){
//		printf("Enter ur NIM:\n");
//		scanf("%s",gr[i].nim); getchar();
//		printf("Enter ur Name:\n");
//		scanf("%[^\n]",gr[i].name); getchar();
//		printf("Enter ur GPA:\n");
//		scanf("%lf",&gr[i].gpa); getchar();
//	
//		printf("NIM: %s\n",gr[i].nim);
//		printf("Name: %s\n",gr[i].name);
//		printf("GPA: %.2lf\n",gr[i].gpa);
//	}
//	printf("First NIM: %s\n",gr[0].nim);
//	printf("First Name: %s\n",gr[0].name);
//	printf("First GPA: %.2lf\n",gr[0].gpa);
//
//	printf("First letter: %c\n",gr[0].name[0]);
	FILE *fp = fopen("testdata.txt","r");
//	int test;
//	fscanf(fp,"%d\n",&test);
	struct studentFile data[100];
//	for(int i=0;i<test;i++){
//		fscanf(fp,"%[^#]#%[^-]-%d\n",data[i].name,data[i].gender,&data[i].score);
//		printf("Hi %s! You're %s with a score of %d\n",data[i].name,data[i].gender,data[i].score);
//	}
	int n=0;
	printf("+----------+----------+-----+\n");
	printf("|Name      |Gender    |Score|\n");
	printf("+----------+----------+-----+\n");
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^-]-%d\n",data[n].name,data[n].gender,&data[n].score);
		printf("|%-10s|%-10s|%-5d|\n",data[n].name,data[n].gender,data[n].score);
		printf("+----------+----------+-----+\n");
		//-10 n stuff i the string to print justified strings (lengths the same)
		n++;
	}
//	printf("+-------------------------------+\n");
	// scanf("%c",fgetc(fp)); to get a single char while fgets is for string
	
	fclose(fp);
 	return 0;
}

