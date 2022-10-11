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

int cmp(void* x, void* y){
    int a = *((int*)x);
    int b = *((int*)y);
    if(a > b) return 1;
    else if(a < b) return -1;
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc <= 1){
        fprintf(stderr, "ERROR, NO ARGV [1]!\n");
        exit(1);
    }

    /*Dict d;
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
    printf("sort: %.4lf\n", seconds );

    FILE* mst_file = write_header(d, "saidas", "MST");

    start = clock();
    Graph* minimum_graph = minimum_spanning_tree(e, total_edges, n, mst_file);
    end = clock();
    seconds = (( double ) (end - start) / CLOCKS_PER_SEC);
    printf("dsu: %.4lf\n", seconds );
  
    fprintf(mst_file,"EOF\n");
    fclose(mst_file);
    free_edges_array(e);

    //inicializa um arquivo com um determinado cabeçalho e o retorna
    FILE* tour_file = write_header(d ,"saidas", "TOUR");

    free(dict_get(d, NAME_KEY));
    free(dict_get(d, DIM_KEY));
    free(dict_get(d, EDGE_KEY));
    dict_delete(d);

    start = clock();
    dfs(minimum_graph, tour_file);
    end = clock();
    seconds = (( double ) (end - start) / CLOCKS_PER_SEC);
    printf("dfs: %.4lf\n", seconds );

    fprintf(tour_file,"EOF\n");
    fclose(tour_file);

    free_graph(minimum_graph);
     */
    int n = atoi(argv[1]);

    int arr[n];

    srand(atoi(argv[1]));
    for(int i = 0; i < n; i++)
        arr[i] = rand()%(i+1), printf(" %d%s", arr[i], (i == (n-1)? "\n" : "" ));

    //heap_sort(arr, sizeof(arr), sizeof(int), cmp);
    sort(arr, sizeof(arr), sizeof(int), cmp);

    for(int i = 0; i < n; i++)
        printf(" %d%s", arr[i], (i == (n-1)? "\n" : ""));


    return 0;
}