#ifndef Heap_h
#define Heap_h

void swap(int *a, int i, int j);
int median(int *a, int lower, int upper);
int Qpartition(int *a, int l, int u, int pivot_val);
void QS(int *a, int lower, int upper);


#endif