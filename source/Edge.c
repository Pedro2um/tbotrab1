#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "../include/Edge.h"

static int _cmp_edge(const void *a, const void *b);

struct edge{
    unsigned short id_a;
    unsigned short id_b;
    float weight;
};

EdgesArray *init_edges_array(int N){
    EdgesArray *e = (EdgesArray *) malloc(N * sizeof(Edge));
    if(e == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF E FAILED!\n");
        assert(0);
    }

    return e;
}

void set_edges_array(EdgesArray *e, int index, unsigned  short id_a, unsigned short id_b, float weight){
    e[index].id_a = id_a;
    e[index].id_b = id_b;
    e[index].weight = weight;
}

unsigned short get_id_a_edges_array(EdgesArray *e, int index){
    return e[index].id_a;
}

unsigned short get_id_b_edges_array(EdgesArray *e, int index){
    return e[index].id_b;
}

void sort_edges_array(EdgesArray *e, int size){
    qsort(e, size, sizeof(Edge), _cmp_edge);
}

void free_edges_array(EdgesArray *e){
    free(e);
}

static int _cmp_edge(const void *a, const void *b){
    Edge *ea = (Edge *) a, *eb = (Edge *) b;
    const double TOLERANCE = 1e-6;
    if( fabs( ea->weight - eb->weight ) < TOLERANCE) return 0;
    return ea->weight < eb->weight ? -1 : 1;
}
