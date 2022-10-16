#ifndef EDGE_H
#define EDGE_H

typedef struct edge Edge;
typedef Edge EdgesArray;

/// @brief Retorna o vetor de arestas
/// @param Tamamho do vetor de arestas
/// @return Um ponteiro para um vetor de arestas
EdgesArray *init_edges_array(int N);

/// @brief Altera a aresta especificada por index
/// @param Um ponteiro para um vetor de arestas alocado
/// @param O índice da aresta a ser alterada
/// @param O primeiro vértice
/// @param O segundo vértice
/// @param O peso da aresta
/// @return Nenhum
void set_edges_array(EdgesArray *e, int index, unsigned  short id_a, unsigned short id_b, float weight);

/// @brief Retorna o primeiro vértice da aresta
/// @param Um ponteiro para um vetor de arestas alocado
/// @param O índice da aresta
/// @return O primeiro vértice
unsigned short get_id_a_edges_array(EdgesArray *e, int index);

/// @brief Retorna o segundo vértice da aresta
/// @param Um ponteiro para um vetor de arestas alocado
/// @param O índice da aresta
/// @return O segundo vértice
unsigned short get_id_b_edges_array(EdgesArray *e, int index);

/// @brief Ordena o vetor de arestas ( ordem não decrescente )
/// @param Um ponteiro para um vetor de arestas alocado
/// @param O tamanho do vetor
/// @return Nenhum
void sort_edges_array(EdgesArray *e, int size);

/// @brief Libera a memoria alocada para o vetor de arestas
/// @param Um ponteiro para um vetor de arestas alocado
/// @return Nenhum
void free_edges_array(EdgesArray *e);

#endif
