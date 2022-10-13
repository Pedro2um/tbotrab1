#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "io.h"
#include "PlanesPoint.h"

static char *_read_value(Dict d, FILE *f, char *key, int add_to_data);

static int _read_coord(PlanePointsArray *coords, FILE *f, int max_coord, int cc);

void read_tsp_data(Dict d, char *tsp_file){
    FILE *f = fopen(tsp_file, "r");
    if(f == NULL){
        printf("ERROR: No such file or directory: '%s'", tsp_file);
        exit(EXIT_FAILURE);
    }

    // Read the name    
    _read_value(d, f, NAME_KEY, 1);

    // Read the comments
    char *com_val = _read_value(d, f, COM_KEY, 0);
    free(com_val);

    // Read the type
    char *type_val = _read_value(d, f, TYPE_KEY, 0);
    if(strcmp(type_val, "TSP") != 0){
        printf("ERROR: Not an instance of symmetric TSP!");
        exit(EXIT_FAILURE);
    }
    free(type_val);

    // Read the dimension
    char *dim_val = _read_value(d, f, DIM_KEY, 0);
    int *dim_val_int = (int *) malloc(sizeof(int));
    *dim_val_int = atoi(dim_val);
    dict_insert(d, DIM_KEY, dim_val_int);
    free(dim_val);

    // Read the edge type
    char *edge_val = _read_value(d, f, EDGE_KEY, 0);
    if(strcmp(edge_val, "EUC_2D") != 0){
        printf("ERROR: Weights are not Euclidian distances in 2D!");
        exit(EXIT_FAILURE);
    }
    free(edge_val);

    // Read the coordinates
    char *coord_key = NULL;
    fscanf(f, " %m[^\n]\n", &coord_key);
    assert(strcmp(COORD_KEY , coord_key) == 0);
    free(coord_key);

    int max_coord = *( (int *) dict_get(d, DIM_KEY) );
    PlanePointsArray *coords = init_plane_points_array(max_coord);
    int cc = 1;

    while(_read_coord(coords, f, max_coord, cc)) cc++;
    dict_insert(d, COORD_KEY, coords);

    fclose(f);
}

FILE* write_header(Dict d, char * dir, char * type)
{
    const char* TYPE_TOUR[2] = {"TOUR", ".tour"};
    const char * TYPE_MST[2] = {"MST", ".mst"};

    char * my_type[2];

    if(strcmp(type, "MST") == 0 ){
        my_type[0] = strdup(TYPE_MST[0]);
        my_type[1] = strdup(TYPE_MST[1]);
    } else{
        my_type[0] = strdup(TYPE_TOUR[0]);
        my_type[1] = strdup(TYPE_TOUR[1]);
    }

    char * file_name = dict_get(d, NAME_KEY);

    int size_dir = 0;

    if(dir != NULL){
        size_dir = strlen(dir);
    }

    int file_dir_size = size_dir + strlen(file_name) + strlen(my_type[1]) + (3);
    char * file_dir = (char*)malloc(sizeof(char)*(file_dir_size));

    if(size_dir == 0) sprintf(file_dir,"./%s%s",file_name, my_type[1]);

    else sprintf(file_dir,"%s/%s%s", dir, file_name, my_type[1]);

    // printf("\n%s\n", file_dir);
    
    FILE* out_file =  fopen(file_dir, "wb");
    fprintf(out_file,"NAME: %s\n", file_name);
    fprintf(out_file,"TYPE: %s\n", my_type[0]);
    fprintf(out_file, "DIMENSION: %d\n", *((int*)dict_get(d, DIM_KEY)));
    fprintf(out_file, "%s_SECTION\n", my_type[0]);

    free(file_dir);
    free(my_type[0]);
    free(my_type[1]);

    return out_file;
}

static char *_read_value(Dict d, FILE *f, char *key, int add_to_data){
    char *key_str = NULL, *value = NULL;
    fscanf(f, " %m[^:]: %m[^\n]\n", &key_str, &value);
    assert(strcmp(key, key_str) == 0);

    if(add_to_data) dict_insert(d, key, value);

    free(key_str);
    return value;
}

static int _read_coord(PlanePointsArray *coords, FILE *f, int max_coord, int cc){
    int i = 0;
    double x = 0.0, y = 0.0;

    int id = fscanf(f, "%d%lf%lf", &i, &x, &y);
    if(id != 3){
        return 0;
    }

    assert(i == cc && i <= max_coord);
    set_plane_points_array(coords, i - 1, x, y);
    return 1;
}