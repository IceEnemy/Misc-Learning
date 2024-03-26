#include <bits/stdc++.h>
using namespace std;

char board[25][10];

void dubrak(int R, int C, int low);

void tetris(int R, int C){
//	printf("tetris\n");
	int low = -1;
	for(int i=0; i<R; i++){
		int count = 0;
		for(int j=0; j<C; j++){
//			printf("tetris %d\n",j);
			if(board[i][j] == '1'){
				count++;
//				printf("satu\n");
			}
		}
		if(count == C){
//			printf("trtris!\n");
			for(int j=0; j<C; j++){
				board[i][j] = '0';
			}
			low = i;
		}
	}
	if(low != -1) dubrak(R,C,low);
}

void dubrak(int R, int C, int low){
//	printf("dubrak\n");
	for(int j=0; j<C; j++){
		for(int i = low-1; i >=0; i--){
			if(board[i][j] == '1'){
				int coord = i;
				while(coord != R-1 && board[coord+1][j] == '0'){
					board[coord][j] = '0';
					board[++coord][j] = '1';
				}
			}
		}
	}
	tetris(R,C);
}


int main()
{
	int R, C;
	cin >> R >> C;
	
	
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf(" %c",&board[i][j]);
		}
		getchar();
	}
	
	tetris(R,C);
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
 	return 0;
}

