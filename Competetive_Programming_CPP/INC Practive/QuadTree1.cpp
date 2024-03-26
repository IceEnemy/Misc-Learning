#include <bits/stdc++.h>
using namespace std;

int counter = 0;
vector<vector<int> > board;
vector<string> coords;

int getSize(int r, int c){
	int size = 1;
	while(size < r || size < c){
		size*=2;
	}
	return size;
}

void fillEmpty(int r, int c, int size){
	for(int i=0; i<size; i++){
		int j;
		if(i < r) j = c;
		else j=0;
		while(j < size){
			board[i][j] = 0;
			j++;
		}
		
	}
}

void printMap(int l, int r, int up, int down){
	for(int i=l; i<=r; i++){
		for(int j=up; j<=down; j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

bool homogen(int l, int r, int up, int down){
//	printMap(l,r,up,down);
//	printf("\n\n");
	int check = board[l][up];
	for(int i=l; i<=r; i++){
		for(int j=up; j<=down; j++){
			if(board[i][j] != check){
				return false;
			} 
		}
	}
	return true;
}

void record(string curr, int l, int r, int up, int down){
	if((l == r && up == down) || homogen(l,r,up,down)){
		if(board[l][up] == 1){
			curr[0] = '1';
			coords.push_back(curr);
			counter++;
		}
	}
	else{
		int mid1, mid2;
		mid1 = (l+r)/2;
		mid2 = (up+down)/2;
		record(curr + "0",l,mid1,up,mid2);
		record(curr + "1", l, mid1, mid2+1, down);
		record(curr + "2", mid1+1, r, up, mid2);
		record(curr + "3", mid1+1, r, mid2+1, down);
	}
}

int main()
{
	int r,c;
	scanf("%d %d",&r, &c);
	
	int s = getSize(r,c);
	board.resize(s, vector<int>(s));
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d",&board[i][j]);
		}
	}
	fillEmpty(r,c,s);
	
//	printMap(s);
	record("0",0,s-1,0,s-1);
	cout << counter << endl;
	for(int i=0; i<counter; i++){
		cout << coords[i] << endl;
	}
//	printf("hey\n");
 	return 0;
}

