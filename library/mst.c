#include <stdlib.h>
#include "mst.h"
#include "PlanesPoint.h"
#include "UnionFind.h"
#include <stdio.h>
#include <assert.h>

#define swap(x, y) if(1){int aux = i; i = j; j = aux;}
typedef struct matrixAdj MatrixAdj;

static MatrixAdj* init_matrix_adj(int size);

static int get_matrix_adj(MatrixAdj* m, int i , int j);

static void print_matrix_adj(MatrixAdj* m );

static void free_matrix_adj(MatrixAdj * m);

static void insert_matrix_adj(MatrixAdj * m, int i, int j, int value);



struct matrixAdj{
    int * array;
    int size;
};

static MatrixAdj* init_matrix_adj(int size){

    MatrixAdj* m = (MatrixAdj*)calloc(sizeof(MatrixAdj) ,1);
    
    int real_size = size*(size-1);
    real_size/=2;

    m->size = size;
    m->array = (int*)calloc(sizeof(int)*real_size, 1);

    return m;
}

static int get_matrix_adj(MatrixAdj* m, int i , int j){
    int N = m->size;
    int * matrix = m->array;

    if(i == j) return 0;
    if(i > j){
        swap(i, j);
    }

    int index = (i*(2*N - (i+1)))/2 + (j - 1 - i);
    return matrix[index];

}

static void print_matrix_adj(MatrixAdj* m ){
   int * matrix = m->array;
   int N = m->size;

    for (int i =0; i < N -1; i ++){
        int index = (i*(2*N - (i+1)))/2;
        printf("[ ");
        for(int j = 1 + i; j < N; j++){
            printf("%d ", matrix[index]);
            index += 1;
        }
        printf("]\n");
        for(int k =0; (k < i + 1) && i < N -2; k ++){
            printf("--");
        }
    }
}

static void free_matrix_adj(MatrixAdj * m){
    free(m->array);
    free(m);
    return;
}

static void insert_matrix_adj(MatrixAdj * m, int i, int j, int value){
    int * matrix = m->array;
    int N = m->size;

    if(i == j) return;
    if(i > j){
        swap(i, j);
    }
    int index = (i*(2*N - (i+1)))/2 + (j - 1 - i);
    matrix[index] = value;
    return;
}



// libera o vetor de pontos
Edge **calculate_edges(Dict d, int size){
    PlanesPoint **pp = dict_get(d, COORD_KEY);
    int n = *((int *) dict_get(d, DIM_KEY));
    Edge **e = (Edge **) malloc(size * sizeof(Edge *));

    if(e == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF E FAILED!\n");
        assert(0);
    }

    for(int i = 0, k = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++, k++){
            e[k] = init_edge(i + 1, j + 1, distance_between_planes_point(pp[i], pp[j]));
        }

        free_planes_point(pp[i]);
    }

    free_planes_point(pp[n - 1]);
    free(pp);

    return e;
}

// libera o vetor de arestas
UF* minimum_spanning_tree(Edge** arr, int size, int N){
    UF* dsu = initUnionFind(N);
    int cnt = 0;
    //iterar sobre o grafo
    for(int i = 0; i < size; i++){
        int ida = get_id_a_edge(arr[i]);
        int idb = get_id_b_edge(arr[i]);

        if(!Conected(dsu, ida , idb)){
            // printf("%d %d\n", ida, idb);
            // puts(" YES");
            Union(dsu, ida, idb);
            cnt++;
        }
        //else puts(" NO");

        free_edge(arr[i]);
    }
    //printf("%d\n", cnt);

    free(arr);

    return dsu;
}


void testa_matrix(){
    MatrixAdj * m = init_matrix_adj(10);

    //int ret = get_matrix(minhaMatrix, 4 , 3, 5);
    //printf("%d", ret);
    
    // 9 0 troca pra => 0 9
    insert_matrix_adj(m, 9,0, 1);

    print_matrix_adj(m);

    free_matrix_adj(m);
   
}