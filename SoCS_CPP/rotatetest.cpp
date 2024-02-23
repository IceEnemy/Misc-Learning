#include <stdio.h>
int main()
{
    int test,size;
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        int var=0;
        scanf("%d",&size);
        printf("Case #%d:\n",i);
        for(int j=1;j<=size;j++){
            int rep =j-size+1;
            for(int k=1;k<=size;k++){
                int odev=k+var;
            if(rep<=0){
                printf(" ");
            }
            else if(rep>0 && odev%2==0){
                printf("#");

            }
            else if(rep>0 && odev%2 != 0){
                printf("*");
            }
            rep++;
        }
        var++;
        printf("\n");
        }

    }

     return 0;
}
