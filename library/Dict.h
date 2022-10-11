#ifndef DICT_H
#define DICT_H

#define DICT_SIZE 13

#define NAME_KEY "NAME"
#define COM_KEY "COMMENT"
#define TYPE_KEY "TYPE"
#define DIM_KEY "DIMENSION"
#define EDGE_KEY "EDGE_WEIGHT_TYPE"
#define COORD_KEY "NODE_COORD_SECTION"

typedef struct keyVal KeyVal;
typedef KeyVal* Dict[DICT_SIZE];

void dict_init(Dict d);

void dict_insert(Dict d, char *key, void *value);

void *dict_get(Dict d, char *key);

void dict_delete(Dict d);

#endif