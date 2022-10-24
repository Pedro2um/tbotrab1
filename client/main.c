#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/Dict.h"
#include "../include/io.h"
#include "../include/mst.h"
#include "../include/PlanesPoint.h"
#include "../include/Graph.h"

int main(int argc, char *argv[])
{
    if(argc <= 1){
        fprintf(stderr, "ERROR, NO ARGV [1]!\n");
        exit(1);
    }

    Dict d;
    dict_init(d);
    read_tsp_data(d, argv[1]);
    
    int n = *((int *) dict_get(d, DIM_KEY));
    int total_edges = ceil(n * (n - 1) / 2.0);
    EdgesArray *e = calculate_edges(d, total_edges);
    free_plane_points_array(dict_get(d, COORD_KEY));
    sort_edges_array(e, total_edges);  

    FILE* mst_file = write_header(d, "saidas", "MST");
    Graph* minimum_graph = minimum_spanning_tree(e, total_edges, n, mst_file);
    free_edges_array(e);  
    fprintf(mst_file,"EOF\n");
    fclose(mst_file);

    FILE* tour_file = write_header(d ,"saidas", "TOUR");
    dict_delete(d);
    dfs(minimum_graph, tour_file);
    
    fprintf(tour_file,"EOF\n");
    fclose(tour_file);
    free_graph(minimum_graph);

    return 0;
}