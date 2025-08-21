#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph_struct graph;

graph *graph_list_add_edge(graph *g, int src, int dest);

graph *graph_list_create(int max_node);

void graph_list_print_bfs(graph *g, int start);

void graph_list_print_dfs(graph *g, int start);

int **graph_list_to_matrix(graph *g);

void graph_matrix_print_dfs(int **matrix, int start, int N);

void graph_matrix_print_bfs(int **matrix, int start, int N);

int graph_matrix_get_shortest_distance_dfs(int **matrix, int src, int dest,
                                           int visited[], int N);

#endif
