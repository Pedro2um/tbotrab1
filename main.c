#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./library/Dict.h"
#include "./library/io.h"
#include "./library/mst.h"
#include "./library/PlanesPoint.h"

int main(int argc, char const *argv[])
{
    Dict d;
    dict_init(d);

    clock_t start = 0, end = 0;
    double seconds = 0.0;

    start = clock();
    read_tsp_data(d, "./exemplos/in/a280.tsp");
    end = clock();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("read_tsp_data: %.4lf\n", seconds );

    int n = *((int *) dict_get(d, DIM_KEY));

    start = clock();
    Edge **e = calculate_edges(d, n * (n - 1) / 2);
    end = clock();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("calculate_edges: %.4lf\n", seconds );

    start = clock();
    qsort(e, n * (n - 1) / 2, sizeof(Edge *), cmp_edge);
    end = clock();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("qsort: %.4lf\n", seconds );

    start = clock();
    UF *dsu = minimum_spanning_tree(e, n * (n - 1) / 2, n);
    end = clock();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("dsu: %.4lf\n", seconds );

    free(dict_get(d, NAME_KEY));
    free(dict_get(d, DIM_KEY));

    freeUnionFind(dsu);
    dict_delete(d);

    return 0;
}