#include <stdlib.h>
#include "mst.h"
#include "PlanesPoint.h"
#include "dictKeys.h"

Edge **calculate_edges(Dict d){
    PlanesPoint **pp = dict_get(d, COORD_KEY);
    int n = *((int *) dict_get(d, DIM_KEY));
    Edge **e = (Edge **) malloc(( n * (n - 1) / 2 ) * sizeof(Edge *));

    for(int i = 0, k = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++, k++){
            e[k] = init_edge(i + 1, j + 1, distance_between_planes_point(pp[i], pp[j]));
        }
    }

    return e;
}

