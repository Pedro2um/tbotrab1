#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph Graph;
typedef struct vertex Vertex;

Graph* init_graph(void);

void add_vertex_to_graph(Graph * g, Vertex * v);

void add_to_adjacency_list_of(Vertex * v1, Vertex * v2);

int get_vertex_id(Vertex* v);

void print_graph_elements(Graph* g);



#endif 