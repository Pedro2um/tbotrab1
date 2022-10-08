#include <stdlib.h>
#include "mst.h"
#include "PlanesPoint.h"
#include "dictKeys.h"
#include "UnionFind.h"
#include <stdio.h>
#include <assert.h>

EdgesArray *calculate_edges(Dict d, int size){
    // PlanesPoint **pp = dict_get(d, COORD_KEY);
    PlanePointsArray *pp = dict_get(d, COORD_KEY);
    int n = *((int *) dict_get(d, DIM_KEY));
    // Edge **e = (Edge **) malloc(size * sizeof(Edge *));
    EdgesArray *e = init_edges_array(size);

    for(int i = 0, k = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++, k++){
            // e[k] = init_edge(i + 1, j + 1, distance_between_planes_point(pp[i], pp[j]));
            set_edges_array(e, k, i + 1, j + 1,
                distance_between_planes_point(
                    get_plane_points_array(pp, i),
                    get_plane_points_array(pp, j)
                )
            );
        }
    }

    return e;
}

UF* minimum_spanning_tree(EdgesArray* arr, int size, int N){
    UF* dsu = initUnionFind(N);
    int cnt = 0;
    //iterar sobre o grafo
    for(int i = 0; i < size; i++){
        int ida = get_id_a_edge(get_edges_array(arr, i));
        int idb = get_id_b_edge(get_edges_array(arr, i));

        if(!Conected(dsu, ida , idb)){
            /*printf("(u,v) = %d %d ", ida, idb);
            puts(" YES");*/
            Union(dsu, ida, idb);
            cnt++;
        }
        //else puts(" NO");
    }
    //printf("%d\n", cnt);

    return dsu;
}

