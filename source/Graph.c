#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/Graph.h"

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
    /*
        pegando um exemplo, imagine uma matriz 5x5
        a linha 0 terá 4 elementos, a linha 1 terá 3
        a linha 2 terá 2, se vermos bem, começamos com 4  (que é o tamanho menos 1 = > 5 -1 )
        vamos subraindo 1 a cada linha que descemos, na linha 1 tiramos 1
        na linha 2 tiramos 2. Então se quisermos saber quantos elementos já percorremos até um linha
        qualquer, podemos calcular como se fosse uma P.A que começa em 4 e vai subraindo 1.

        ex.: no começo da linha 3, teremos já percorrido 4 (linha 0) + 3 (linha 1) + 2 (linha 2) = 9
        entao o indice do elemento antes do primeiro da linha 3 é 9 - 1 = 8
        e o indice do primeiro da linha 3 é igual a 8 + 1 = 9, entao o resultado da P.A é 
        o indice do primeiro elemento da linha selecionada

        formula da p.a = > m.(u + p)/2 ; m = numero de elementos , u = ultimo, p = primeiro

        se estamos na linha 3, passamos 3 linhas que representam os 3 numeros de elementos, entao m = i que é a linha.
        o primeiro sempre será 4, que é a quantidade de elementos da primeira linha, e 4 é N (tamanho da matriz) -1,
        entao p =  N -1 

        partindo de N -1, vamos retirando 1 pra cada linha, ex.: na linha 1 temos 4 -1 = 3
        na linha 2 temos 4 -2 = 2 e assim por diante, entao para a linha 2 teremos 4 + 3 elementos antes dela.
        i é a linha que estamos, como retiramos de 4 até o valor da linha anterior de i, que é i - 1, no exemplo dado
        o u (ultimo) foi 4 - (1), que é a linha 1, podemos escrever então 4 - (2 -1), 2 é a linha que estamos
        portanto u = N - 1 - (i -1) que é N - i

        montando a formula
        
        i * (N -1 + N - i) /2 
        rearrajando = > i * (2 * N - (i +1))

        ufa!!

        pronto, selecionamos o primeiro elemento da linha, agora precisamos deslocar a coluna 

        se olharmos para a linha 0, vemos que a coluna 1 na verdade é o indice 0 do vetor. 
        entao j - 1 é o primeiro passo para corrigir o acesso a primeira linha da matriz,
        mas a cada linha que vamos descendo, temos um elento a menos na linha
        entao o acesso a coluna se dá por J = j - 1 - (i) 

        juntando tudo temos que o elemento que queremos acessar é a o primeiro elemento da linha  + o deslocamento da coluna 

        portanto = > (i * (2*N - (i + 1))) / 2 + (j - 1 - i)
    
    */
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
