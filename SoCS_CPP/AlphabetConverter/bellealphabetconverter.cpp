#include <stdio.h>
#include <string.h>
// int main()
// {
//     FILE *bellefile = fopen("testdata.in", "w");
//     fclose(bellefile);
//     return 0;
// }

int main()
{
    int T;
    char string[110];

    FILE *bellefile = fopen("testdata.in", "r");

    fscanf(bellefile, "%d\n", &T);
    

    for (int i = 1; i <= T; i++)
    {
    	fscanf(bellefile, "%s\n", string);

    	int length = strlen(string);
        int change;
        fscanf(bellefile, "%d\n", &change);

        char alpha;
        char convert;

        int checking[26] = {0};
        for (int x = 0; x < change; x++)
        {
            fscanf(bellefile, "%c %c\n", &alpha, &convert);

            if (checking[alpha - 'A'] == 0)
            {
                checking[alpha - 'A']++;

                for (int k = 0; k < length; k++)
                {
                    if (string[k] == alpha)
                    {
                        string[k] = convert;
                    }
                    else
                    {
                        string[k] = string[k];
                    }
                }
            }
        }

        // printf("%s\n", string);

        int counter[27] = {0};
        for (int o = 0; o < length; o++)
        {
            for (int l = 0; l < 26; l++)
            {
                if (string[o] == 'A' + l)
                {
                    counter[l]++;
                }
            }
        }

        for (int j = 0; j < 26; j++)
        {
            if (counter[j] > 0)
            {
                printf("%c %d\n", 'A' + j, counter[j]);
            }
        }
    }

    fclose(bellefile);
    return 0;
}
