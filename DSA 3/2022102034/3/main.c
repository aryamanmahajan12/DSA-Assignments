#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int a[n];
    PriorityQueue H;
    long long int k;
    H = Initialize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    long long int sum = 0;
    int knobs = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            INsert(H, a[i]);
        }
        sum += a[i];
        knobs++;

        if (sum < 0)
        {
            long long int x = DeleteMin(H);
            sum = sum - x;
            knobs--;
        }
    }
    printf("%d\n", knobs);
    return 0;
}