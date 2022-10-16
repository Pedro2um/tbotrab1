#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef struct uf UF;

/**
 * @brief Incia o conjunto
 * @param O numero de elementos do conjunto
 * @return Um ponteiro para um conjunto
 */
//os elementos são representados por numeros que começam do 1 e vão até N (inclusivo)
UF* initUnionFind(unsigned short n);

/**
 * @brief Une dois elementos que são representados por inteiros na estrutura
 * @param Dois inteiros
 * @return Nenhum
 */
void Union(UF* uf,  unsigned short a, unsigned short b);

/**
 * @brief   Verifica se dois elementos estao conectados
 * @param   Dois inteiros
 * @return  Nenhum
 */
//
unsigned short Conected(UF* uf, unsigned short a, unsigned short b);

/**
 * @brief   Acha o pai do elemento especificado
 * @param   Um ponteiro para um conjunto alocado
 * @param   Um inteiro
 * @return  Nenhum
 */
unsigned short Find(UF* uf, unsigned short a);

/**
 * @brief   Libera toda a estrutura do conjunto
 * @param   Um ponteiro para um conjunto alocado
 * @return  Nenhum
 */
//
void freeUnionFind(UF* uf);

#endif 
