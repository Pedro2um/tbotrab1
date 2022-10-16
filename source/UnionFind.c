#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/UnionFind.h"

#define in_range(x, N) (x >= 0 && x < N)

struct uf{
    unsigned short * vec;
    unsigned short * weights;
    unsigned int size;
};

UF* initUnionFind(unsigned short n){
    UF* uf = (UF*)malloc(sizeof(UF));
    if(uf == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF UF FAILED!\n");
        assert(0);
    }
    uf->size = n;
    uf->vec = (unsigned short *)malloc(sizeof(unsigned short)*n);
    if(uf->vec == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF VEC FAILED!\n");
        assert(0);
    }
    uf->weights = (unsigned short*)malloc(sizeof(unsigned short)*n);
    if(uf->weights == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF WEIGHTS FAILED!\n");
        assert(0);
    }
    for(unsigned short i =0; i < n; i ++){
        uf->vec[i] = i;
        uf->weights[i] = 1;
    }

    return uf;
}

//o elemento passado é a posicao do vetor, mas o elemento 1 está na posicao 0, portanto, toda funcao que retorna um inteiro para o usuario, na verdade, esse 
//inteiro menos 1 é a posicao real no vetor
void Union(UF* uf,  unsigned short a,unsigned short b){
    // por isso subtraimos 1 aqui 
    unsigned short ar = Find(uf, a) - 1;
    unsigned short br = Find(uf, b) - 1;

    unsigned short * w = uf->weights;
    unsigned short * v = uf->vec;

    if(in_range(ar, uf->size) && in_range(br, uf->size)) {
        if (w[ar] >= w[br]) {
            v[br] = ar;
            w[ar] += w[br];
        } else {
            v[ar] = br;
            w[br] += w[ar];
        }
    }
    else{
        if( in_range(ar, uf->size) == 0 ) fprintf(stderr, "ERROR, AR IS OUT OF BOUNDS!\n");
        if( in_range(br, uf->size) == 0 ) fprintf(stderr, "ERROR, BR IS OUT OF BOUNDS!\n");
        assert(0);
    }

}

unsigned short Conected(UF* uf, unsigned short a, unsigned short b){
    return (Find(uf, a) == Find(uf, b));
}

unsigned short Find(UF* uf, unsigned short a){
    unsigned short * vec = uf->vec;
    unsigned short i = a - 1;
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