#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Edge.h"
#include <assert.h>
#include "sort.h"
static int _cmp_edge(const void *a, const void *b);

struct edge{
    unsigned short id_a;
    unsigned short id_b;
    float weight;
};

Edge* init_edge(unsigned short id_a, unsigned short id_b, float weight){
    Edge* e = (Edge*)malloc(sizeof(Edge));
    if(e == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF E FAILED!\n");
        assert(0);
    }
    e->id_a = id_a;
    e->id_b = id_b;
    e->weight = weight;
    return e;
}

float get_weight_edge(Edge* e){
    if(e == NULL){
        printf("error, get_weight_edge got a NULL edge pointer");
        return 0;
    }
    return e->weight;
}

void print_edge(Edge* e){
    if(e == NULL){
        printf("error, print_edge got a NULL edge pointer");
        return;
    }
    printf("\nEdge\n{\n  id_a: %d\n  id_b: %d\n  weight: %lf\n}\n", e->id_a, e->id_b, e->weight);
}


unsigned short get_id_a_edge(Edge* e){
    if(e == NULL){
        printf("error, get_id_a_edge got a NULL edge pointer");
        return -1;
    }
    return e->id_a;
}

unsigned short get_id_b_edge(Edge * e){
    if(e == NULL){
        printf("error, get_id_b_edge got a NULL edge pointer");
        return -1;
    }
    return e->id_b;
}

void free_edge(Edge * e){
    free(e);
}

static int _cmp_edge(const void *a, const void *b){
    Edge *ea = (Edge *) a, *eb = (Edge *) b;
    const double TOLERANCE = 1e-6;
    if( fabs( ea->weight - eb->weight ) < TOLERANCE) return 0;
    return ea->weight < eb->weight ? -1 : 1;
}


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

EdgesArray *get_edges_array(EdgesArray *e, int index){
    return &e[index];
}

void sort_edges_array(EdgesArray *e, int size){
    qsort(e, size, sizeof(Edge), _cmp_edge);
    //sort(e, size);
}

void free_edges_array(EdgesArray *e){
    free(e);
}