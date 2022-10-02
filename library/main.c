#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "PlanesPointList.h"

int main(int argc, char const *argv[])
{
    Dict d;
    dict_init(d);
    read_tsp_data(d, "a280.tsp");

    printf("%s\n", dict_get(d, "NAME"));
    printf("%s\n", dict_get(d, "COMMENT"));
    printf("%s\n", dict_get(d, "TYPE"));
    printf("%d\n", *( (int *) dict_get(d, "DIMENSION") ));
    printf("%s\n", dict_get(d, "EDGE_WEIGHT_TYPE"));
    pp_list_print(dict_get(d, "NODE_COORD_SECTION"));

    free(dict_get(d, "NAME"));
    free(dict_get(d, "COMMENT"));
    free(dict_get(d, "TYPE"));
    free(dict_get(d, "DIMENSION"));
    free(dict_get(d, "EDGE_WEIGHT_TYPE"));
    pp_list_free(dict_get(d, "NODE_COORD_SECTION"));

    dict_delete(d);
    
    return 0;
}