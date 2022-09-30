#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "PlanesPoint.h"

struct planesPoint{
    double tuple[2];
    int id;
};



PlanesPoint * init_planes_point(int id, double x, double y){
    PlanesPoint* p = (PlanesPoint*)malloc(sizeof(PlanesPoint));
    p->tuple[0] = x;
    p->tuple[1] = y;
    p->id = id;

    return p;
}

double get_x_planes_point(PlanesPoint* p){
    return p->tuple[0];
}

double get_y_planes_point(PlanesPoint* p){
    return p->tuple[1];
}


void free_planes_point(PlanesPoint* p){
    free(p);
    return;
}

void print_planes_point(PlanesPoint* p){
    printf("{\n  id = %d\n  x = %lf\n  y = %lf\n}\n", p->id, p->tuple[0], p->tuple[1]);
}

double distance_between_planes_point(PlanesPoint* p1, PlanesPoint* p2){
    double distance  = (p1->tuple[0] - p2->tuple[0])*(p1->tuple[0] - p2->tuple[0]) + (p1->tuple[1] - p2->tuple[1])*(p1->tuple[1] - p2->tuple[1]);

    return sqrt(distance);
}


void copy_to_planes_point(PlanesPoint * p1, PlanesPoint* p2){
    p2->tuple[0] = p1->tuple[0];
    p2->tuple[1] = p1->tuple[1];
    p2->id = p1->id;
    return;
}