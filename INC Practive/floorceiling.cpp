#include <bits/stdc++.h>
using namespace std;

int main()
{
	double inp;
	int floor,ceiling;
	int check;
	scanf("%lf",&inp);
	check = inp;
	if(inp == check){
		floor = ceiling = inp;
	}
	else if(inp < 0){
		ceiling = inp;
		floor = ceiling - 1;
	}
	else{	
		floor = inp;
		ceiling = floor + 1;
	}
	printf("%d %d\n",floor, ceiling);
 	return 0;
}

