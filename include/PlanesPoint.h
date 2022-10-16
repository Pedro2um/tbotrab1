#ifndef PLANES_POINT_H
#define PLANES_POINT_H

typedef float PlanePoint[2];
typedef PlanePoint PlanePointsArray;

/**
 * @brief inicializa a estrutura de pontos
 * 
 * @param N quantidade de pontos
 * @return PlanePointsArray* a estrutura de pontos
 */
PlanePointsArray *init_plane_points_array(unsigned short N);

/**
 * @brief modifica um ponto na estrutura de pontos
 * 
 * @param p a estrutura de pontos
 * @param id o id do ponto a ser modificado
 * @param x o novo x do ponto
 * @param y o novo y do ponto
 */
void set_plane_points_array(PlanePointsArray *p, unsigned short id, float x, float y);

/**
 * @brief calcula a distancia entre dois pontos
 * 
 * @param p a estrutura de pontos
 * @param id1 o id do primeiro ponto
 * @param id2 o id do segundo ponto
 * @return float a distancia entre os pontos
 */
float distance_between_plane_points(PlanePointsArray *p, unsigned short id1, unsigned short id2);

/**
 * @brief libera a memoria alocada para a estrutura de pontos
 * 
 * @param p a estrutura de pontos
 */
void free_plane_points_array(PlanePointsArray *p);

#endif 