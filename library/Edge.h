#ifndef EDGE_H
#define EDGE_H

typedef struct edge Edge;
typedef Edge** EdgesArray;

Edge* init_edge(unsigned  short id_a, unsigned short id_b, float weight);

float get_weight_edge(Edge* e);

void print_edge(Edge* e);

unsigned short get_id_a_edge(Edge* e);

unsigned short get_id_b_edge(Edge * e);

int cmp_edge(const void *a, const void *b);

void free_edge(Edge * e);


#endif