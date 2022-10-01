#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int main(int argc, char const *argv[])
{
    dict d;
    dict_init(d);
    read_tsp_data(d, "a280.tsp");

    printf("%s\n", dict_get(d, "NAME"));
    printf("%s\n", dict_get(d, "COMMENT"));
    printf("%s\n", dict_get(d, "TYPE"));
    printf("%d\n", *( (int *) dict_get(d, "DIMENSION") ));
    printf("%s\n", dict_get(d, "EDGE_WEIGHT_TYPE"));

    free(dict_get(d, "NAME"));
    free(dict_get(d, "COMMENT"));
    free(dict_get(d, "TYPE"));
    free(dict_get(d, "DIMENSION"));
    free(dict_get(d, "EDGE_WEIGHT_TYPE"));

    dict_delete(d);
    
    return 0;
}