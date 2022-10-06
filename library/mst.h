#ifndef MST_H
#define MST_H

#include "Dict.h"
#include "Edge.h"
#include "UnionFind.h"

Edge **calculate_edges(Dict d, int size);
UF* minimum_spanning_tree(Edge** arr, int size, int N);

#endif