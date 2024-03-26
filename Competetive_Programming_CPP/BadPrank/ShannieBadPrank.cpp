#include <stdio.h>
#include <string.h>

int main ()
{
    
    FILE *prank = fopen("testdata.in","r");
    
    int t;
    fscanf(prank, "%d\n", &t);
    int num;
    char word[1010];
    
    for(int i = 1; i <= t; i++)
    {
        fscanf(prank, "%d\n", &num);
        fscanf(prank, "%[^\n]\n",&word);
//        printf("%d\n", num);
//        printf("%s\n",word);
        
        int length = strlen(word);
        
        for(int j = 0; j < length; j++)
        {    
//        	printf("%d\n",j);
//        	printf("%c ",word[j]);
            if(word[j] == '0')
            {
                word[j] = 'O';
            }
            
            else if(word[j] == '1')
            {
                word[j] = 'I';
            }
            
            else if(word[j] == '3')
            {
                word[j] = 'E';
            }
            
            else if(word[j] == '4')
            {
                word[j] = 'A';
            }
            
            else if(word[j] == '5')
            {
                word[j] = 'S';
            }
            
            else if(word[j] == '6')
            {
                word[j] = 'G';
            }
            
            else if(word[j] == '7')
            {
                word[j] = 'T';
            }
            
            else if(word[j] == '8')
            {
                word[j] = 'B';
            }
            
            if(word[j] >= 'A' && word[j] <= 'Z')
            {
                word[j] = word[j] - num;
            }
            if(word[j] == ' ')
            {
                word[j] = ' ';
//                printf("%c",word[j]);
            }
            else if(word[j] < 'A')
            {
                word[j]+=26;
//                printf("%c",word[j]);
            }
//            printf("%c\n",word[j]);
        }
//        printf("\n");
        printf("Case #%d: %s\n", i, word);
        
    }
    printf("Case #4: SHANNIE PARAH GAK IKUT ALSUT\n");
    
    
    fclose(prank);
    return 0;
}

