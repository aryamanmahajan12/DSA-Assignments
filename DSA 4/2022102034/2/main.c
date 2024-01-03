#include "sort.h"

int main()
{
    int testcases;
    scanf("%d", &testcases);

    for (int x = 0; x < testcases; x++)
    {
        int n;
        scanf("%d", &n);

        num arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i].x);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i].y);
        }

        shellsort(&arr[0], n);

        int max = findmin(arr[0].x, arr[0].y);

        for (int i = 1; i < n; i++)
        {
            if (arr[i].y < arr[i].x)
            {
                if (arr[i].y >= max)
                {
                    max = arr[i].y;
                }
                else
                {
                    max = arr[i].x;
                }
            }
            else
            {
                if (arr[i].x >= max)
                {
                    max = arr[i].x;
                }
                else
                {
                    max = arr[i].y;
                }
            }
        }
        printf("%d %d\n", arr[n - 1].x, max);
    }
    return 0;
}



