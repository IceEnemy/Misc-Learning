#include <stdio.h>
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        int length,plus;
        scanf("%d %d",&length,&plus);
        getchar();
        char str[length];
        scanf("%s",str);
        printf("Case #%d: ",i);
        for(int k=0;k<length;k++){
            int number=str[k] + plus;
            while(number>122){
                number -= 26;
            }
            printf("%c",number);
        }
        printf("\n");
    }
     return 0;
}
