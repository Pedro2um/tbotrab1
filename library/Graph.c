#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

// faz a troca entre dois inteiros
#define swap(a, b) { a ^= b; b ^= a; a ^= b; }

typedef unsigned char MatrixAdj;
typedef unsigned char Vertex;

struct graph
{
    // um vetor de char onde a posicao
    // eh o indice do vertice e o conteudo
    // indica se o vertice foi visitado
    Vertex *v;

    // quantidade de vertices
    unsigned int v_size;

    // um vetor de char abstraido em uma matriz onde
    // a posicao (i, j) indica se o vertice de indice
    // i eh adjacente ao vertice de indice j
    MatrixAdj *adj;
};

/**
 * @brief inicializa a estrutura matriz de adjacencias
 * 
 * @param size quantidade de vertices do grafo
 * @return MatrixAdj* a estrutura matriz de adjacencias
 */
static MatrixAdj *init_matrix_adj(int size);

/**
 * @brief verifica se dois vertices sao adjacentes
 * 
 * @param m a estrutura matriz de adjacencias
 * @param size quantidade de vertices do grafo
 * @param i vertice i
 * @param j vertice j
 * @return int 1 se os vertices sao adjacentes 0 caso contrario
 */
static int get_matrix_adj(MatrixAdj *m, int size, int i, int j);

/**
 * @brief insere uma adjacencia na matriz de adjacencias
 * 
 * @param m a estrutura matriz de adjacencias
 * @param size quantidade de vertices do grafo
 * @param i vertice i
 * @param j vertice j
 */
static void insert_matrix_adj(MatrixAdj *m, int size, int i, int j);

/**
 * @brief libera a memoria alocada para a matriz de adjacencias
 * 
 * @param m a estrutura matriz de adjacencias
 */
static void free_matrix_adj(MatrixAdj *m);

/**
 * @brief caminha pelo grafo e imprime o caminho no arquivo
 * 
 * @param g a estrutura de grafo
 * @param id o id do vertice a ser visitado
 * @param outuput_file o arquivo de output do caminho
 */
static void private_dfs_(Graph *g, unsigned short id, FILE *outuput_file);

Graph *init_graph(int N)
{
    Graph *g = (Graph *) malloc(sizeof(Graph));

    g->v = (Vertex *) calloc(N, sizeof(Vertex));
    g->v_size = N;
    g->adj = init_matrix_adj(N);

    return g;
}

void add_to_adjacency_list_of(Graph *g, unsigned short id1, unsigned short id2)
{
    insert_matrix_adj(g->adj, g->v_size, id1, id2);
}

void dfs(Graph *g, FILE *output_file)
{
    private_dfs_(g, 0, output_file);
}

void private_dfs_(Graph *g, unsigned short id, FILE *output_file)
{
    // marca o vertice como visitado
    g->v[id] = 1;

    // imprime o vertice no arquivo de saida
    // como parte do caminho
    fprintf(output_file, "%d\n", id + 1);

    // verifica todos os vertices
    for (int i = 0; i < g->v_size; i++)
    {
        // se o vertice for adjacente ao vertice atual
        // e nao tiver sido visitado ainda, eh chamado a dfs
        // para esse vertice
        if (get_matrix_adj(g->adj, g->v_size, id, i) && !g->v[i])
            private_dfs_(g, i, output_file);
    }
}

void free_graph(Graph *g)
{
    free(g->v);
    free_matrix_adj(g->adj);
    free(g);
}

static MatrixAdj *init_matrix_adj(int size)
{
    MatrixAdj *adj = (MatrixAdj *) calloc(size * (size - 1) / 2, sizeof(MatrixAdj));
    if(adj == NULL){
        fprintf(stderr, "ERROR, ALLOCATION OF ADJ FAILED!\n");
        assert(0);
    }
    return adj;
}

static int get_matrix_adj(MatrixAdj *m, int size, int i, int j)
{
    int N = size;

    if (i == j)
        return 0;
    if (i > j)
    {
        swap(i, j);
    }

    int index = (i * (2 * N - (i + 1))) / 2 + (j - 1 - i);
    return m[index];
}

static void insert_matrix_adj(MatrixAdj *m, int size, int i, int j)
{
    int N = size;

    if (i == j)
        return;
    if (i > j)
    {
        swap(i, j);
    }

    int index = (i * (2 * N - (i + 1))) / 2 + (j - 1 - i);
    m[index] = 1;
}

static void free_matrix_adj(MatrixAdj *m)
{
    free(m);
}
