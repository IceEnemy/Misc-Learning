#include <stdio.h>
#include <string.h>

int main(){
	//1
//	int a;
//	a = 20;
//	
//	int *ptr_a;
//	ptr_a = &a;
//	
//	//& is to get the address of the variable
//	//* get the value of the variables stored in a pointer through pointer
//	
//	printf("value of a: %d\n",a);
//	printf("address of a: %d\n",&a);
//	
//	printf("value of ptr_a: %d\n",ptr_a);
//	printf("value of a thru ptr_a: %d\n",*ptr_a);
//	printf("address ptr_a: %d\n",&ptr_a);
//	
//	*ptr_a = 10;
//	printf("value of a: %d\n",a);
//	
//	//double pointers
//	int **ptr_ptr_a;
//	ptr_ptr_a = &ptr_a;
//	printf("value of ptr_ptr_a: %d\n",ptr_ptr_a);
//	printf("value of a thru ptr_ptr_a: %d\n",**ptr_ptr_a);
	
	//one dimensional array
//	int ar1[5];
//	int ar2[]= {1,2,3,4,5};
//	
//	printf("%d\n",ar2[3]);
//	//or
//	for(int i=0;i<sizeof(ar2)/sizeof(int);i++){
//		printf("index %d: %d\n",i,ar2[i]);
//	}
//	//sizeof(ar2)/sizeof(int) is to count the size of an array
//
//	char str[100]="abcde";
//	
//	printf("strlen: %d\n",strlen(str));
//	printf("strlen: %d\n",sizeof(str));
//	//strlen counts the active letters while sizeof counts the whole 100
//	
	
//	//multidimensional array
//	int num_table[5][2] ={
//					{1,3},
//					{2,6},
//					{-1,7},
//					{11,4},
//					{10000,8}	
//	};
//	for(int i=0;i<5;i++){
//		for(int j=0;j<2;j++){
//			printf("%d ",num_table[i][j]);
//		}
//		puts("");
//	}
	int n,m;
	scanf("%d %d",&n,&m);
	int num2[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&num2[i][j]);
		}
	}
	for(int i=0;i<sizeof(num2)/sizeof(num2[0]);i++){
		for(int j=0;j<sizeof(num2[0])/sizeof(int);j++){
			printf("%d ",num2[i][j]);
		}
		puts("");
	}
	return 0;
}

