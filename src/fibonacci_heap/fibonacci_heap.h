
/**
 * @file fibonacci_heap.h
 * @brief fibonacci heap library
 */

#ifndef FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_H

#include "fibonacci_heap_node.h"
#include <stdbool.h>

typedef void (*print_fn)(void *);

typedef struct Fibonacci_Heap_Struct {
    print_fn print;
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

#endif
