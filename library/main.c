#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "PlanesPoint.h"

int main(int argc, char const *argv[])
{
    Dict d;
    dict_init(d);
    read_tsp_data(d, "a280.tsp");

    printf("%s\n", (char *) dict_get(d, "NAME"));
    printf("%s\n", (char *) dict_get(d, "COMMENT"));
    printf("%s\n", (char *) dict_get(d, "TYPE"));
    printf("%d\n", *( (int *) dict_get(d, "DIMENSION") ));
    printf("%s\n", (char *) dict_get(d, "EDGE_WEIGHT_TYPE"));

    PlanesPoint **vet = dict_get(d, "NODE_COORD_SECTION");
    int n = *( (int *) dict_get(d, "DIMENSION") );
    for(int i = 0; i < n; i++){
        print_planes_point(vet[i]);
    }

    free(dict_get(d, "NAME"));
    free(dict_get(d, "COMMENT"));
    free(dict_get(d, "TYPE"));
    free(dict_get(d, "DIMENSION"));
    free(dict_get(d, "EDGE_WEIGHT_TYPE"));
    for(int i = 0; i < n; i++){
        free_planes_point(vet[i]);
    }
    free(vet);

    dict_delete(d);
    
    return 0;
}