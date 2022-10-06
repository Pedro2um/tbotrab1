#ifndef EDGE_H
#define EDGE_H

typedef struct edge Edge;
typedef Edge** EdgesArray;

Edge* init_edge(int id_a, int id_b, double weight);

double get_weight_edge(Edge* e);

void print_edge(Edge* e);

int get_id_a_edge(Edge* e);

int get_ide_b_edge(Edge * e);

void free_edge(Edge * e);


#endif