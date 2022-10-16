#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "./library/Dict.h"
#include "./library/io.h"
#include "./library/mst.h"
#include "./library/PlanesPoint.h"
#include "./library/Graph.h"

int main(int argc, char *argv[])
{
    //verifica se parametros nao foram passados para o programa corretamente 
    if(argc <= 1){
        fprintf(stderr, "ERROR, NO ARGV [1]!\n");
        exit(1);
    }

    //criando dicionário
    Dict d;
    dict_init(d);

    // lê os dados e insere no dicionário
    read_tsp_data(d, argv[1]);
    
    //resgata a dimenção armazenada no dicionário 
    int n = *((int *) dict_get(d, DIM_KEY));

    //calcula a quantidade de arestas que podem ser geradas com a quantidade 'n', calcula as arestas 
    int total_edges = ceil(n * (n - 1) / 2.0);
    EdgesArray *e = calculate_edges(d, total_edges);
    free_plane_points_array(dict_get(d, COORD_KEY));    
    //ordena o vetor de arestas gerado
    sort_edges_array(e, total_edges);

    //cria o arquivo com cabeçalho para .mst
    FILE* mst_file = write_header(d, "saidas", "MST");

    //retorna o grafo que representa a arvore geradora minima
    // imprime, também, as arestas da árvore no arquivo passado 
    Graph* minimum_graph = minimum_spanning_tree(e, total_edges, n, mst_file);
    free_edges_array(e);  
    fprintf(mst_file,"EOF\n");
    fclose(mst_file);

    //cria um arquivo com cabeçaho para .tour
    FILE* tour_file = write_header(d ,"saidas", "TOUR");    
    //libera o dicionário
    dict_delete(d);
    //deep-first search aplicada no grafo da que representa a árvore geradora mínima
    //é printado no arquivo passado o caminho percorrido
    dfs(minimum_graph, tour_file);
    fprintf(tour_file,"EOF\n");

    //liberando estruturas e fechando arquivos 
    fclose(tour_file);
    free_graph(minimum_graph);

    return 0;
}