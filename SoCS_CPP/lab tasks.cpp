#include <stdio.h>
int main()
{
	int a,b,c,d,num1,num2,odev;
	char name[100];
	scanf("%d %d", &a,&b);
	if(a >= b){
		printf("%d\n", a);
	}
	else{
		printf("%d\n", b);
	}
	
	scanf("%d", &c);
	if(c % 3 == 0 && c % 5 == 0){
		printf("fizzbuzz\n");
	}
	else if(c % 3 == 0 && c % 5 != 0){
		printf("fizz\n");
	}
	else if(c % 5 == 0 && c % 3 != 0){
		printf("buzz\n");
	}
	else{
		printf("-\n");
	}
	printf("1. Introduction\n2. Simple addition\n3. Even/odd?\n");
	scanf("%d", &d);
	if(d == 1){
		printf("Your name is: ");
		getchar();
		scanf("%[^\n]", name); 
		printf("Hello, welcome %s", name);
	}
	else if(d == 2){
		printf("Input two numbers: ");
		scanf("%d %d",&num1,&num2);
		printf("%d",num1 + num2);
	}
	else if(d == 3){
		printf("Input a number: ");
		scanf("%d", &odev);
		if(odev % 2 == 0){
			printf("Your number is Even");
		}
		else{
			printf("Your number is Odd");
		}
	}
	else{
		printf("That menu doesn\'t exist!");
	}
	
	// if you want to compare strings use strcmp with #include <string.h> example:
	// if(strcmp(the answer), ans) == 0)
	
	return 0;
}

