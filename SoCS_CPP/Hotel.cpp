#include <stdio.h>

int main()
{
	int guest;
	scanf("%d",&guest);
	int room[guest];
	for(int i=0;i<guest;i++){
		scanf("%d",&room[i]);
	}
	for(int i=0;i<guest;i++){
		for(int j=i+1;j<guest;j++){
			if(room[i]==room[j]){
				for(int k=j;k<guest-1;k++){
					room[k]=room[k+1];
				}
				guest--;
				j--;
			}
		}
	}
	printf("%d\n",guest);
 	return 0;
}

