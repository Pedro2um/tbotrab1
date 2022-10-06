#include <stdio.h>
#include <stdlib.h>

#include "Edge.h"

struct edge{
    int id_a;
    int id_b;
    double weight;
};

Edge* init_edge(int id_a, int id_b, double weight){
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->id_a = id_a;
    e->id_b = id_b;
    e->weight = weight;
    return e;
}

double get_weight_edge(Edge* e){
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


int get_id_a_edge(Edge* e){
    if(e == NULL){
        printf("error, get_id_a_edge got a NULL edge pointer");
        return -1;
    }
    return e->id_a;
}

int get_ide_b_edge(Edge * e){
    if(e == NULL){
        printf("error, get_id_b_edge got a NULL edge pointer");
        return -1;
    }
    return e->id_b;
}


void free_edge(Edge * e){
    free(e);
}