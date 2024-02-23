#include <bits/stdc++.h>
using namespace std;

int main()
{
	string A,B;
	cin >> A >> B;
	int diff = 0;
	if(B.length() < A.length() || A.length()-B.length() == 1){
		for(int i=0, j=0; i<A.length(); i++, j++){
			if(j == B.length()) diff++;
			else{
				if(A[i] != B[j]){
					diff++;
					j--;
				}	
			}
		}	
	}
	if(diff == 1) cout << "Tentu saja bisa!" << endl;
	else cout << "Wah, tidak bisa :(" << endl;
	
 	return 0;
}

