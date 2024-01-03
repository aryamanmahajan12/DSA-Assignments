#ifndef heap_h
#define heap_h

typedef struct HeapStruct
{
    long long int capacity;
    long long int size;
    long long int *elements;
} heap;

typedef struct HeapStruct *PriorityQueue;

void swap(long long int *a, long long int *b);
PriorityQueue Initialize(long long int maxelements);
int isempty(PriorityQueue h);
void percoulateup(PriorityQueue h, int i);
void INsert(PriorityQueue h, long long int x);
void heapify(PriorityQueue h, int i);
long long int DeleteMin(PriorityQueue h);


#endif