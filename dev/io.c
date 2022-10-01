#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "io.h"

#define NAME_KEY "NAME"
#define COM_KEY "COMMENT"
#define TYPE_KEY "TYPE"
#define DIM_KEY "DIMENSION"
#define EDGE_KEY "EDGE_WEIGHT_TYPE"
#define COORD_KEY "NODE_COORD_SECTION"

static char *_read_value(dict d, FILE *f, char *key, int add_to_data);

void read_tsp_data(dict d, char *tsp_file){
    FILE *f = fopen(tsp_file, "r");

    // Read the name    
    _read_value(d, f, NAME_KEY, 1);

    // Read the comments
    _read_value(d, f, COM_KEY, 1);

    // Read the type
    char *type_val = _read_value(d, f, TYPE_KEY, 1);
    if(strcmp(type_val, "TSP") != 0){
        printf("ERROR: Not an instance of symmetric TSP!");
        exit(EXIT_FAILURE);
    }

    // Read the dimension
    char *dim_val = _read_value(d, f, DIM_KEY, 0);
    int *dim_val_int = (int *) malloc(sizeof(int));
    *dim_val_int = atoi(dim_val);
    dict_insert(d, DIM_KEY, dim_val_int);
    free(dim_val);

    // Read the edge type
    char *edge_val = _read_value(d, f, EDGE_KEY, 1);
    if(strcmp(edge_val, "EUC_2D") != 0){
        printf("ERROR: Weights are not Euclidian distances in 2D!");
        exit(EXIT_FAILURE);
    }

    fclose(f);
}

static char *_read_value(dict d, FILE *f, char *key, int add_to_data){
    char *key_str = NULL, *value = NULL;
    fscanf(f, " %m[^:]: %m[^\n]\n", &key_str, &value);
    assert(strcmp(key, key_str) == 0);

    if(add_to_data) dict_insert(d, key, value);

    free(key_str);
    return value;
}