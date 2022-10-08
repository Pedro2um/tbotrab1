#ifndef PLANES_POINT_H
#define PLANES_POINT_H

typedef struct planesPoint PlanesPoint;
typedef PlanesPoint PlanePointsArray;

// cria um ponto do plano que contem um id e suas cordenadas
PlanesPoint * init_planes_point(unsigned short id, float x, float y);

//retorna a coordenada x do ponto
float get_x_planes_point(PlanesPoint* p);

//retorna a coordernada y do ponto
float get_y_planes_point(PlanesPoint* p);

//libera a estrutura do ponto do plano
void free_planes_point(PlanesPoint* p);

//printa a estrutura do ponto do plano
void print_planes_point(PlanesPoint* p);

//calcula a distancia entre dois pontos do plano passados e retorna
float distance_between_planes_point(PlanesPoint* p1, PlanesPoint* p2);

//copia os dados do plano 1 e passa dos dados para o plano 2, (inclusive o id);
void copy_to_planes_point(PlanesPoint * p1, PlanesPoint* p2);

unsigned short get_id_planes_point(PlanesPoint* p);


PlanePointsArray *init_plane_points_array(int N);

void set_plane_points_array(PlanePointsArray *p, int index, unsigned short id, float x, float y);

PlanePointsArray *get_plane_points_array(PlanePointsArray *p, int index);

void free_plane_points_array(PlanePointsArray *p);

#endif 