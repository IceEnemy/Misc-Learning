#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct housingdata
{
    char loc1[110];
    char loc2[110];
    int price;
    int rooms;
    int bathroom;
    int carparks;
    char type[110];
    int area;
    char furnish[110];
};

void printMenu()
{
    printf("Choose what to look up:\n");
    printf(">> loc1\n");
    printf(">> loc2\n");
    printf(">> price\n");
    printf(">> room\n");
    printf(">> bathroom\n");
    printf(">> carpark\n");
    printf(">> furnish\n\n");

    printf("Enter in this format = ... in ...\n");
    printf("Search : ");
}

int main()
{
    FILE *bellefile = fopen("file.csv", "r");
    char discard[1100];
    fscanf(bellefile, "%[^\n]\n", discard);

    housingdata data[3950];
    int i = 0;
    while (!feof(bellefile))
    {
        fscanf(bellefile, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", data[i].loc1, data[i].loc2, &data[i].price, &data[i].rooms, &data[i].bathroom, &data[i].carparks, data[i].type, &data[i].area, data[i].furnish);
        i++;
    }

    char findcondition[110];
    char finddata[110];
    printMenu();
    scanf("%s in %s", findcondition, finddata);
    getchar();

    if (strcmp(finddata, "loc1") == 0)
    {
        int q = 0;
        while (q < i)
        {
            printf("| %-20s |%-15s | %-10d | %-2d | %-2d | %-2d | %-10s | %-2d |%-15s|\n", data[q].loc1, data[q].loc2, data[q].price, data[q].rooms, data[q].bathroom, data[q].carparks, data[q].type, data[q].area, data[q].furnish);
            q++;
        }
    }
    else if (strcmp(finddata, "loc2") == 0)
    {
        int q = 0;
        while (q < i)
        {
            printf("| %-20s |%-15s | %-10d | %-2d | %-2d | %-2d | %-10s | %-2d |%-15s|\n", data[q].loc1, data[q].loc2, data[q].price, data[q].rooms, data[q].bathroom, data[q].carparks, data[q].type, data[q].area, data[q].furnish);
            q++;
        }
    }
    else if (strcmp(finddata, "price") == 0)
    {
        int q = 0;
        while (q < i)
        {
            printf("| %-20s |%-15s | %-10d | %-2d | %-2d | %-2d | %-10s | %-2d |%-15s|\n", data[q].loc1, data[q].loc2, data[q].price, data[q].rooms, data[q].bathroom, data[q].carparks, data[q].type, data[q].area, data[q].furnish);
            q++;
        }
    }
    else if (strcmp(finddata, "rooms") == 0)
    {
        int q = 0;
        while (q < i)
        {
            printf("| %-20s |%-15s | %-10d | %-2d | %-2d | %-2d | %-10s | %-2d |%-15s|\n", data[q].loc1, data[q].loc2, data[q].price, data[q].rooms, data[q].bathroom, data[q].carparks, data[q].type, data[q].area, data[q].furnish);
            q++;
        }
    }
    else if (strcmp(finddata, "bathrooms") == 0)
    {
        int q = 0;
        while (q < i)
        {
            printf("| %-20s |%-15s | %-10d | %-2d | %-2d | %-2d | %-10s | %-2d |%-15s|\n", data[q].loc1, data[q].loc2, data[q].price, data[q].rooms, data[q].bathroom, data[q].carparks, data[q].type, data[q].area, data[q].furnish);
            q++;
        }
    }
    else if (strcmp(finddata, "carparks") == 0)
    {
        int q = 0;
        while (q < i)
        {
            printf("| %-20s |%-15s | %-10d | %-2d | %-2d | %-2d | %-10s | %-2d |%-15s|\n", data[q].loc1, data[q].loc2, data[q].price, data[q].rooms, data[q].bathroom, data[q].carparks, data[q].type, data[q].area, data[q].furnish);
            q++;
        }
    }
    else if (strcmp(finddata, "furnish") == 0)
    {
        int q = 0;
        while (q < i)
        {
            printf("| %-20s |%-15s | %-10d | %-2d | %-2d | %-2d | %-10s | %-2d |%-15s|\n", data[q].loc1, data[q].loc2, data[q].price, data[q].rooms, data[q].bathroom, data[q].carparks, data[q].type, data[q].area, data[q].furnish);
            q++;
        }
    }
    else
    {
        printf("No data is found\n");
    }

    fclose(bellefile);
    return 0;
}

