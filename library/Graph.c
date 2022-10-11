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
    unsigned short *tour;
    unsigned short tour_p;
};

static MatrixAdj *init_matrix_adj(int size);

static int get_matrix_adj(MatrixAdj *m, int size, int i, int j);

static void print_matrix_adj(MatrixAdj *m, int size);

static void insert_matrix_adj(MatrixAdj *m, int size, int i, int j, int value);

static void free_matrix_adj(MatrixAdj *m);

static void private_dfs_(Graph *g, unsigned short id, FILE* outuput_file);

Graph *init_graph(int N)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));

    g->v = (Vertex *)calloc(N, sizeof(Vertex));
    g->v_size = N;
    g->adj = (MatrixAdj *)calloc(N * (N - 1) / 2, sizeof(MatrixAdj));
    g->tour = (unsigned short *)malloc(N * sizeof(unsigned short));
    g->tour_p = 0;

    return g;
}

void add_to_adjacency_list_of(Graph *g, unsigned short id1, unsigned short id2)
{
    insert_matrix_adj(g->adj, g->v_size, id1, id2, 1);
}

void print_graph_elements(Graph *g)
{
    for (int i = 0; i < g->tour_p; i++)
    {
        printf("%d\n", g->tour[i] + 1);
    }
}

void dfs(Graph *g, FILE* output_file)
{
    private_dfs_(g, 0, output_file);
}

void private_dfs_(Graph *g, unsigned short id, FILE* output_file)
{
    g->tour[g->tour_p++] = id;
    g->v[id] = 1;
    printf("%d ", id + 1);
    fprintf(output_file,"%d\n", id + 1);

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
    free(g->tour);
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

static void print_matrix_adj(MatrixAdj *m, int size)
{
    int N = size;

    for (int i = 0; i < N - 1; i++)
    {
        int index = (i * (2 * N - (i + 1))) / 2;
        printf("[ ");
        for (int j = 1 + i; j < N; j++)
        {
            printf("%d ", m[index]);
            index += 1;
        }
        printf("]\n");
        for (int k = 0; (k < i + 1) && i < N - 2; k++)
        {
            printf("--");
        }
    }
}

static void insert_matrix_adj(MatrixAdj *m, int size, int i, int j, int value)
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

// void testa_matrix(){
//     MatrixAdj * m = init_matrix_adj(10);

//     //int ret = get_matrix(minhaMatrix, 4 , 3, 5);
//     //printf("%d", ret);

//     // 9 0 troca pra => 0 9
//     insert_matrix_adj(m, 10, 9, 0, 1);

//     print_matrix_adj(m, 10);

//     free_matrix_adj(m);
// }