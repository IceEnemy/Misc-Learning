#include <cstdio>
#include <limits.h>
#include <math.h>
using namespace std;

struct close
{
    int x, y;
};

int func(int closenessx1, int closenessy1, int closenessx2, int closenessy2, int constant)
{
    int result = pow(abs(closenessx1 - closenessx2), constant) + pow(abs(closenessy1 - closenessy2), constant);
    return result;
}

int main()
{
    int student, constant;
    int max = -1;
    int min = INT_MAX;
    int result = 0;
    scanf("%d %d", &student, &constant);

    close data[student];
    for (int i = 0; i < student; i++)
    {
        scanf("%d %d", &data[i].x, &data[i].y);
        for (int x = i - 1; x >= 0; x--)
        {
            result = func(data[i].x, data[i].y, data[x].x, data[x].y, constant);
            if (result > max)
                max = result;
            if (result < min)
                min = result;
        }
    }
    printf("%d %d\n", min, max);
    return 0;
}
