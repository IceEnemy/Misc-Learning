#include <stdio.h>

long long counter;

int main()
{
    int i;
    counter = 0;
    for(i = 1; i <= 80; i++) {
        int j;
        for (j = 1; j <= i; j++) {
            counter++;
        }
        for(int k=1; k<=(i-2); k++){
            counter++;
        }
    }
    printf("%lld\n", counter);
    return 0;
}
