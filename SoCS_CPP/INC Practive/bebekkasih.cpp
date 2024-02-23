#include <bits/stdc++.h>
using namespace std;

int main()
{
	int total, person, mod;
	scanf("%d %d",&total, &person);
	mod = total/person;
	total = total % person;
	printf("masing-masing %d\n",mod);
	printf("bersisa %d\n",total);
 	return 0;
}

