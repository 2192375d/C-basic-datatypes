#include "fibonacci_heap_node.h"
#include "../utils.h"
#include <stdlib.h>

Fibonacci_Heap_Node *fibonacci_heap_node_create(int priority, void *value) {

    Fibonacci_Heap_Node *new_node =
        (Fibonacci_Heap_Node *)malloc(sizeof(Fibonacci_Heap_Node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->priority = priority;
    new_node->value = value;
    new_node->degree = 0;
    new_node->marked = false;
    new_node->left_sibling = NULL;
    new_node->right_sibling = NULL;
    new_node->child = NULL;
    new_node->parent = NULL;

    return new_node;
}

Fibonacci_Heap_Node *
fibonacci_heap_node_insert_sibling(Fibonacci_Heap_Node *source,
                                   Fibonacci_Heap_Node *sibling) {

    if (!source) {
        ds_assert("source node does not exist");
    }
    if (!source->right_sibling) {
        source->right_sibling = sibling;
        sibling->left_sibling = source;
        return source;
    }

    else if (!source->left_sibling) {
        source->left_sibling = sibling;
        sibling->right_sibling = source;
        return source;
    }

    Fibonacci_Heap_Node *temp_node = source->right_sibling;
    source->right_sibling = temp_node;
    temp_node->left_sibling = source;

    return source;
}
