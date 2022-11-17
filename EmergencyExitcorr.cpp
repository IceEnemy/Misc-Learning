#include <stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int len,hold;
		scanf("%d %d",&len,&hold);
		getchar();
		char cor[len+10];
		scanf("%s",cor);
		getchar();
		int sum=0;
		int ded=0;
		int check = 0;
		int next;
		if(hold>=len){
			printf("Case #%d: Alive\n",i);
			continue;
		}
		for(int j=0;j<len;j++){
			if(cor[j]=='0'){
				sum++;
				if(sum==hold){
				ded=1;
				break;
				}
			}
			else if(cor[j]=='1'){
				for(int k=0;k<len;k++){
					check+=(int)cor[k]-48;
					if(cor[k]=='1'){
						next=k;
//						printf("%d ",next);
					}
				}	
				if(check==1){
					ded=1;
					break;
				}
				else if(check>1){
					j=next;
					sum=0;
				}
			}
		}
		if(ded==1){
			printf("Case #%d: Dead\n",i);
		}
		else{
			printf("Case #%d: Alive\n",i);
		}
	}
 	return 0;
}
