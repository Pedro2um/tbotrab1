#ifndef IO_H
#define IO_H

#include "Dict.h"

/// @brief lê os dados do arquivo .tsp e coloca em um dicionario 
/// @param dicionario alocado 
/// @param string contendo o caminho para o arquivo .tsp
/// @return retorno vazio 
void read_tsp_data(Dict d, char *tsp_file);

/// @brief cria um arquivo .mst ou .tour com cabeçalho para um determinado .tsp
/// @param dicionario que guarda as informações do .tsp para criar o cabeçalho
/// @param diretorio aonde vai ser colocado o arquivo criado 
/// @param tipo do arquivo a ser criado, 'MST' ou 'TOUR'
/// @return retorna o arquivo 'mst' ou 'tour' com cabelho pronto
FILE* write_header(Dict d, char * dir, char * type);

#endif