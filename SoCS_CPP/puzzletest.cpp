#include <stdio.h>

int main()
{
	int size;
	int condition = 0;
	scanf("%d",&size);
	int puz[size][size];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			scanf("%d",&puz[i][j]);
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			for(int k=j+1;k<size;k++){
				if(puz[i][j]!=puz[j][i] || puz[i][j]==puz[i][k]){
					condition++;
					break;
				}
			}
		}
	}
	if(condition == 0){
		printf("Yay\n");
	}
	else{
		printf("Nay\n");
	}
 	return 0;
}

