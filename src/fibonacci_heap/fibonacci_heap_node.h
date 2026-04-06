#ifndef FIBONACCI_HEAP_NODE_H
#define FIBONACCI_HEAP_NODE_H

#include <stdbool.h>

typedef struct Fibonacci_Heap_Node_Struct {
    int priority;
    void *value;
    int degree;
    bool marked;
    struct Fibonacci_Heap_Node_Struct *parent;
    struct Fibonacci_Heap_Node_Struct *left_sibling;
    struct Fibonacci_Heap_Node_Struct *right_sibling;
    struct Fibonacci_Heap_Node_Struct *child;
} Fibonacci_Heap_Node;

Fibonacci_Heap_Node *fibonacci_heap_node_create(int priority, void *value);

Fibonacci_Heap_Node *
fibonacci_heap_node_insert_sibling(Fibonacci_Heap_Node *source,
                                   Fibonacci_Heap_Node *sibling);

#endif
