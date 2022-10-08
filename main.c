#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "./library/Dict.h"
#include "./library/io.h"
#include "./library/mst.h"
#include "./library/PlanesPoint.h"

int main(int argc, char *argv[])
{   
    if(argc <= 1){
        fprintf(stderr, "ERROR, NO ARGV [1]!\n");
        exit(1);
    }

    Dict d;
    dict_init(d);

    clock_t start = 0, end = 0;
    double seconds = 0.0;
    
    start = clock();
    read_tsp_data(d, argv[1]);
    end = clock();
    seconds = (( double ) (end - start) / CLOCKS_PER_SEC);
    printf("read_tsp_data: %.4lf\n", seconds );

    int n = *((int *) dict_get(d, DIM_KEY));
    int total_edges = ceil(n * (n - 1) / 2.0);

    start = clock();
    EdgesArray *e = calculate_edges(d, total_edges);
    end = clock();
    seconds = (( double ) (end - start) /  CLOCKS_PER_SEC);
    printf("calculate_edges: %.4lf\n", seconds );

    PlanePointsArray *pp = dict_get(d, COORD_KEY);
    free_plane_points_array(pp);

    start = clock();
    // qsort(e, n * (n - 1) / 2, sizeof(Edge *), cmp_edge);
    sort_edges_array(e, total_edges);
    end = clock();
    seconds = (( double ) (end - start) / CLOCKS_PER_SEC);
    printf("qsort: %.4lf\n", seconds );

    start = clock();
    UF *dsu = minimum_spanning_tree(e, total_edges, n);
    end = clock();
    seconds = (( double ) (end - start) / CLOCKS_PER_SEC);
    printf("dsu: %.4lf\n", seconds );

    free(dict_get(d, NAME_KEY));
    free(dict_get(d, DIM_KEY));
    free(dict_get(d, EDGE_KEY));

    free_edges_array(e);

    freeUnionFind(dsu);
    dict_delete(d);

    testa_matrix();
    
    return 0;
}
