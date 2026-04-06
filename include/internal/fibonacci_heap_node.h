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

typedef struct Fibonacci_Heap_Pop_Group_Struct {
    Fibonacci_Heap_Node *node;
    Fibonacci_Heap_Node *node_list;
} Fibonacci_Heap_Pop_Group;

// creates a new heap node, with priority and value
Fibonacci_Heap_Node *fibonacci_heap_node_create(int priority, void *value);

// inserts a heap node to the current doubly linked list, detach original
// parent, siblings of the new sibling node. But child remains
Fibonacci_Heap_Node *
fibonacci_heap_node_insert_sibling(Fibonacci_Heap_Node *source,
                                   Fibonacci_Heap_Node *sibling);

// returns the leftmost node on the current doubly linked list
Fibonacci_Heap_Node *
fibonacci_heap_node_get_leftmost(Fibonacci_Heap_Node *source);

Fibonacci_Heap_Pop_Group
fibonacci_heap_node_pop_self(Fibonacci_Heap_Node *node);

#endif
