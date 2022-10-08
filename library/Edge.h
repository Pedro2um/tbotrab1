#ifndef EDGE_H
#define EDGE_H

typedef struct edge Edge;
typedef Edge EdgesArray;

Edge* init_edge(unsigned  short id_a, unsigned short id_b, float weight);

float get_weight_edge(Edge* e);

void print_edge(Edge* e);

unsigned short get_id_a_edge(Edge* e);

unsigned short get_id_b_edge(Edge * e);

void free_edge(Edge * e);


EdgesArray *init_edges_array(int N);

void set_edges_array(EdgesArray *e, int index, unsigned  short id_a, unsigned short id_b, float weight);

EdgesArray *get_edges_array(EdgesArray *e, int index);

void sort_edges_array(EdgesArray *e, int size);

void free_edges_array(EdgesArray *e);

#endif