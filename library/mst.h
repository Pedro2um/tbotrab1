#ifndef MST_H
#define MST_H

#include "Dict.h"
#include "Edge.h"
#include "Graph.h"

EdgesArray *calculate_edges(Dict d, int size);

//vai retornar um grafo representando a arvore 
Graph * minimum_spanning_tree(EdgesArray* arr, int size, int N, FILE* output_file);

#endif