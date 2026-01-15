#include "array.h"
#include "bst.h"
#include "graph.h"
#include "linkedList.h"
// #include "number-application.h"
#include "stdio.h"
#include "stdlib.h"
#define N 10

void test_array_library() {

    int arr[N] = {0, -3, 4, 2, 3, 9, 1, 7, 4, 6};

    array_print(arr, N);
    printf("\n");

    array_quick_sort(arr, N);

    array_print(arr, N);
    printf("\n");
}

void test_linked_list_library() {}

void test_bst_library() {
    bst_node *root = (void *)0x0;
    linked_list_node *head = NULL;
    root = bst_node_insert(root, 3);
    root = bst_node_insert(root, -4);
    root = bst_node_insert(root, -2);
    root = bst_node_insert(root, -3);
    root = bst_node_insert(root, 2);
    root = bst_node_insert(root, 7);
    root = bst_node_insert(root, 5);
    root = bst_node_insert(root, 9);

    bst_inorder_print(root);
    printf("\n");

    // head = bst_to_sorted_linked_list(root, head);
    //
    // linked_list_print(head);
}

void test_grpah_library() {
    graph *g = graph_list_create(7);
    int **matrix = NULL;
    // int distance = 0;
    int searched[7];
    array_constant_valued_get(searched, 0, 7);

    g = graph_list_add_edge(g, 0, 1);
    g = graph_list_add_edge(g, 0, 2);
    g = graph_list_add_edge(g, 1, 3);
    g = graph_list_add_edge(g, 1, 4);
    g = graph_list_add_edge(g, 2, 4);
    g = graph_list_add_edge(g, 2, 5);
    g = graph_list_add_edge(g, 3, 0);
    g = graph_list_add_edge(g, 3, 6);
    g = graph_list_add_edge(g, 4, 6);
    g = graph_list_add_edge(g, 4, 1);
    g = graph_list_add_edge(g, 5, 2);
    g = graph_list_add_edge(g, 5, 6);
    g = graph_list_add_edge(g, 6, 0);
    g = graph_list_add_edge(g, 6, 3);
    g = graph_list_add_edge(g, 6, 5);

    matrix = graph_list_to_matrix(g);
    (void)matrix;
}

// void temp(){
//
// }

int main() {

    test_bst_library();

    return 0;
}
