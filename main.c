#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "./library/Dict.h"
#include "./library/io.h"
#include "./library/mst.h"
#include "./library/PlanesPoint.h"
#include "./library/Graph.h"

int main(int argc, char *argv[])
{
    if(argc <= 1){
        fprintf(stderr, "ERROR, NO ARGV [1]!\n");
        exit(1);
    }

    clock_t start = 0, end = 0;
    double seconds = 0.0;

    Dict d;
    dict_init(d);

    start = clock ();
    read_tsp_data(d, argv[1]);
    end = clock ();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("read_tsp_data: %.4lf\n", seconds );    
    
    int n = *((int *) dict_get(d, DIM_KEY));
    int total_edges = ceil(n * (n - 1) / 2.0);    

    start = clock ();
    EdgesArray *e = calculate_edges(d, total_edges);
    end = clock ();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("calculate_edges: %.4lf\n", seconds );

    free_plane_points_array(dict_get(d, COORD_KEY));

    start = clock ();
    sort_edges_array(e, total_edges);
    end = clock ();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("sort_edges_array: %.4lf\n", seconds );    

    FILE* mst_file = write_header(d, "saidas", "MST");

    start = clock ();
    Graph* minimum_graph = minimum_spanning_tree(e, total_edges, n, mst_file);
    end = clock ();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("minimum_spanning_tree: %.4lf\n", seconds );

    free_edges_array(e);  
    fprintf(mst_file,"EOF\n");
    fclose(mst_file);

    FILE* tour_file = write_header(d ,"saidas", "TOUR");
    dict_delete(d);

    start = clock ();
    dfs(minimum_graph, tour_file);
    end = clock ();
    seconds = (( double ) (end - start) / ( double ) CLOCKS_PER_SEC);
    printf("dfs: %.4lf\n", seconds );
    
    fprintf(tour_file,"EOF\n");
    fclose(tour_file);
    free_graph(minimum_graph);

    return 0;
}