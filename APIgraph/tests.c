#include "../APIarray/array.h"
#include "graph.h"
#include "stdio.h"

int main() {
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

    distance =
        graph_matrix_get_shortest_distance_bfs(matrix, 6, 1, searched, 7);

    printf("distance: %d\n", distance);

    return 0;
}
