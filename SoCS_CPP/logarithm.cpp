#include <stdio.h>

//void log(int n,int m,int *counter){
//	if(m<n) return;
//	(*counter)++;
//	log(n,m/n,counter);
//}

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		long long int counter=0;
		long long int n,m;
		scanf("%lld %lld",&n,&m);
//		log(n,m,&counter);
		while(m>=n){ 
			counter++;
			m/=n;
		}
		printf("Case #%d: %lld\n",i,counter);
	}
 	return 0;
}

