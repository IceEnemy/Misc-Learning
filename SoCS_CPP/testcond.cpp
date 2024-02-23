// if you use an increment in a single statement, B++ And ++B will be the same, if you use it in another statement,
//++b will add value first while b++ will add value after.

#include <stdio.h>
int main()
{
    int a=2,b=2,c=2;
    char A[100];
    if(a==b && b==c){
        printf("Hello World\n");
}
//conditional assignment
printf("%s\n", (a==b)? "Yes":"No");

scanf("%s", A);
if(A == "thing"){
	printf("Yes\n");
}
    else{
    	printf("no\n");
	}
    
    // XOR : if both statements are the same value, then it will output 0, if they are different, they will print out 1
    /*
    shift left or right
    binary:
    2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
     0   0   0   0   1   0   0   0
     0   0   0   0   0   0   1   0 shift right by 2 b>>2
     0   1   0   0   0   0   0   0 shift left by 3 b<<3
     shiftinf left or right means multiplication & division by 2 to the power of the value set ex: 3 in b<<'3'
     
     finding an odd occuringnumber:
     
     int num[15]={1,2,2};
     int res=0;
     for(int i=0; i<3; i++){
     res^=num[i];
	}
	printf("%d\n", res);
	return 0;
	 */
     
     //pointer
     int *p=&a;
     printf("%d\n", p);
     return 0;
}

