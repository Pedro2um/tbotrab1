#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef struct uf UF;

// incia o conjunto/árvore/grafo que utiliza do algoritimo de Union-Find, os elementos são representados por numeros que começam do 1 e vão até N (inclusivo)
UF* initUnionFind(int n);

//une dois elementos que são representados por inteiros na estrutura
void Union(UF* uf,  int a,int b);

//verifica se dois elementos estao conectados)
int Conected(UF* uf, int a, int b);

//acha o pai do elemento especificado
int Find(UF* uf, int a);

//libera toda a estrutura do union find
void freeUnionFind(UF* uf);

//printa a estrutura (vetores) do union find 
void printUnionFind(UF* uf);




#endif 