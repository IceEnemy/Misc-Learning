#include <stdio.h>
#include <string.h>
// int main()
// {
//     FILE *bellefile = fopen("testdata.in", "w");
//     fclose(bellefile);

//     return 0;
// }

struct weatherdata
{
    char city[1100];
    double temp;
    char type;
};

void merge_sort(struct weatherdata data[], int left, int right);
void merge(struct weatherdata data[], int left, int middle, int right);

void merge_sort(struct weatherdata data[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        merge_sort(data, left, middle);
        merge_sort(data, middle + 1, right);

        merge(data, left, middle, right);
    }
}

void merge(struct weatherdata data[], int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    struct weatherdata left_temp[left_length];
    struct weatherdata right_temp[right_length];

    int left_counter = 0;
    int right_counter = 0;
    int data_counter = left;

    for (int i = 0; i < left_length; i++)
    {
        left_temp[i] = data[left + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        right_temp[i] = data[middle + 1 + i];
    }

    while (left_counter < left_length && right_counter < right_length)
    {
        if (left_temp[left_counter].temp < right_temp[right_counter].temp)
        {
            data[data_counter++] = left_temp[left_counter++];
        }
        else if (left_temp[left_counter].temp == right_temp[right_counter].temp)
        {
            if (strcmp(left_temp[left_counter].city, right_temp[right_counter].city) < 0)
            {
                data[data_counter++] = left_temp[left_counter++];
            }
            else
            {
                data[data_counter++] = right_temp[right_counter++];
            }
        }
        else
        {
            data[data_counter++] = right_temp[right_counter++];
        }
    }

    while (left_counter < left_length)
    {
        data[data_counter++] = left_temp[left_counter++];
    }

    while (right_counter < right_length)
    {
        data[data_counter++] = right_temp[right_counter++];
    }
}

void convertFtoC(double *temp, char type)
{
    if (type == 'F')
    {
        *temp = (*temp - 32) * 5 / 9;
    }
}

void convertCtoF(double *temp, char type)
{
    if (type == 'F')
    {
        *temp = (*temp * 9 / 5) + 32;
    }
}

int main()
{
    FILE *bellefile = fopen("testdata.in", "r");

    struct weatherdata data[1100];

    int counter = 0;
    while (fscanf(bellefile, "%[^#]#%lf#%c\n", data[counter].city, &data[counter].temp, &data[counter].type) != EOF)
    {
        convertFtoC(&data[counter].temp, data[counter].type);
        counter++;
    }

    merge_sort(data, 0, counter - 1);

    for (int x = 0; x < counter; x++)
    {
        convertCtoF(&data[x].temp, data[x].type);
        printf("%s is %.2lf%c\n", data[x].city, data[x].temp, data[x].type);
    }

    fclose(bellefile);
    return 0;
}
