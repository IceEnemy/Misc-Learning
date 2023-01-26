#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int num[n];
	int oddArr[n],evenArr[n];
	int oddCount=0,evenCount=0;
	
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]%2==0){
			evenArr[evenCount++]=num[i];
		}
		else{
			oddArr[oddCount++]=num[i];
		}
	}
	
//	for(int j=0;j<oddCount;j++){
//		printf("%d ",oddArr[j]);
//	}
//	printf("\n");
//	
//	for(int j=0;j<evenCount;j++){
//		printf("%d ",evenArr[j]);
//	}
//	printf("\n");
	
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int lim;
		scanf("%d",&lim);
		int odd=0;
		int even=0;
		
		for(int j=0;j<oddCount-1;j++){
			for(int k=j+1;k<oddCount;k++){
				if(oddArr[j]+oddArr[k]>=lim){
//					printf("%d + %d >= %d\n",oddArr[j],oddArr[k],lim);
					odd++;
				}
			}
		}
		for(int j=0;j<evenCount-1;j++){
			for(int k=j+1;k<evenCount;k++){
				if(evenArr[j]+evenArr[k]>=lim){
					even++;
//					printf("%d + %d >= %d\n",evenArr[j],evenArr[k],lim);
				}
			}
		}
		printf("Case #%d: %d %d\n",i,odd,even);
	}
 	return 0;
}

