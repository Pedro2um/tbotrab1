#ifndef MST_H
#define MST_H

#include "Dict.h"
#include "Edge.h"
#include "Graph.h"

/// @brief 
/// @param Um dict alocado
/// @param Tamamho do vetor de arestas
/// @return Um ponteiro para um vetor de arestas
EdgesArray *calculate_edges(Dict d, int size);

/// @brief 
/// @param  Um vetor de arestas
/// @param  O tamanho do vetor de arestas
/// @param  Numero de vétices do grafo
/// @param  Um ponteiro para o arquivo de saida
/// @return Um grafo representando a arvore 
Graph * minimum_spanning_tree(EdgesArray* arr, int size, int N, FILE* output_file);

#endif
