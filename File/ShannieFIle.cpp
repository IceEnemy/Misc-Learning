#include <stdio.h>
#include <string.h>

struct kamusgaul{
    char singkat[55];
    char asli[55];
};

struct berang{
    char word[105];
};

int main ()
{
    FILE *otter = fopen("testdata.in", "r");
    
    int num;
    fscanf(otter, "%d\n", &num);
    printf("%d\n", num);
    
    struct kamusgaul data[105];
    
    for(int i = 1; i <= num; i++)
    {
        fscanf(otter, "%[^#]#%s\n", &data[i].singkat, &data[i].asli);
    }
    
    int t;
    fscanf(otter, "%d\n", t);
    printf("%d\n", t);
    struct berang air[105];
    
    for(int i = 1; i <= t; i++)
    {
        char pisah = 'o';
        int count = 0;
        while(pisah != '\n')
        {
            fscanf(otter, "%s%c", air[count].word, &pisah);
            count++;
        }
        
        for(int j = 0; j < count; j++)
        {
            for(int k = 0; k < num; k++)
            {
                if(air[j].word == data[k].singkat)
                {
                    strcpy(air[j].word, data[k].asli);
                }
            }
        }
        
        printf("Case #%d:\n", i);
        
        for(int j = 0; j < count; j++)
        {
            if(j != count-1)
            {
                printf("%s ", air[j].word);
            }
            else{
                printf("%s\n", air[j].word);
            }
        }    
    }
    
    fclose(otter);
    return 0;
}

