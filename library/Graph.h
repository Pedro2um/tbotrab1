#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph Graph;

Graph* init_graph(int N);

void add_to_adjacency_list_of(unsigned short v1, unsigned short v2);

void print_graph_elements(Graph* g);

void dfs(Graph* g, unsigned short id);

// void testa_matrix();

#endif 