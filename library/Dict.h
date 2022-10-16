#ifndef DICT_H
#define DICT_H

#define DICT_SIZE 7

#define NAME_KEY "NAME"
#define COM_KEY "COMMENT"
#define TYPE_KEY "TYPE"
#define DIM_KEY "DIMENSION"
#define EDGE_KEY "EDGE_WEIGHT_TYPE"
#define COORD_KEY "NODE_COORD_SECTION"

typedef struct keyVal KeyVal;
typedef KeyVal* Dict[DICT_SIZE];

/**
 * @brief inicializa um dicionario
 * 
 * @param d o dicionario
 */
void dict_init(Dict d);

/**
 * @brief insere uma chave/valor no dicionario
 * 
 * @param d o dicionario
 * @param key a chave
 * @param value o valor
 */
void dict_insert(Dict d, char *key, void *value);

/**
 * @brief retorna o valor referente a chave
 * 
 * @param d o dicionario
 * @param key a chave
 * @return void* o valor, ou null caso a chave nao exista
 */
void *dict_get(Dict d, char *key);

/**
 * @brief libera a memoria alocada para o dicionario
 * 
 * @param d o dicionario
 */
void dict_delete(Dict d);

#endif