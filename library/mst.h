#ifndef MST_H
#define MST_H

#include "Dict.h"
#include "Edge.h"
#include "UnionFind.h"
#include "Graph.h"
// void testa_matrix(void);

EdgesArray *calculate_edges(Dict d, int size);

//vai retornar um grafo representando a arvore 
Graph * minimum_spanning_tree(EdgesArray* arr, int size, int N, FILE* output_file);

#endif