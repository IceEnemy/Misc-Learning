#include <stdio.h>
int main(){
	int year;
	printf("Input a year: ");
	scanf("%d", &year);
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		printf("A leap year\n");
	}
	else{
		printf("not a leap year\n");
	}
	// or it can be written as printf("%s\n", (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? "A leap year":"Not a leap year");
	return 0;
}
