#include <stdio.h>
int main()
{
    int test,games,lili,bibi;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        lili = 0;
        bibi = 0;
        scanf("%d",&games);
        char res[games+10];
        scanf("%s",res);
        
        for(int j=0;j<games;j++){
            if(res[j] == 'B'){
                bibi++;
            }
            else if(res[j] == 'L'){
                lili++;
            }
        }
        if(lili==bibi){
            printf("None\n");
        }
        else if(bibi>lili){
            printf("Bibi\n");
        }
        else if(bibi<lili){
            printf("Lili\n");
        }
    }
     return 0;
}
