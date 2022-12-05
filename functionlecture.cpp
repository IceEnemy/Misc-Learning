#include <stdio.h>

//int x,y --> global variables, can be declared in any function

int sum(int a,int b){ //--> sums x and y
	return a+b;
	/*
	OR
	int result=a+b;
	return res;
	*/
}

void printres(int res); //--> this is to mention that you have a function below the main function so it reads (prototype function)

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}
/*
normal functions usually just pass by value, the value of the originals are not changed.
if you want to change the value of a variable outside of the function, use pointers to pass by refrence.
*/

/*
multidimentional arrays have to have a value after the first box, like map[][20], map[][20][20], in one dimentional arrays,
you dont have to add any value like map[].
*/

void printNameA(char name[]){
	name[0]='A';
	printf("%s\n",name);
}
/*
arrays dont need stars because an array itself is a pointer, so you can just use char *name instead of char name[].
*/

//recursive function is a function that calls itself, it's similar to a loop.
void revPrint(int n){
	if(n>0){
		printf("%d\n",n);
		revPrint(n-1);
	}
}

long long int fib(int n){
	if(n<=1) return n;
	else return fib(n-1) + fib(n-2);
}


int main()
{
	int x,y,res;
	scanf("%d %d",&x,&y);
	
	//function to sum x and y
	
	res = sum(x,y);
	printf("%d\n",res);
	printres(res);
	swap(&x,&y);
	printf("x: %d\n",x);
	printf("y: %d\n",y);
	
	char name[100];
	scanf("%s",name);
	printNameA(name);
	printf("%s\n",name);
	revPrint(10);
	int n;
	scanf("%d",&n);
	printf("%lld\n",fib(n));
 	return 0;
}

void printres(int res){ //--> voids are functions that dont return anything, usually used for printing
	printf("The result is: %d\n",res);
}

