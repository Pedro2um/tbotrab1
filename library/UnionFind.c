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

//o elemento passado é a posicao do vetor, mas o elemento 1 está na posicao 0, portanto, toda funcao que retorna um inteiro para o usuario, na verdade, esse 
//inteiro menos 1 é a posicao real no vetor
void Union(UF* uf,  int a,int b){
    // por isso subtraimos 1 aqui 
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
    //retornamos o index mais 1, porque o usuario pensa que o vetor comeca com o elemento igual a 1
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
        // pritna i + 1 porque o usuario pensa que o vetor comeca com o elemento igual a 1
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


