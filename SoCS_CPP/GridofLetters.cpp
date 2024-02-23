#include <stdio.h>
#include <string.h>

struct grid{
	char letter[210];
};

int main()
{
	int row,col;
	scanf("%d %d",&row,&col);
	struct grid lStr[210];
	for(int i=0;i<row;i++){
		scanf("%s",lStr[i].letter);
		for(int j=0;j<col-1;j++){
			for(int k=0;k<col-1-j;k++){
				if(lStr[i].letter[k]>lStr[i].letter[k+1]){
					char temp=lStr[i].letter[k];
					lStr[i].letter[k]=lStr[i].letter[k+1];
					lStr[i].letter[k+1]=temp;
				}
			}
		}
	}
//	for(int i=0;i<row;i++){
//		printf("%s\n",lStr[i].letter);
//	}
//	printf("=======================\n");
	char tempy[210];
	for(int i=0;i<row-1;i++){
		for (int j=0;j<row-1;j++){
			if(strcmp(lStr[j].letter,lStr[j+1].letter)<0){
//				struct grid tempy=lStr[j];
//				printf("tempy : %s\n",tempy[j].letter);
				tempy=lStr[j].letter;
				lStr[j].letter=lStr[j+1].letter;
				lStr[j+1].letter=tempy;
			}
			
		}
	}
	
	for(int i=0;i<row;i++){
		printf("%s\n",lStr[i].letter);
	}
	
 	return 0;
}

