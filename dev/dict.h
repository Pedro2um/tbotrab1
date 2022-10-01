#ifndef DICT_H
#define DICT_H

#define DICT_SIZE 13

typedef struct key_val key_val;

typedef key_val *dict[DICT_SIZE];

void dict_init(dict d);

void dict_insert(dict d, char *key, void *value);

void *dict_get(dict d, char *key);

void dict_delete(dict d);

#endif