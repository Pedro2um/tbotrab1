#include <stdio.h>
#include <stdlib.h>

#include "./library/UnionFind.h"

int main(void){
    UF* uf = initUnionFind(10);

    Union(uf, 1, 2);
    Union(uf, 1, 3);
    Union(uf, 4, 5);
    Union(uf, 4, 1);

    printUnionFind(uf);
    freeUnionFind(uf);

    return 0;
}