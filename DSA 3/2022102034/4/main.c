#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"


int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        arr[i] = a[i];
    }
    if (n == 1)
    {
        printf("%d\n", a[0]);
    }

    else
    {
        QS(a, 0, n - 1);
        // for(int i =0;i<n;i++)
        // {
        //     printf("%d ", a[i]);
        // }
        // printf("\n");
        int k = 0;
        int temp;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == arr[k])
            {
                temp = a[j];
                if (j + 1 != n)
                {
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }

                if(j+1==n)
                {
                    a[j]=a[j-1];
                    a[j-1]=temp;
                }
            }
            k++;
        }

        //         if (m == n)
        //         {
        //         }
        //         else
        //         {
        //             temp[m] = -1;
        //         }

        //         if (m % 2 == 0)
        //         {
        //             int t;
        //             for (int l = 0; l < m; l ++)
        //             {
        //                 t = a[temp[l]];
        //                 a[temp[l]] = a[temp[l]+1];
        //                 a[temp[l]+1] = t;
        //             }
        //         }

        //         else if (m % 2 != 0)
        //         {
        //             int f;
        //             for (int l = 0; l < m; l ++)
        //             {
        //                 f = a[temp[l]];
        //                 if (l != m - 1)
        //                 {
        //                     a[temp[l]] = a[temp[l]+1];
        //                     a[temp[l]+1] = f;
        //                 }
        //                 if (l == m - 1 && l - 1 > 0)
        //                 {
        //                     a[temp[l]] = a[temp[l]-1];
        //                     a[temp[l]-1] = f;
        //                 }
        //                 else if (m == 1)
        //                 {
        //                     if (temp[l] + 1 != n)
        //                     {
        //                         a[temp[l]] = a[temp[l] + 1];
        //                         a[temp[l] + 1] = f;
        //                     }
        //                     if (temp[l] - 1 != n && temp[l] + 1 == n)
        //                     {
        //                         a[temp[l]] = a[temp[l] - 1];
        //                         a[temp[l] - 1] = f;
        //                     }
        //                 }
        //             }
        //         }

                for (int x = 0; x < n; x++)
                {
                    printf("%d ", a[x]);
                }
                printf("\n");
            }
            return 0;
        }
