#include <stdio.h>
#include <stdlib.h>
struct num
{
    int x;
    int y;
};
typedef struct num num;

void swap(num *a, int i, int j);
int comp(num a, num b);
void shellsort(num *arr, int n);
int findmin(int a, int b);
