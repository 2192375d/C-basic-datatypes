#include "graph.h"
#include "linkedList.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct graph_struct {
    int max_node;
    linked_list_node **lists;
} graph;

////////////////////////////////////////////////////////////////

graph *graph_list_create(int max_node) {
    /*
     * title, if no enough space for graph/adj lists, return NULL and leave a
     * message
     */

    graph *new = (graph *)calloc(1, sizeof(graph));

    if (new == NULL) {
        printf("graph_create: not enough space to create more graphs\n");
        return NULL;
    }

    new->max_node = max_node;

    new->lists =
        (linked_list_node **)calloc(max_node, sizeof(linked_list_node *));

    if (new->lists == NULL) {
        printf("graph_create: not enough space to create more adj lists\n");
        return NULL;
    }

    return new;
}

////////////////////////////////////////////////////////////////

graph *graph_list_add_edge(graph *g, int src, int dest) {
    /*
     * add an edge from src to dest, if edge already exists, return do nothing
     */

    if (g == NULL || src >= g->max_node || dest >= g->max_node) {
        return NULL;
    }

    linked_list_node *target = linked_list_node_create();
    target->value = dest;

    if (linked_list_search(g->lists[src], target) == NULL) {
        g->lists[src] = linked_list_insert_count(
            g->lists[src], target, linked_list_length(g->lists[src]));
    }

    return g;
}

////////////////////////////////////////////////////////////////
/*____________________________________________________________*/

void graph_list_print_dfs_recursive(graph *g, int current,
                                    _Bool visited[g->max_node]) {
    /*
     * helper function for graph_list_print_dfs()
     */

    linked_list_node *temp = g->lists[current];

    visited[current] = 1;
    printf("%d ", current);

    while (temp != NULL) {

        if (visited[temp->value] == 0) {
            graph_list_print_dfs_recursive(g, temp->value, visited);
        }

        temp = temp->next;
    }
}

/*____________________________________________________________*/
////////////////////////////////////////////////////////////////

void graph_list_print_dfs(graph *g, int start) {
    /*
     * prints a graph from an adjacency list in dfs
     */

    _Bool visited[g->max_node];
    for (int i = 0; i < g->max_node; i++) {
        visited[i] = 0;
    }

    graph_list_print_dfs_recursive(g, start, visited);
}

////////////////////////////////////////////////////////////////

void graph_list_print_bfs(graph *g, int start) {
    /*
     * prints a graph from an adjacency list in bfs
     */

    linked_list_node *queue = NULL;
    linked_list_node *temp = NULL;
    _Bool visited[g->max_node];

    for (int i = 0; i < g->max_node; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue = linked_list_insert_end(queue, start);

    while (queue != NULL) {

        printf("%d ", queue->value);
        temp = g->lists[queue->value];

        while (temp != NULL) {
            if (visited[temp->value] == 0) {

                // printf("%d->%d ", queue->value, temp->value);
                queue = linked_list_insert_end(queue, temp->value);
                visited[temp->value] = 1;
            }

            temp = temp->next;
        }
        queue = linked_list_delete_count(queue, 0);
    }
}

////////////////////////////////////////////////////////////////
/*____________________________________________________________*/

void graph_matrix_print_dfs_recursive(int **matrix, int current,
                                      _Bool visited[], int N) {
    /*
     * prints a graph from adjacency matrix in bfs
     */

    visited[current] = 1;
    printf("%d ", current);
    for (int i = 0; i < N; i++) {
        if (matrix[current][i] == 1 && visited[i] == 0) {
            graph_matrix_print_dfs_recursive(matrix, i, visited, N);
        }
    }
}

/*____________________________________________________________*/
////////////////////////////////////////////////////////////////

void graph_matrix_print_dfs(int **matrix, int start, int N) {
    /*
     * prints a graph from adjacency matrix in dfs
     */

    _Bool visited[N];

    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    graph_matrix_print_dfs_recursive(matrix, start, visited, N);
}

////////////////////////////////////////////////////////////////

void graph_matrix_print_bfs(int **matrix, int start, int N) {
    /*
     * prints a graph from adjacency matrix in bfs
     */

    linked_list_node *queue = NULL;
    _Bool visited[N];

    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue = linked_list_insert_end(queue, start);

    while (queue != NULL) {

        printf("%d ", queue->value);

        for (int i = 0; i < N; i++) {
            if (matrix[queue->value][i] == 1 && visited[i] == 0) {
                queue = linked_list_insert_end(queue, i);
                visited[i] = 1;
            }
        }

        queue = linked_list_delete_count(queue, 0);
    }
}

////////////////////////////////////////////////////////////////

int **graph_list_to_matrix(graph *g) {
    /*
     * convert a linked list to matrix, and returns it.
     * Expect matrix to be g->max_node by g->max_node
     */

    int **matrix = (int **)calloc(g->max_node, sizeof(int *));
    for (int i = 0; i < g->max_node; i++) {
        matrix[i] = (int *)calloc(g->max_node, sizeof(int));
    }

    linked_list_node *temp = NULL;
    for (int i = 0; i < g->max_node; i++) {
        temp = g->lists[i];

        while (temp != NULL) {
            matrix[i][temp->value] = 1;

            temp = temp->next;
        }
    }

    return matrix;
}
