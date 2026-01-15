#include "array.h"
#include "bst.h"
#include "graph.h"
#include "linkedList.h"
// #include "number-application.h"
#include "stdio.h"
#include "stdlib.h"
#define N 10

void test_API_array() {

    int arr[N] = {0, -3, 4, 2, 3, 9, 1, 7, 4, 6};

    array_print(arr, N);
    printf("\n");

    array_quick_sort(arr, N);

    array_print(arr, N);
    printf("\n");
}

void test_API_linked_list() {}

void test_API_bst() {
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

    head = bst_to_sorted_linked_list(root, head);

    linked_list_print(head);
}

void test_API_graph() {
    graph *g = graph_list_create(7);
    int **matrix = NULL;
    int distance = 0;
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
}

void test_API_number_application() {

    int input_array[14] = {1, 2, 0, 3, 10, 11, 16, 15, 21, 19, 20, 3, 1, 2};

    linked_list_node *input = array_to_linked_list(input_array, 14);
    linked_list_node *output = NULL;

    output = number_ternary_conversion(25, 31, input);

    linked_list_print(output);
}

// void temp(){
//
// }

int main() {

    test_API_bst();

    return 0;
}
