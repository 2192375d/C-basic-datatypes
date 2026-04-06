#include "internal/fibonacci_heap_node.h"
#include "utils.h"
#include <stdlib.h>

Fibonacci_Heap_Node *
fibonacci_heap_node_remove_family(Fibonacci_Heap_Node *node);

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
                                   Fibonacci_Heap_Node *new_sibling) {

    if (!source) {
        return new_sibling;
    }

    new_sibling = fibonacci_heap_node_remove_family(new_sibling);

    if (!source->right_sibling) {
        source->right_sibling = new_sibling;
        new_sibling->left_sibling = source;
        return source;
    }

    else if (!source->left_sibling) {
        source->left_sibling = new_sibling;
        new_sibling->right_sibling = source;
        return source;
    }

    Fibonacci_Heap_Node *temp_node = source->right_sibling;
    source->right_sibling = new_sibling;
    new_sibling->left_sibling = source;
    new_sibling->right_sibling = temp_node;
    temp_node->left_sibling = new_sibling;

    return source;
}

Fibonacci_Heap_Node *
fibonacci_heap_node_get_leftmost(Fibonacci_Heap_Node *source) {
    if (source == NULL) {
        return NULL;
    }

    while (source->left_sibling != NULL) {
        source = source->left_sibling;
    }
    return source;
}

Fibonacci_Heap_Node *
fibonacci_heap_node_remove_family(Fibonacci_Heap_Node *node) {
    node->left_sibling = NULL;
    node->right_sibling = NULL;
    node->parent = NULL;
    return node;
}

// returns a bundle of the poped node and the doubly linked list after poping
Fibonacci_Heap_Pop_Group
fibonacci_heap_node_pop_self(Fibonacci_Heap_Node *node) {

    ds_assert(node, "fibonacci_heap_node_pop_self",
              "input node has nothing to be popped");
    Fibonacci_Heap_Pop_Group pop_group;
    pop_group.node = node;

    if (!node->left_sibling && !node->right_sibling) {
        pop_group.node_list = NULL;
        pop_group.node = fibonacci_heap_node_remove_family(pop_group.node);
        return pop_group;
    }

    else if (!node->right_sibling) {
        pop_group.node_list = node->left_sibling;
        pop_group.node_list->right_sibling = NULL;
        pop_group.node = fibonacci_heap_node_remove_family(pop_group.node);
        return pop_group;
    } else if (!node->left_sibling) {
        pop_group.node_list = node->right_sibling;
        pop_group.node_list->left_sibling = NULL;
        pop_group.node = fibonacci_heap_node_remove_family(pop_group.node);
        return pop_group;
    }
    pop_group.node_list = node->left_sibling;
    pop_group.node_list->right_sibling = node->right_sibling;
    node->right_sibling->left_sibling = pop_group.node_list;
    pop_group.node = fibonacci_heap_node_remove_family(pop_group.node);
    return pop_group;
}
