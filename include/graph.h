// linkedList.h

/*
 * This file takes part of Lumiere's datatype libraries in C
 * The current file contains the API documentation of all functions from the
 * graph library
 *
 * Note that the graphs here take only works with integer
 *
 * No further documentation is provided in this file because the purpose of each
 * functions are self explainatory from their name
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "linkedList.h"
#include "stdbool.h"

typedef struct edge_struct {
    int src;
    int dest;
    int weight;
} edge;

typedef struct graph_struct {
    int max_node;
    linked_list_node **lists;
} graph;

/*__________________adjacency list operations_________________*/
graph *graph_list_add_edge(graph *g, int src, int dest);

graph *graph_list_create(int max_node);

void graph_list_print_bfs(graph *g, int start);

void graph_list_print_dfs(graph *g, int start);

bool graph_list_is_undirected(graph *g);

// graph *graph_list_get_mst_kruskal(graph *g);

/*__________________adjacency matrix operations_______________*/
void graph_matrix_print_dfs(int **matrix, int start, int N);

void graph_matrix_print_bfs(int **matrix, int start, int N);

bool graph_matrix_is_undrected(int **matrix);

edge *graph_matrix_get_edges(int **matrix, int N);

/*__________________other operations__________________________*/
int **graph_list_to_matrix(graph *g);

#endif
