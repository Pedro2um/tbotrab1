#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph Graph;

#include <stdio.h>

Graph* init_graph(int N);

void add_to_adjacency_list_of(Graph* g, unsigned short id1, unsigned short id2);

void dfs(Graph* g, FILE* output_file);

void free_graph(Graph* g);

#endif 