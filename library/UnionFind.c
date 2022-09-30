#include <stdio.h>
#include <stdlib.h>

#include "UnionFind.h"


struct uf{
    int * vec;
    int * weights;
    unsigned int size;
};  


UF* initUnionFind(int n){
    UF* uf = (UF*)malloc(sizeof(UF));

    uf->size = n;
    uf->vec = (int*)calloc(sizeof(int), n);
    uf->weights = (int*)calloc(sizeof(int), n);
    
    for(int i =0; i < n; i ++){
        uf->vec[i] = i;
        uf->weights[i] = 1;
    }

    return uf;

}

void Union(UF* uf,  int a,int b){
    int ar = Find(uf, a) - 1;
    int br = Find(uf, b) - 1;

    int * w = uf->weights;
    int * v = uf->vec;

    if(w[ar] >= w[br]){
        v[br] = ar;
        w[ar] += w[br];
    }else{
        v[ar] = br;
        w[br] += w[ar];
    }


}

int Conected(UF* uf, int a, int b){
    return (Find(uf, a) == Find(uf, b));
}


int Find(UF* uf, int a){
    int * vec = uf->vec;
    int i = a - 1;
    while (i != vec[i]){
        vec[i] = vec[vec[i]];
        i = vec[i];
    }
    return i + 1;
}


void freeUnionFind(UF* uf){
    free(uf->vec);
    free(uf->weights);
    free(uf);
}

void printUnionFind(UF* uf){
    int * vec = uf->vec;
    int * w = uf->weights;

    printf("[ ");
    for(int i =0; i < uf->size; i ++){
        printf("%d ", vec[i] + 1);
    }
    printf("]\n");

     printf("[ ");
    for(int i =0; i < uf->size; i ++){
        printf("%d ", w[i]);
    }
    printf("]");

    return;
}


