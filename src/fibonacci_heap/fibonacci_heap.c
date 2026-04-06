#include "fibonacci_heap.h"
#include "fibonacci_heap_node.h"
#include <stdlib.h>

Fibonacci_Heap *fibonacci_heap_create(print_fn print) {
    Fibonacci_Heap *new_heap = (Fibonacci_Heap *)malloc(sizeof(Fibonacci_Heap));

    if (new_heap == NULL) {
        return NULL;
    }

    new_heap->print = print;
    new_heap->min_node = NULL;

    return new_heap;
}

Fibonacci_Heap *fibonacci_heap_insert(Fibonacci_Heap *heap, int priority,
                                      void *value) {

    Fibonacci_Heap_Node *new_node = fibonacci_heap_node_create(priority, value);
    if (!heap->min_node) {
        if (!new_node) {
            return NULL;
        }

        heap->min_node = new_node;
        return heap;
    }

    heap->min_node =
        fibonacci_heap_node_insert_sibling(heap->min_node, new_node);
    if (heap->min_node->priority < new_node->priority) {
        heap->min_node = new_node;
    }

    return heap;
}
