#include <stdio.h>
#include <string.h>
int main()
{
    int test,tst=1,maxnum=1,dot=0;
    scanf("%d",&test);
    getchar();
    for(int i=1;i<=test;i++){
        char ip[100];
        scanf("%s",ip);
        for(int j=0;j<strlen(ip);j++){
            	if(ip[j]>=0 && ip[j]<=9 && maxnum<=6){
            		dot = 1;
				}
				else if(ip[j]=='.' && dot==1){
					maxnum++;
					dot=0;
				}
				else{
					tst=0;
				}
        }
        if(tst==1 && maxnum == 6)
        printf("Case #%d: YES\n",i);
        else
        printf("Case #%d: NO\n",i);
    }
     return 0;
}
