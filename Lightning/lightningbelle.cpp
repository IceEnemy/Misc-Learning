#include <stdio.h>
// int main()
// {
//     FILE *bellefile = fopen("testdata.in", "w");
//     fclose(bellefile);
//     return 0;
// }

int main()
{
    FILE *bellefile = fopen("testdata.in", "r");

    int T;
    fscanf(bellefile, "%d\n", &T);
    printf("%d\n",T);

    for (int i = 1; i <= T; i++)
    {
        int total, min, max;
        fscanf(bellefile, "%d %d %d\n", &total, &min, &max);
        printf("%d %d %d\n", total, min, max);

        int counter = 0;
        int sum = 0;
        for (int x = 0; x < total; x++)
        {
            char sound[total+5];
            fscanf(bellefile, "%c", &sound[x]);
            printf("%c",sound[x]);
            if (sound[x] == '1')
            {
                counter++;
            }
            if (sound[x] == '0' || x == total-1)
            {
                if (counter >= min && counter <= max)
                {
                    sum++;
                    counter = 0;
//                    break;
                }
                else
                {
                    counter = 0;
                }
            }
        }
        printf("\n");

        printf("Case #%d: %d\n", i, sum);
    }
    fclose(bellefile);
    return 0;
}
