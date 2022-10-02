#ifndef DICT_H
#define DICT_H

#define DICT_SIZE 13

typedef struct keyVal KeyVal;

typedef KeyVal *Dict[DICT_SIZE];

void dict_init(Dict d);

void dict_insert(Dict d, char *key, void *value);

void *dict_get(Dict d, char *key);

void dict_delete(Dict d);

#endif