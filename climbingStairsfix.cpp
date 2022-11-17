#include <stdio.h>
int main()
{
    int stair,sum=1,var=0;
    scanf("%d",&stair);
    int step[stair];
    int taken[stair];
    for(int i=0;i<stair;i++){
        scanf("%d",&step[i]);
    }
    for(int j=0;j<stair;j++){
        int dif = step[j+1]-step[j];
        if(j==stair-1){
            taken[var]=sum;
        }
        else if(dif>0){
            sum++;
        }
        else{
            taken[var]=sum;
            sum=1;
            var++;
        }
    }
    for(int k=0;k<=var;k++){
        printf("%d ",taken[k]);
    }
    printf("\b");
    printf("\n");
     return 0;
}
