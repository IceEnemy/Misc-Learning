#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int num[],int size){
//	int size = sizeof(num)/sizeof(num[0]);
//	printf("%d\n",size); --> this wont work in a function because it will evaluate as sizeof(int*)/sizeof(int) which will always be 2
	for(int i=0;i<size;i++){
		if(i!=size-1){
			printf("%d ",num[i]);
		}
		else{
			printf("%d\n",num[i]);
		}
	}
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct Person{
	char name[100];
	int age;
};

int main()
{
//	int num[5] = {0,1,3,4,5};
//	int size = sizeof(num)/sizeof(num[0]);
//	printf("%d\n",size);
//	printf("Address of array : %lld\n",num);
//	num[0] = 1;
//	printArray(num,size);
//	*(num+1) = 2;
//	printArray(num,size);
//	int *num = (int *)malloc(sizeof(int)*5);
//	*num = 1;
//	*(num+1)= 2;
//	num[2]=3;
//	printArray(num);
//	//normal struct
//	struct Person person1;
//	strcpy(person1.name,"Guido");
//	person1.age = 10;
//	printf("%s %d\n",person1.name,person1.age);
//	// pointer struct
//	struct Person *person2 = (struct Person *)malloc(sizeof(struct Person));
//	strcpy(person2->name,"Mista");
//	person2->age = 16;
//	printf("%s %d\n",person2->name,person2->age);
//	//(*ptr).name == ptr->name

	int a = 10;
	int b = 5;
	printf("%d %d\n",a,b);
	swap(&a,&b);
	printf("%d %d\n",a,b);
 	return 0;
}

