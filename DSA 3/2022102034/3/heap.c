#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

void swap(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}


PriorityQueue Initialize(long long int maxelements)
{
    PriorityQueue H;

    if (maxelements < 0)
    {
        printf("Size too small\n");
        return NULL;
    }

    H = (PriorityQueue)malloc(sizeof(heap));
    assert(H != NULL);

    H->elements = malloc((maxelements + 1) * (sizeof(long long int)));
    assert(H->elements != NULL);

    H->capacity = maxelements;
    H->size = 0;

    return H;
}

int isempty(PriorityQueue h)
{
    if (h->size == 0)
        return 1;
    return 0;
}
void percoulateup(PriorityQueue h, int i)
{
    int parent = (i - 1) / 2;
    if (i > 0 && h->elements[parent] > h->elements[i])
    {
        swap(&h->elements[parent], &h->elements[i]);
        percoulateup(h, parent);
    }
}
void INsert(PriorityQueue h, long long int x)
{
    h->elements[h->size] = x;
    h->size++;
    percoulateup(h, h->size - 1);
}


void heapify(PriorityQueue h, int i)
{
    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < h->size && h->elements[l] < h->elements[i])
    {
        min = l;
    }
    if (r < h->size && h->elements[r] < h->elements[i])
    {
        min = r;
    }
    if (i != min)
    {
        swap(&h->elements[i], &h->elements[min]);
        heapify(h, min);
    }
}

long long int DeleteMin(PriorityQueue h)
{
    long long int min = h->elements[0];
    swap(&h->elements[0], &h->elements[h->size - 1]);
    h->size--;
    heapify(h, 0);
    return min;
}
