#ifndef MST_H
#define MST_H

#include "Dict.h"
#include "Edge.h"
#include "UnionFind.h"

// void testa_matrix(void);

EdgesArray *calculate_edges(Dict d, int size);

UF* minimum_spanning_tree(EdgesArray* arr, int size, int N);

#endif