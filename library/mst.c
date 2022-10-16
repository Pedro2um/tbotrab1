#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "mst.h"
#include "PlanesPoint.h"
#include "UnionFind.h"
// Como o grafo é completo, temos n*(n+1)/2 arestas, pois todo vértice é adjacente a todos os outros.
EdgesArray *calculate_edges(Dict d, int size){
    PlanePointsArray *pp = dict_get(d, COORD_KEY);
    int n = *((int *) dict_get(d, DIM_KEY));
    EdgesArray *e = init_edges_array(size);

    for(int i = 0, k = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++, k++){
            set_edges_array(e, k, i + 1, j + 1, distance_between_plane_points(pp, i, j));
        }
    }

    return e;
}
/*  Algoritmo de Kruskal para árvore geradora mínima (MST)
    1 - Ordenar as arestas ( ordem não decrescente )
    2 - Iterar sobre as arestas, e adicionar a aresta leve que cruza o corte que respeita a MST
*/
Graph* minimum_spanning_tree(EdgesArray* arr, int size, int N, FILE* output_file){
    Graph *g = init_graph(N);
    UF* dsu = initUnionFind(N);
    int cnt = 0;
    //iterar sobre o grafo
    for(int i = 0; i < size; i++){
        int ida = get_id_a_edges_array(arr, i);
        int idb = get_id_b_edges_array(arr, i);

        if(!Conected(dsu, ida , idb)){
            fprintf(output_file, "%d %d\n", ida, idb);
            Union(dsu, ida, idb);
            cnt++;
            
            add_to_adjacency_list_of(g, ida - 1, idb - 1);
        }
    }

    freeUnionFind(dsu);
    return g;
}
