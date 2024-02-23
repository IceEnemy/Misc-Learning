#include <stdio.h>

struct studentdata
{
    char name[20];
    int score;
};

void merge_sort(struct studentdata data[], int left, int right);
void merge(struct studentdata data[], int left, int middle, int right);

void merge_sort(struct studentdata data[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        merge_sort(data, left, middle);
        merge_sort(data, middle + 1, right);

        merge(data, left, middle, right);
    }
}

void merge(struct studentdata data[], int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    struct studentdata left_temp[left_length];
    struct studentdata right_temp[right_length];

    int left_count = 0;
    int right_count = 0;
    int data_count = left;

    for (int i = 0; i < left_length; i++)
    {
        left_temp[i] = data[left + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        right_temp[i] = data[middle + 1 + i];
    }

    while (left_count < left_length && right_count < right_length)
    {
        if (left_temp[left_count].score > right_temp[right_count].score)
        {
            data[data_count++] = left_temp[left_count++];
        }
        else
        {
            data[data_count++] = right_temp[right_count++];
        }
    }

    while (left_count < left_length)
    {
        data[data_count++] = left_temp[left_count++];
    }

    while (right_count < right_length)
    {
        data[data_count++] = right_temp[right_count++];
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    struct studentdata data[1100];

    int student;
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &student);
        getchar();

        for (int x = 0; x < student; x++)
        {
            scanf("%[^#]#%d", data[x].name, &data[x].score); getchar();
            // printf("%s %d\n", data[x].name, data[x].score);
        }

        merge_sort(data, 0, student - 1);

        for (int x = 0; x < student; x++)
        {
            printf("%s %d\n",data[x].name, data[x].score);
        }
    }

    return 0;
}
