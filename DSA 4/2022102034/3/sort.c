#include "sort.h"

void swap(char **a, int i, int j)
{
    char *temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int comparator(char *a, char *b)
{
    int different_index = 1;
    int i = 0;
    int diff_flag = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
        {
            diff_flag = 1;
            break;
        }
        i++;
        different_index++;
    }
    if (diff_flag == 1)
    {
        if (different_index % 2 == 1 && a[i] < b[i])
            return 0;
        else if (different_index % 2 == 0 && a[i] > b[i])
            return 0;
    }
    if (diff_flag == 0)
    {
        if (different_index % 2 == 0 && a[i] == '\0')
            return 0;
        else if (different_index % 2 == 1 && b[i] == '\0')
            return 0;
    }
    return 1;
}

void shellsort(char **arr, int n)
{
    int flag;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i;
            int k = i - gap;
            while (k >= 0)
            {
                if (j % 2 == 0)
                    flag = 1;
                if (j % 2 != 0)
                    flag = 0;

                if (comparator(arr[j], arr[k]))
                {
                    swap(arr, j, k);
                }
                else
                {
                    break;
                }
                j -= gap;
                k -= gap;
            }
        }
    }
}