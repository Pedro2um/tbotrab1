#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "PlanesPoint.h"

struct planesPoint{
    float tuple[2];
    unsigned short id;
};

PlanesPoint * init_planes_point(unsigned short id, float x, float y){
    PlanesPoint* p = (PlanesPoint*)malloc(sizeof(PlanesPoint));
    if(p == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF P FAILED!\n");
        assert(0);
    }

    p->tuple[0] = x;
    p->tuple[1] = y;
    p->id = id;

    return p;
}

float get_x_planes_point(PlanesPoint* p){
    return p->tuple[0];
}

float get_y_planes_point(PlanesPoint* p){
    return p->tuple[1];
}


void free_planes_point(PlanesPoint* p){
    free(p);
    return;
}

void print_planes_point(PlanesPoint* p){
    printf("{\n  id = %d\n  x = %f\n  y = %f\n}\n", p->id, p->tuple[0], p->tuple[1]);
}

float distance_between_planes_point(PlanesPoint* p1, PlanesPoint* p2){
    float distance  = (p1->tuple[0] - p2->tuple[0])*(p1->tuple[0] - p2->tuple[0]) + (p1->tuple[1] - p2->tuple[1])*(p1->tuple[1] - p2->tuple[1]);

    return sqrt(distance);
}

void copy_to_planes_point(PlanesPoint * p1, PlanesPoint* p2){
    p2->tuple[0] = p1->tuple[0];
    p2->tuple[1] = p1->tuple[1];
    p2->id = p1->id;
    return;
}

unsigned short get_id_planes_point(PlanesPoint* p){
    return p->id;
}


PlanePointsArray *init_plane_points_array(int N){
    PlanePointsArray* p = (PlanePointsArray*) malloc(N * sizeof(PlanesPoint));
    if(p == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF P FAILED!\n");
        assert(0);
    }

    return p;
}

void set_plane_points_array(PlanePointsArray *p, int index, unsigned short id, float x, float y){
    p[index].id = id;
    p[index].tuple[0] = x;
    p[index].tuple[1] = y;
}

PlanePointsArray *get_plane_points_array(PlanePointsArray *p, int index){
    return &p[index];
}

void free_plane_points_array(PlanePointsArray *p){
    free(p);
}