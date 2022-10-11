#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph Graph;

Graph* init_graph(int N);

void add_to_adjacency_list_of(Graph* g, unsigned short id1, unsigned short id2);

void print_graph_elements(Graph* g);

void dfs(Graph* g);

void free_graph(Graph* g);

// void testa_matrix();

#endif 