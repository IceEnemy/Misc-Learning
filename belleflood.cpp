#include <stdio.h>
int counter = 0;

void flood(char wall[][105], int a, int b)
{
    if(wall[a][b] == 'S')
    {
        wall[a][b] = '#';
        flood(wall, a + 1, b);
        flood(wall, a - 1, b);
        flood(wall, a, b + 1);
        flood(wall, a, b - 1);
    }
    else if(wall[a][b] == '.')
    {
        counter++;
        wall[a][b] = '#';
        flood(wall, a + 1, b);
        flood(wall, a - 1, b);
        flood(wall, a, b + 1);
        flood(wall, a, b - 1);
    }
}
int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++)
    {
        counter = 0;
        int height, width;
        scanf("%d %d",&height, &width);

        int a, b;

        char wall[height][105];
        for(int x = 0; x < height; x++)
        {
            for(int y = 0; y < width; y++)
            {
                scanf(" %c", &wall[x][y]);
                if(wall[x][y] == 'S')
                {
                    a = x;
                    b = y;
                }
            }
        }

       printf("Case #%d: ", i);
       flood(wall, a, b);
       printf("%d\n", counter);

        for(int b = 0; b < height; b++)
        {
            for(int c = 0; c < width; c++)
            {
                wall[b][c] = '#';
            }
        }

    }
    return 0;
} 


