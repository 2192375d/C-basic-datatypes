#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H

typedef struct heap_struct {
    int *values;
    int count;
    int capacity;
} heap;

void insert(heap *heap, int value);
int extract_max(heap *heap);

#endif
