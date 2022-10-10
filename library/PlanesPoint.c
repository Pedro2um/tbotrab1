#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "PlanesPoint.h"

PlanePointsArray *init_plane_points_array(unsigned short N){
    PlanePointsArray* p = (PlanePointsArray*) malloc(N * sizeof(PlanePoint));
    if(p == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF P FAILED!\n");
        assert(0);
    }

    return p;
}

void set_plane_points_array(PlanePointsArray *p, unsigned short id, float x, float y){
    p[id][0] = x;
    p[id][1] = y;
}

void print_plane_points_array(PlanePointsArray *p, unsigned short N){
    for(int i = 0; i < N; i++){
        printf("{\n  id = %d\n  x = %f\n  y = %f\n}\n", i + 1, p[i][0], p[i][1]);
    }
}

float distance_between_plane_points(PlanePointsArray *p, unsigned short id1, unsigned short id2){
    float distance = (p[id1][0] - p[id2][0]) * (p[id1][0] - p[id2][0])
                   + (p[id1][1] - p[id2][1]) * (p[id1][1] - p[id2][1]);
    return sqrt(distance);
}

void free_plane_points_array(PlanePointsArray *p){
    free(p);
}