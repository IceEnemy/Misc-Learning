#include <stdio.h>
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        int house;
        scanf("%d",&house);
        int height[house];
        for(int j=0;j<house;j++){
            scanf("%d",&height[j]);
        }
        int smallest = height[0]-height[1];
        if(smallest < 0){
            smallest = -smallest;
        }
        for(int k=0;k<house;k++){
            if(k==house-1){
            break;
            }
            int dif = height[k] - height[k+1];
            if(dif < 0){
                dif = -dif;
            }

            if(dif < smallest){
                smallest = dif;
            }
        }
        printf("Case #%d: %d\n",i,smallest);
    }
     return 0;
}
