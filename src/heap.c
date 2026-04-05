#include "heap.h"
#include "utils.h"
#include <stdlib.h>

void insert(heap *heap, int value) {
    if (heap->count >= heap->capacity - 1) {
        if (heap->count == 0) {
            heap->capacity = 2;
        } else {
            heap->capacity *= 2;
        }

        heap->values = realloc(heap->values, heap->capacity * sizeof(int));
    }

    heap->count++;
    heap->values[heap->count] = value;

    for (int index = heap->count;
         index > 1 && heap->values[index] > heap->values[index / 2];
         index /= 2) {

        int temp = heap->values[index / 2];
        heap->values[index / 2] = heap->values[index];
        heap->values[index] = temp;
    }
}

int extract_max(heap *heap) {
    if (heap->count == 0) {
        return -1;
    }

    int max = heap->values[1];
    heap->values[1] = heap->values[heap->count - 1];
    heap->count--;

    int index = 1;

    while (2 * index <= heap->count) {
        if (heap->values[index] < heap->values[index * 2]) {
            int temp = heap->values[index];
            heap->values[index] = heap->values[2 * index];
            heap->values[2 * index] = temp;
            index = 2 * index;
        } else {
            int temp = heap->values[index];
            heap->values[index] = heap->values[2 * index + 1];
            heap->values[2 * index + 1] = temp;
            index = 2 * index + 1;
        }
    }

    return max;
}
