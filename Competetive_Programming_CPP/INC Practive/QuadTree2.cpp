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

void fillEmpty(int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			board[i][j] = 0;
		}
	}
}

void printBoard(int r, int c){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(j == c-1) printf("%d\n",board[i][j]);
			else printf("%d ",board[i][j]);
		}
	}
}

void fillOne(int l, int r, int up, int down){
	for(int i=l; i<=r; i++){
		for(int j=up; j<=down; j++){
			board[i][j] = 1;
		}
	}
}

void fillBoard(string coord, int idx, int l, int r, int up, int down){
	if(idx >= coord.length()-1) fillOne(l,r,up,down);
	else{
		int mid1 = (l+r)/2;
		int mid2 = (up+down)/2;
		if(coord[idx+1] == '0') fillBoard(coord,idx+1,l,mid1,up,mid2);
		else if(coord[idx+1] == '1') fillBoard(coord,idx+1,l,mid1,mid2+1,down);
		else if(coord[idx+1] == '2') fillBoard(coord,idx+1,mid1+1,r,up,mid2);
		else if(coord[idx+1] == '3') fillBoard(coord,idx+1,mid1+1,r,mid2+1,down);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	coords.resize(n);
	
	for(int i=0; i<n; i++){
		cin >> coords[i];	
	}
	int r,c;
	scanf("%d %d",&r, &c);
	
	int s = getSize(r,c);
	board.resize(s, vector<int>(s));
	
	fillEmpty(s);
	
	for(int i=0; i<n; i++){
		fillBoard(coords[i],0,0,s-1,0,s-1);
	}
	printBoard(r,c);
 	return 0;
}

