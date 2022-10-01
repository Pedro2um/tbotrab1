#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dict.h"

static int _hash_code(char *key);

struct key_val{
    char *key;
    void *value;
};

void dict_init(dict d){
    memset(d, 0, sizeof(dict));
}

void dict_insert(dict d, char *key, void *value){
    key_val *kv = (key_val *) malloc(sizeof(key_val));
    kv->key = strdup(key);
    kv->value = value;

    int hash_code = _hash_code(key);
    int i = 0;

    while(d[hash_code + i] != NULL && strcmp(d[hash_code + i]->key, key) != 0){
        i = (i + 1) % DICT_SIZE;
    }

    if(d[hash_code + i] != NULL){
        free(d[hash_code + i]->key);
        free(d[hash_code + i]);
    }

    d[hash_code + i] = kv;
}

void *dict_get(dict d, char *key){
    int hash_code = _hash_code(key);
    int i = 0;

    while(d[hash_code + i] != NULL && strcmp(d[hash_code + i]->key, key) != 0){
        i = (i + 1) % DICT_SIZE;
    }

    if(d[hash_code + i] == NULL) return NULL;
    return d[hash_code + i]->value;
}

void dict_delete(dict d){
    for(int i = 0; i < DICT_SIZE; i++){
        if(d[i] != NULL){
            free(d[i]->key);
            free(d[i]);
            d[i] = NULL;
        }
    }
}

static int _hash_code(char *key){
    unsigned long long code = 0;

    int i = 0;
    while(key[i] != '\0'){
        code += (unsigned long long) pow(key[i], i + 1) % DICT_SIZE;
        i++;
    }

    return code % DICT_SIZE;
}