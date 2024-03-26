#include <stdio.h>
int main()
{
	//switch cases will only compare int and char and then it will only compare wether it's true or not
/* switch structure:
switch(variable){
case 'input':
printf("print")
	break;
	the else for this is default:
	you cannot declare a variable in the switch case unless you put {} like in if
	*/
	int a,num1,num2,odev;
	char name[100];
	printf("1. Introduction\n2. Simple addition\n3. Even/odd?\n");
	scanf("%d", &a);
	switch(a){
		case 1:
		printf("Your name is: ");
		getchar();
		scanf("%[^\n]", name); 
		printf("Hello, welcome %s", name);
		break;
		case 2:
		printf("Input two numbers: ");
		scanf("%d %d",&num1,&num2);
		printf("%d",num1 + num2);
		break;
		case 3:
		printf("Input a number: ");
		scanf("%d", &odev);
		if(odev % 2 == 0){
			printf("Your number is Even");
		}
		else{
			printf("Your number is Odd");
		}
		break;
		default:
			printf("That menu doesn\'t exist!");
	}

	return 0;
}
