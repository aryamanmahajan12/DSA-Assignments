#include "sort.h"

int main()
{
    int testcases;
    scanf("%lld", &testcases);

    for (int i = 0; i < testcases; i++)
    {
        int k, m;
        /*k = no. of schools, kth school ot jth school will be yth school. Mth student will be Xth student.*/

        scanf("%lld %lld", &k, &m);

        int arr[m][k];

        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < k; y++)
            {
                scanf("%lld", &arr[x][y]);
            }
        }
        int l;
        scanf("%lld", &l);
        int j = l - 1;
        int a[m]; // students of jth school
        int b[m]; // maximum elements amongst all other schools in order
        for (int p = 0; p < m; p++)
        {
            a[p] = arr[p][j];
            arr[p][j] = -2;
        }
        int max = -1;
        for (int p = 0; p < m; p++)
        {
            max = -1; // Reset max for each iteration
            for (int g = 0; g < k; g++)
            {
                if (arr[p][g] > max)
                    max = arr[p][g];
            }
            b[p] = max;
        }
        shellsort(a, m); // sorted elements of jth school
        shellsort(b, m); // sorted max elements of other schools

        // for (int i = 0; i < m; i++)
        //     printf("%lld ", a[i]);
        // printf("\n");

        // for (int i = 0; i < m; i++)
        //     printf("%lld ", b[i]);
        // printf("\n");

        int count = 0;
        int klo = 0;
        for (int i = 0; i < m; i++)
        {
            while (klo < m)
            {
                if (a[klo] > b[i])
                {
                    klo++;
                    count++;
                    break;
                }
                else
                {
                    klo++;
                }
            }
        }

        // int flag[m];
        // for (int i = 0; i < m; i++)
        // {
        //     flag[i] = 0;
        // }

        // for (int i = 0; i < m; i++)
        // {
        //     if (flag[i] == 0)
        //     {

        //         if (a[i] > b[i])
        //         {
        //             flag[i] = 1;
        //             count++;
        //             continue;
        //         }
        //         else
        //         {
        //             int j = i + 1;
        //             while (j < m)
        //             {
        //                 if (a[j] > b[i])
        //                 {
        //                     if (flag[j] == 0)
        //                     {
        //                         count++;
        //                         flag[j] = 1;
        //                         break;
        //                     }
        //                 }
        //                 j++;
        //             }
        //             if (j >= m)
        //                 break;
        //         }
        //     }
        // }
        printf("%lld\n", count);
    }
    return 0;
}