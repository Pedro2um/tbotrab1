#ifndef IO_H
#define IO_H

#include "Dict.h"

void read_tsp_data(Dict d, char *tsp_file);

FILE* write_header(Dict d, char * dir, char * type);

#endif