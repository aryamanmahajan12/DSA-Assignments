#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void swap(num *a, int i, int j)
{
    num temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int comp(num a, num b)
{
    if (a.x < b.x)
        return 1;
    if (a.x > b.x)
        return 0;

    return a.y < b.y;
}

void shellsort(num *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i;
            int k = i - gap;
            while (k >= 0)
            {
                // if ( arr[j] < arr[k]){
                if (comp(arr[j], arr[k]))
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

int findmin(int a, int b)
{
    if (a < b)
        return a;

    else
        return b;
}