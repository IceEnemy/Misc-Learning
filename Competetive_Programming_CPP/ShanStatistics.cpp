#include <stdio.h>

int main ()
{
    int t;
    scanf("%d", &t);
    int size;
    int mid;
    double mean;
    
    for(int i = 1; i <= t; i++)
    {
        scanf("%d", &size);
        double num[size];
        double total = 0;
        
        for(int j = 0; j < size; j++)
        {
            scanf("%lf", &num[j]);
            total+=num[j];
        }
        
        for(int m = 0; m < size-1; m++)
        {
            for(int n = 0; n < size - m - 1; n++)
            {
                if(num[n] > num[n+1])
                {
                    double temp = num[n];
                    num[n] = num[n+1];
                    num[n+1] = temp;
                }
            }
        }
//        for(int j=0;j<size;j++){
//        	printf("%lf ",num[j]);
//		}
//		printf("\n");
        
        
//        for(int k = 0; k < size; k++)
//        {
//            total += num[k];
//        }
//        printf("%lf\n",total);
    
//        for(int d = 0; d < size-1; d++)
//        {
         
            if(size % 2 == 1)
            {
                mid = size/2;
            }
            else
            {
                mid = (size/2)-1;
            }
//        }
//        printf("%d\n",mid);
    
        mean = total/size;
    
        if(size % 2 == 1)
        {
            printf("Case #%d:\n", i);
            printf("Mean : %.2lf\n", mean);
            printf("Median : %.2lf\n", num[mid]);
        }
        else{
            printf("Case #%d:\n", i);
            printf("Mean : %.2lf\n", mean);
            printf("Median : %.2lf\n", (num[mid] + num[mid+1])/2);
        }
    }
    return 0;
}

