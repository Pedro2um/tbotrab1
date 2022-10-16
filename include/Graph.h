#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph Graph;

/**
 * @brief inicializa a estrutura de grafo
 * 
 * @param N quantidade de vertices do grafo
 * @return Graph* a estrutura de grafo
 */
Graph* init_graph(int N);

/**
 * @brief adiciona uma aresta entre dois vertices
 * 
 * @param g a estrutura de grafo
 * @param id1 o id do primeiro vertice
 * @param id2 o id do segundo vertice
 */
void add_to_adjacency_list_of(Graph* g, unsigned short id1, unsigned short id2);

/**
 * @brief caminha pelo grafo e imprime o caminho no arquivo
 * 
 * @param g a estrutura de grafo
 * @param output_file o arquivo de output do caminho
 */
void dfs(Graph* g, FILE* output_file);

/**
 * @brief libera a memoria alocada para a estrutura de grafo
 * 
 * @param g a estrutura de grafo
 */
void free_graph(Graph* g);

#endif 