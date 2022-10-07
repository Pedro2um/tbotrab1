#include <stdlib.h>
#include "mst.h"
#include "PlanesPoint.h"
#include "UnionFind.h"
#include <stdio.h>
#include <assert.h>

// libera o vetor de pontos
Edge **calculate_edges(Dict d, int size){
    PlanesPoint **pp = dict_get(d, COORD_KEY);
    int n = *((int *) dict_get(d, DIM_KEY));
    Edge **e = (Edge **) malloc(size * sizeof(Edge *));

    if(e == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF E FAILED!\n");
        assert(0);
    }

    for(int i = 0, k = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++, k++){
            e[k] = init_edge(i + 1, j + 1, distance_between_planes_point(pp[i], pp[j]));
        }

        free_planes_point(pp[i]);
    }

    free_planes_point(pp[n - 1]);
    free(pp);

    return e;
}

// libera o vetor de arestas
UF* minimum_spanning_tree(Edge** arr, int size, int N){
    UF* dsu = initUnionFind(N);
    int cnt = 0;
    //iterar sobre o grafo
    for(int i = 0; i < size; i++){
        int ida = get_id_a_edge(arr[i]);
        int idb = get_id_b_edge(arr[i]);

        if(!Conected(dsu, ida , idb)){
            // printf("%d %d\n", ida, idb);
            // puts(" YES");
            Union(dsu, ida, idb);
            cnt++;
        }
        //else puts(" NO");

        free_edge(arr[i]);
    }
    //printf("%d\n", cnt);

    free(arr);

    return dsu;
}