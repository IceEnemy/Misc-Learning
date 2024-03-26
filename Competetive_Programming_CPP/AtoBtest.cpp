#include <stdio.h>

bool AtoB(int A,int B){
	if(A==B) return true;
	else if(A==1) return false;
	else if(A%2==0) return AtoB(A/2,B);
	else if(A%2==1) return AtoB(A*3+1,B);
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int A,B;
		scanf("%d %d",&A,&B);
		bool check=AtoB(A,B);
		
		if(check==true) printf("Case #%d: YES\n",i);
		else printf("Case #%d: NO\n",i);
	}
 	return 0;
}

