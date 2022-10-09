#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "./library/sort.h"
#include "./library/Dict.h"
#include "./library/io.h"
#include "./library/mst.h"
#include "./library/PlanesPoint.h"
#include "./library/Graph.h"

int cmp_int(void * x, void * y);

int main(int argc, char *argv[])
{   
    /*if(argc <= 1){
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

    //testa_matrix();
    */
    int n = 8;
    int arr[n];
    for(int i = 0; i < n; i++)
        arr[i] = (i+1) * (i+1) - i;
    //1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    //insertion_sort(arr, sizeof(arr), sizeof(int), cmp_int);
    heap_sort(arr, sizeof(arr), sizeof(int), cmp_int);
    for(int i = 0; i < n; i++){
        printf(" %d", arr[i]);
        printf("%s", (i == n-1?"\n":""));
    }

    return 0;
}

int cmp_int(void * x, void * y){
    if(x == NULL ){
        perror("DEU RUIM X EH NULL\n");
        exit(1);
    }
    else if(y == NULL){
        perror("DEU RUIM Y EH NULL\n");
        exit(1);
    }

    int X = *((int*)x);
    int Y = *((int*)y);
    return (X-Y); // 1 == x > y, 0 == x =y, -1 == x < y
}