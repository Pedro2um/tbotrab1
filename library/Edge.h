#ifndef EDGE_H
#define EDGE_H

typedef struct edge Edge;
typedef Edge EdgesArray;

EdgesArray *init_edges_array(int N);

void set_edges_array(EdgesArray *e, int index, unsigned  short id_a, unsigned short id_b, float weight);

unsigned short get_id_a_edges_array(EdgesArray *e, int index);

unsigned short get_id_b_edges_array(EdgesArray *e, int index);

void sort_edges_array(EdgesArray *e, int size);

void free_edges_array(EdgesArray *e);

#endif