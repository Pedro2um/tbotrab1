#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/Dict.h"

static int _hash_code(char *key);

struct keyVal{
    char *key;
    void *value;
};

void dict_init(Dict d){
    memset(d, 0, sizeof(Dict));
}

void dict_insert(Dict d, char *key, void *value){
    KeyVal *kv = (KeyVal *) malloc(sizeof(KeyVal));
    kv->key = strdup(key);
    kv->value = value;

    int hash_code = _hash_code(key);
    int i = 0;

    // a insercao funciona com deslocamento
    // caso a posicao referente ao hash code esteja ocupada
    // ele procura a proxima livre
    while(d[hash_code + i] != NULL && strcmp(d[hash_code + i]->key, key) != 0){
        i = (i + 1) % DICT_SIZE;
    }

    // caso a chave ja exista
    // o valor referente a ela é atualizado
    if(d[hash_code + i] != NULL){
        free(d[hash_code + i]->key);
        free(d[hash_code + i]);
    }

    d[hash_code + i] = kv;
}

void *dict_get(Dict d, char *key){
    int hash_code = _hash_code(key);
    int i = 0;

    while(d[hash_code + i] != NULL && strcmp(d[hash_code + i]->key, key) != 0){
        i = (i + 1) % DICT_SIZE;
    }

    if(d[hash_code + i] == NULL) return NULL;
    return d[hash_code + i]->value;
}

void dict_delete(Dict d){
    // como o dicionario foi modelado pra esse problema
    // ele libera valores que nao foram liberados antes
    free(dict_get(d, NAME_KEY));
    free(dict_get(d, DIM_KEY));

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