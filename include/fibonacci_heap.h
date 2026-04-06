
/**
 * @file fibonacci_heap.h
 * @brief fibonacci heap library
 */

#ifndef FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_H

#include "internal/fibonacci_heap_node.h"
#include <stdbool.h>

typedef void (*print_fn)(void *);

typedef struct Fibonacci_Heap_Entry_Struct {
    int priority;
    void *value;
} Fibonacci_Heap_Entry;

typedef struct Fibonacci_Heap_Struct {
    print_fn print;
    int num_node;
    Fibonacci_Heap_Node *min_node;
} Fibonacci_Heap;

/**
 * creates a new fibonacci heap, min_node set to NULL
 *
 * @param print the funciton pointing to the printing function of the nodes in
 *              the heap
 *
 * @return the new heap
 */
Fibonacci_Heap *fibonacci_heap_create(print_fn print);

/**
 * inserts a node in the input fibonacci heap
 *
 * @param heap the fibonacci heap to insert to
 * @param priority the priority of the new heap node
 * @param value the value of the new heap node
 *
 * @return the fibonacci heap after insertion
 */
Fibonacci_Heap *fibonacci_heap_insert(Fibonacci_Heap *heap, int priority,
                                      void *value);
/**
 * union two fibonacci heaps
 *
 * @param heap1 first heap to union
 * @param heap2 second heap to union
 *
 * @return the fibonacci heap after union
 */
Fibonacci_Heap *fibonacci_heap_union(Fibonacci_Heap *heap1,
                                     Fibonacci_Heap *heap2);

Fibonacci_Heap_Entry fibonacci_heap_extract_min(Fibonacci_Heap *heap);

#endif
