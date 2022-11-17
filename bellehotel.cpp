#include <stdio.h>
int main(){
    int room; 
    scanf("%d", &room);
    int number[room];

    for(int i = 0; i < room; i++)
    {
        scanf("%d", &number[i]);
    }

    int counter = 0;
    for(int x = 0; x < room; x++)
    {
        for(int j = x + 1; j < room; j++)
        {
            if(number[x] == number[j])
            {
                counter++;
            }
        }
    }
    printf("%d\n", room - counter);
    return 0;
}

