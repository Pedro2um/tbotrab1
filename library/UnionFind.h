#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef struct uf UF;

UF* initUnionFind(int n);

void Union(UF* uf,  int a,int b);

int Conected(UF* uf, int a, int b);

int Find(UF* uf, int a);

void freeUnionFind(UF* uf);

void printUnionFind(UF* uf);




#endif 