#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

#define swap(x, y) if(1){int aux = i; i = j; j = aux;}
typedef unsigned char MatrixAdj;
typedef unsigned char Vertex;

struct graph{
    // o vertice é um vetor de char, a posicao do vetor
    // é o id do vertice e o conteudo da posicao é o campo de finalizado
    // 1 para finalizado 0 para nao
    Vertex *v;

    //tamanho do vetor de vertice
    unsigned int v_size;

    // a matriz tambem é um vetor de char, matheus fez
    // os calculos de posicao
    MatrixAdj *adj;

    // esse é o vetor que vai salvar o tour pela dfs
    unsigned short *tour;

    // posicao atual no tour
    unsigned short tour_p;
};

static MatrixAdj* init_matrix_adj(int size);

static int get_matrix_adj(MatrixAdj* m, int size, int i , int j);

static void print_matrix_adj(MatrixAdj* m, int size);

static void insert_matrix_adj(MatrixAdj * m, int size, int i, int j, int value);

static void free_matrix_adj(MatrixAdj * m);


Graph* init_graph(int N);

void add_to_adjacency_list_of(unsigned short v1, unsigned short v2);

void print_graph_elements(Graph* g);

void dfs(Graph* g, unsigned short id){
    // adiciona o id do vertice atual ao vetor de tour
    g->tour[g->tour_p++] = id;

    // pra cada vertice ele tenta caminhar
    for(int i = id + 1; i < g->v_size; i++){
        // mas so caminha se for adjacente e nao tiver sido finalizado
        if(get_matrix_adj(g->adj, g->v_size, id, i) && !g->v[i])
            dfs(g, i);
    }

    // marca o vertice como finalizado
    g->v[id] = 1;
}

static MatrixAdj* init_matrix_adj(int size){
    MatrixAdj *adj = (MatrixAdj*) calloc(size * (size - 1) / 2, sizeof(MatrixAdj));
        // fazer verificacao
    return adj;
}

static int get_matrix_adj(MatrixAdj* m, int size, int i , int j){
    int N = size;

    if(i == j) return 0;    
    if(i > j){
        swap(i, j);
    }

    int index = (i * (2 * N - (i + 1))) / 2 + (j - 1 - i);
    return m[index];
}

static void print_matrix_adj(MatrixAdj* m, int size){
    int N = size;

    for (int i = 0; i < N - 1; i++){
        int index = (i * (2 * N - (i + 1))) / 2;
        printf("[ ");
        for(int j = 1 + i; j < N; j++){
            printf("%d ", m[index]);
            index += 1;
        }
        printf("]\n");
        for(int k =0; (k < i + 1) && i < N -2; k ++){
            printf("--");
        }
    }
}

static void insert_matrix_adj(MatrixAdj * m, int size, int i, int j, int value){
    int N = size;

    if(i == j) return;
    if(i > j){
        swap(i, j);
    }

    int index = (i * (2 * N - (i + 1))) / 2 + (j - 1 - i);
    m[index] = value;
}

static void free_matrix_adj(MatrixAdj * m){
    free(m);
}

// void testa_matrix(){
//     MatrixAdj * m = init_matrix_adj(10);

//     //int ret = get_matrix(minhaMatrix, 4 , 3, 5);
//     //printf("%d", ret);
    
//     // 9 0 troca pra => 0 9
//     insert_matrix_adj(m, 10, 9, 0, 1);

//     print_matrix_adj(m, 10);

//     free_matrix_adj(m);
// }