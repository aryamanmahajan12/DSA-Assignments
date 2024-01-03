#include "sort.h"

void swap ( int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void shellsort (int* arr, int n){
    for ( int gap = n/2; gap>0; gap/=2){
        for ( int i=0; i<n; i++){
            int j = i;
            int k = i- gap;
            while ( k >= 0){
                if ( arr[j] < arr[k]){
                    swap ( arr, j, k);
                }
                else {
                    break;
                }
                j -= gap;
                k -= gap;
            }
        }
    }
}

void reverse ( int* arr, int n, int k){
    if ( k < 2)
        return;
    int temp_arr[k];
    for ( int i=0; i<k; i++){
        temp_arr[i] = arr[n-1-i];
    }
    for ( int i=0; i<k; i++){
        arr[n-k+i] = temp_arr[i];
    }
}

int findmax(int *arr, int n)
{   
    int temp;
    if ( n < 2)
        return 0;
    int count  = 1;

    if ( !arr[1] && !arr[2] && !arr[3] && !arr[4] && !arr[5])
        temp=0;

    while ((n-1-count) >= 0){
        if (arr[n-count] > arr[n-1-count])
            break;
        count++;
    }

    reverse ( arr, n, count);
    int max = n-1;
    return max;
}