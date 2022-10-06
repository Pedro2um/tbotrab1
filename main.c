#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int cmp_edge(const void* a, const void* b){
    if(a == NULL || b == NULL) perror("AQUI\n");
    Edge* x = *((Edge**)a), *y = *((Edge**)b);
    double wx = get_weight_edge(x);
    double wy = get_weight_edge(y);
    if(wx > wy) return 1;
    else if(wx < wy) return -1;
    return 0;
}

int Rand(int a, int b){
    if(b < a){
        int temp = a;
        a = b;
        b = temp;
    }
    return a + rand()%(b-a+1);
}


int main(int argc, char* argv[]){
    /*UF* uf = initUnionFind(10);

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


   remove_inteiro(l ,1);
   remove_inteiro(l ,5);
   remove_inteiro(l ,3);

   print_list_gen(l , printa_inteiro);

   free_info_plus_list_gen(l, libera_inteiro);*/

    const int N = 5;
    const int SIZE = ceil(N*(N-1)/2.0);
    printf("%d\n", SIZE);
    Edge* arr[SIZE];

    if(argc <= 1) exit(1);

    srand(atoi(argv[1]));

    // inicialização das coordenadas dos vértices durante a leitura do arq de entrada -> O(N)
    // construção das arestas = N*(N-1)/2 -> O(N^2)
    for(int i = 1, k = 0; i <= N; i++)
        for(int j = i+1; j <= N && k < SIZE; j++, k++)
            arr[k] = init_edge(i, j, Rand(0, 1000));

    /*for(int i = 0; i < SIZE; i++){
        print_edge(arr[i]);
        puts("###");
    }
    puts("\n\n\n\n\n");
    */
    size_t size = SIZE;

    //ordenação das arestas
    qsort(arr, size, sizeof(Edge*), cmp_edge);
    UF* dsu = initUnionFind(N);
    //iterar sobre o grafo

    for(int i = 0; i < SIZE; i++){
        int ida = get_id_a_edge(arr[i]);
        int idb = get_id_b_edge(arr[i]);
        printf("(u,v) = %d %d ", ida, idb);
        if(!Conected(dsu, ida , idb)){
            puts(" YES");
            Union(dsu, ida, idb);
        }
        else puts(" NO");
    }

    printUnionFind(dsu);
    puts("");
    for(int i = 0; i < SIZE; i++){
        print_edge(arr[i]);
        puts("###");
    }

    freeUnionFind(dsu);
    for(int i = 0; i < SIZE; i++)
        free_edge(arr[i]);

    return 0;

}