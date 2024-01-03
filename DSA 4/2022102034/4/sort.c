#include "sort.h"

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void shellsort(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i;
            int k = i - gap;
            while (k >= 0)
            {
                if (arr[j] < arr[k])
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
