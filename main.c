#include <stdio.h>
#include <stdlib.h>

#include "./library/UnionFind.h"
#include "./library/ListaGen.h"
#include "./library/Edge.h"
#include "./library/PlanesPoint.h"

void insere_inteiro(ListGen* l, int n ){
    int * p = (int*)malloc(sizeof(int));
    *p = n;
    insert_list_gen(l, p);
}

int compara_inteiro(void * a, void * b){
    if(*(int*)a == *(int*)b){
        return 0;
    }else return 1;
}


int remove_inteiro(ListGen* l, int n ){
   int *  p = remove_list_gen(l, &n, compara_inteiro);
   int k = *p;
   free(p);
   return k;
   
}

void printa_inteiro(void * a ){
    printf("%d ", *((int*)a));
    return;
}

void libera_inteiro(void * i){
    free((int*)i);
}



int main(void){
    UF* uf = initUnionFind(10);

    Union(uf, 1, 2);
    Union(uf, 1, 3);
    Union(uf, 4, 5);
    Union(uf, 4, 1);

    printUnionFind(uf);
    freeUnionFind(uf);

    puts("");

    ListGen* l = init_list_gen();
    
    insere_inteiro(l, 1);
    insere_inteiro(l, 2);
    insere_inteiro(l, 3);
    insere_inteiro(l, 4);
    insere_inteiro(l, 5);

    Iterator* t = get_iterator_list_gen(l);
    for(; its_end_iterator(t)!= 1; advance_iterator(t)){
        int * i = get_current_by_iterator(t);
        printf("%d\n", *i);
    }

    free_iterator(t);
   
    remove_inteiro(l ,1);
    remove_inteiro(l ,5);
    remove_inteiro(l ,3);

    print_list_gen(l , printa_inteiro);

    free_info_plus_list_gen(l, libera_inteiro);

   

    return 0;
}