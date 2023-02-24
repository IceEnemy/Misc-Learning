#include<bits/stdc++.h>
using namespace std;

const int maxN=100;
int sum[maxN+2];

void precomp()
{
    memset(sum, 0, sizeof(sum));
    for(int i=1;i<=maxN;i++)
    {
        printf("[%d].\n", i);
        for(int j=1;j<=i;j++)
        {
            int temp=i/__gcd(i,j);
            printf("%d ", temp);
            sum[i]+=temp;
        }
        printf("\n%d\n", sum[i]);
    }
}

int main()
{
    precomp();
    return 0;
}

