#include "sort.h"

/*make heap for all the elements. Now keep taking the maximum element inside a k-loop
and keep decrementing the element every time you use it.Heapify again.*/

/*Heap is basically an array only. */


int main()
{
    int testcases;
    scanf("%lld", &testcases);

    for (int x = 0; x < testcases; x++)
    {
        int n, k;
        scanf("%lld %lld", &n, &k);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        int sum = 0;

        // reverse ( arr, n, n-1);
        // for ( int i=0; i<n;i++){
        //     printf ( "%lld ", arr[i]);
        // }

        shellsort ( arr, n);
        for (int j = 0; j < k; j++)
        {
            int index = findmax(arr, n);
            sum += arr[index];

            // for ( int i=0; i<n;i++){
            //     printf ( "%lld ", arr[i]);
            // }
            // printf ("\n");

            if ( arr[index] > 0)
                arr[index]--;
            



        }
        printf("%lld\n", sum);
    }
    return 0;
}