#ifndef PLANES_POINT_H
#define PLANES_POINT_H

typedef struct planesPoint PlanesPoint;

// cria um ponto do plano que contem um id e suas cordenadas
PlanesPoint * init_planes_point(int id, double x, double y);

//retorna a coordenada x do ponto
double get_x_planes_point(PlanesPoint* p);

//retorna a coordernada y do ponto
double get_y_planes_point(PlanesPoint* p);

//libera a estrutura do ponto do plano
void free_planes_point(PlanesPoint* p);

//printa a estrutura do ponto do plano
void print_planes_point(PlanesPoint* p);

//calcula a distancia entre dois pontos do plano passados e retorna
double distance_between_planes_point(PlanesPoint* p1, PlanesPoint* p2);

//copia os dados do plano 1 e passa dos dados para o plano 2, (inclusive o id);
void copy_to_planes_point(PlanesPoint * p1, PlanesPoint* p2);



#endif 