#include <stdio.h>
#include <string.h>

/*
	how to compare strings
	if(strcmp(data[i].NIM , data[i+1].NIM) > 0) --> the first string has bigger ascii
	if mau pake bubble sort with a struct, declare the temporary variable as a struct
	struct studentData temp = data[i] n stuff

*/


struct studentData{
	char NIM[15];
	char name[1010];
};

int main()
{
	FILE *fp = fopen("testdata.in","r");
	int test;
	fscanf(fp,"%d",&test);
	struct studentData data[1010];
//	fprintf(fp,"Nama saya Norberth\n");
//	int i=0;
//	while(fscanf(fp,"%s %s\n",data[i].NIM,data[i].name)!= EOF){
//		i++;
//	} -->this is for when files dont have a size.
	for(int i=0;i<test;i++){
		fscanf(fp,"%s %s\n",data[i].NIM,data[i].name);
		
	}
	//%[^#]# --> scan until # (the other # is to eat the #)
	// struct is not like an array, you need a pointer to change the struct
	fclose(fp);
 	return 0;
}

