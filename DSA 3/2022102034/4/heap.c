#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Heap.h"

void swap(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int median(int *a, int lower, int upper)
{
    int mid = (lower + upper) / 2;

    if (a[lower] > a[mid])
        swap(a, lower, mid);
    if (a[lower] > a[upper])
        swap(a, lower, upper);
    if (a[mid] > a[upper])
        swap(a, mid, upper);

    swap(a, mid, upper);

    return a[upper];
}

int Qpartition(int *a, int l, int u, int pivot_val)
{
    int i = l - 1;

    for (int j = l; j < u; j++)
    {
        if (a[j] < pivot_val)
        {
            i++;
            swap(a, i, j);
        }
    }

    swap(a, i + 1, u);

    return i + 1;
}

void QS(int *a, int lower, int upper)
{
    if (lower < upper)
    {
        int pivot_val = median(a, lower, upper);
        int pivot_indx_final = Qpartition(a, lower, upper, pivot_val);
        QS(a, lower, pivot_indx_final - 1);
        QS(a, pivot_indx_final + 1, upper);
    }
}