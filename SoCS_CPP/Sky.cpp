#include <stdio.h>

int main()
{
	int s;
	scanf("%d",&s);
	int map[s][s];
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	for(int i=s-1;i>=0;i--){
		for(int j=s-1;j>=0;j--){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
//	printf("\n");
//	for(int i=0;i<s;i++){
//		for(int j=s-1;j>=0;j--){
//			printf("%c",map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(int i=s-1;i>=0;i--){
//		for(int j=0;j<s;j++){
//			printf("%c",map[i][j]);
//		}
//		printf("\n");
//	}
 	return 0;
}

