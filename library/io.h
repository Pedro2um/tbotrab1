#ifndef IO_H
#define IO_H

#include "Dict.h"
#include "Edge.h"
#include <stdio.h>

void read_tsp_data(Dict d, char *tsp_file);

void print_edges_in_file(EdgesArray* e_arr, int size,FILE* output_file);

FILE* write_header(Dict d, char * dir, char * type);

#endif