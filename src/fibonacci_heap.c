#include "fibonacci_heap.h"
#include "internal/fibonacci_heap_node.h"
#include "utils.h"
#include <stdlib.h>

Fibonacci_Heap *fibonacci_heap_create(print_fn print) {
    Fibonacci_Heap *new_heap = (Fibonacci_Heap *)malloc(sizeof(Fibonacci_Heap));

    if (new_heap == NULL) {
        return NULL;
    }

    new_heap->print = print;
    new_heap->num_node = 0;
    new_heap->min_node = NULL;

    return new_heap;
}

Fibonacci_Heap *fibonacci_heap_insert(Fibonacci_Heap *heap, int priority,
                                      void *value) {
    ds_assert(!heap, "fibonacci_heap_insert", "heap is NULL");

    heap->num_node++;

    // if no node inside, insert as min_node
    Fibonacci_Heap_Node *new_node = fibonacci_heap_node_create(priority, value);
    if (!heap->min_node) {
        if (!new_node) {
            return NULL;
        }

        heap->min_node = new_node;
        return heap;
    }

    // if some node inside, insert as sibling of root
    heap->min_node =
        fibonacci_heap_node_insert_sibling(heap->min_node, new_node);
    if (heap->min_node->priority < new_node->priority) {
        heap->min_node = new_node;
    }

    return heap;
}

Fibonacci_Heap *fibonacci_heap_union(Fibonacci_Heap *heap1,
                                     Fibonacci_Heap *heap2) {

    ds_assert(!heap1 || !heap2, "fibonacci_heap_union",
              "input heap cannot be NULL");

    if (heap1->num_node < heap2->num_node) {
        return fibonacci_heap_union(heap2, heap1);
    }

    // now it has to be the case that heap1.size >= heap2.size
    if (heap1->min_node == NULL) {
        return NULL;
    }
    if (heap2->min_node == NULL) {
        return heap1;
    }

    Fibonacci_Heap_Node *temp_node =
        fibonacci_heap_node_get_leftmost(heap2->min_node);

    while (temp_node != NULL) {
        heap1->min_node =
            fibonacci_heap_node_insert_sibling(heap1->min_node, temp_node);
        temp_node = temp_node->right_sibling;
    }

    return heap1;
}

Fibonacci_Heap_Entry fibonacci_heap_extract_min(Fibonacci_Heap *heap) {
    ds_assert(!heap || !heap->min_node, "fibonacci_heap_extract_min",
              "invalid input heap");

    Fibonacci_Heap_Entry min_heap_entry;
    min_heap_entry.priority = heap->min_node->priority;
    min_heap_entry.value = heap->min_node->value;

    Fibonacci_Heap_Pop_Group pop_group =
        fibonacci_heap_node_pop_self(heap->min_node);

    Fibonacci_Heap_Node *iterator_node;
    Fibonacci_Heap_Node *next_node;

    heap->num_node--;
    heap->min_node = pop_group.node_list;

    iterator_node = fibonacci_heap_node_get_leftmost(pop_group.node->child);

    while (iterator_node != NULL) {
        next_node = iterator_node->right_sibling;
        iterator_node = fibonacci_heap_node_pop_self(iterator_node).node;
        iterator_node->parent = NULL;
        heap->min_node =
            fibonacci_heap_node_insert_sibling(heap->min_node, iterator_node);
        iterator_node = next_node;
    }

    free(pop_group.node);

    if (heap->min_node == NULL) {
        return min_heap_entry;
    }

    iterator_node = fibonacci_heap_node_get_leftmost(heap->min_node);
    heap->min_node = NULL;

    Fibonacci_Heap_Node *degree_array[heap->num_node + 1];
    for (int i = 0; i <= heap->num_node; i++) {
        degree_array[i] = NULL;
    }

    while (iterator_node != NULL) {
        next_node = iterator_node->right_sibling;
        Fibonacci_Heap_Node *x = fibonacci_heap_node_pop_self(iterator_node).node;

        while (degree_array[x->degree] != NULL) {
            Fibonacci_Heap_Node *y = degree_array[x->degree];
            degree_array[x->degree] = NULL;

            if (x->priority > y->priority) {
                Fibonacci_Heap_Node *temp_node = x;
                x = y;
                y = temp_node;
            }

            y = fibonacci_heap_node_pop_self(y).node;
            x->child = fibonacci_heap_node_insert_sibling(x->child, y);
            y->parent = x;
            y->marked = false;
            x->degree++;
        }

        degree_array[x->degree] = x;
        iterator_node = next_node;
    }

    for (int i = 0; i <= heap->num_node; i++) {
        if (degree_array[i] != NULL) {
            degree_array[i]->parent = NULL;
            heap->min_node =
                fibonacci_heap_node_insert_sibling(heap->min_node, degree_array[i]);
            if (heap->min_node == degree_array[i] ||
                degree_array[i]->priority < heap->min_node->priority) {
                heap->min_node = degree_array[i];
            }
        }
    }

    return min_heap_entry;
}
