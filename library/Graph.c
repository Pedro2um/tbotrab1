#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

#define swap(x, y)   \
                     \
    {                \
        int aux = i; \
        i = j;       \
        j = aux;     \
    }

typedef unsigned char MatrixAdj;
typedef unsigned char Vertex;

struct graph
{
    Vertex *v;
    unsigned int v_size;
    MatrixAdj *adj;
};

static MatrixAdj *init_matrix_adj(int size);

static int get_matrix_adj(MatrixAdj *m, int size, int i, int j);

static void insert_matrix_adj(MatrixAdj *m, int size, int i, int j, unsigned short value);

static void free_matrix_adj(MatrixAdj *m);

static void private_dfs_(Graph *g, unsigned short id, FILE *outuput_file);

Graph *init_graph(int N)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));

    g->v = (Vertex *)calloc(N, sizeof(Vertex));
    g->v_size = N;
    g->adj = init_matrix_adj(N);

    return g;
}

void add_to_adjacency_list_of(Graph *g, unsigned short id1, unsigned short id2)
{
    insert_matrix_adj(g->adj, g->v_size, id1, id2, 1);
}

void dfs(Graph *g, FILE *output_file)
{
    private_dfs_(g, 0, output_file);
}

void private_dfs_(Graph *g, unsigned short id, FILE *output_file)
{
    g->v[id] = 1;
    fprintf(output_file, "%d\n", id + 1);

    for (int i = 0; i < g->v_size; i++)
    {
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
    MatrixAdj *adj = (MatrixAdj *)calloc(size * (size - 1) / 2, sizeof(MatrixAdj));
    // fazer verificacao
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

static void insert_matrix_adj(MatrixAdj *m, int size, int i, int j, unsigned short value)
{
    int N = size;

    if (i == j)
        return;
    if (i > j)
    {
        swap(i, j);
    }

    int index = (i * (2 * N - (i + 1))) / 2 + (j - 1 - i);
    m[index] = value;
}

static void free_matrix_adj(MatrixAdj *m)
{
    free(m);
}