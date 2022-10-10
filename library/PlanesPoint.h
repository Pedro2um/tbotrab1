#ifndef PLANES_POINT_H
#define PLANES_POINT_H

typedef float PlanePoint[2];
typedef PlanePoint PlanePointsArray;

PlanePointsArray *init_plane_points_array(unsigned short N);

void set_plane_points_array(PlanePointsArray *p, unsigned short id, float x, float y);

PlanePointsArray *get_plane_points_array(PlanePointsArray *p, int index);

void print_plane_points_array(PlanePointsArray *p, unsigned short N);

//calcula a distancia entre dois pontos do plano passados e retorna
float distance_between_plane_points(PlanePointsArray *p, unsigned short id1, unsigned short id2);

void free_plane_points_array(PlanePointsArray *p);

#endif 