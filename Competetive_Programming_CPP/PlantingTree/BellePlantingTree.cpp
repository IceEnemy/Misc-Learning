#include <stdio.h>
#include <string.h>
// int main()
// {
//     FILE *bellefile = fopen("testdata.in", "w");
//     fclose(bellefile);
//     return 0;
// }

struct plantdata
{
    char person[110];
    char plant[110];
};

int main()
{
    FILE *bellefile = fopen("testdata.in", "r");

    struct plantdata data[1100];

    int num;
    fscanf(bellefile, "%d\n", &num);
    printf("%d\n",num);
    for (int i = 0; i < num; i++)
    {
        fscanf(bellefile, "%[^#]#%[^\n]\n", data[i].person, data[i].plant);
         printf("%s %s\n", data[i].person, data[i].plant);
    }

    int numberpersonprint;
    char namepersonprint[110];

    fscanf(bellefile, "%d\n", &numberpersonprint);
    for (int i = 1; i <= numberpersonprint; i++)
    {
        fscanf(bellefile, "%[^\n]\n", namepersonprint);
        printf("Case #%d: ", i);
        for (int x = 0; x < num; x++)
        {
            if (strcmp(namepersonprint,data[x].person)==0)
            {
                printf("%s\n", data[x].plant);
                break;
            }
            else if(x==num-1){
            	printf("N/A\n");
			}
        }
    }

    fclose(bellefile);
    return 0;
}

