#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int pancakes;
        scanf("%d", &pancakes);

        printf("Case #%d: ", i);

        long long int slice = 1;
        long long int result = 0;
        for (int x = 0; x < pancakes; x++)
        {
            if (x == 0 && x == pancakes - 1)
            {
                printf("%d\n", slice + x);
            }
            else if (x == pancakes - 1)
            {
                printf("%d\n", result + x);
                result += x;
            }
            else if (x == 0)
            {
                result = slice + x;
                printf("%d ", result);
            }
            else
            {
                printf("%d ", result + x);
                result += x;
            }
        }
    }
    return 0;
}

