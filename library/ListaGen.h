#ifndef LISTA_GEN_H
#define LISTA_GEN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct iterator Iterator;
typedef struct listGen ListGen;

// inicia uma lista generica sem nenhum elemento 
ListGen* init_list_gen(void);

//insere um ponteiro já alocado na lista
void insert_list_gen(ListGen* l, void * info);

//remove o elemento da lista se, passando este com a chave para a funcao de callback, o resultador é 0; caso o elemento não exista, é retornado null
void * remove_list_gen(ListGen* l, void * key, int (*cmp)(void * info, void * key));

//remove o primeiro elemento da lista e o retorna, caso a lista esteja vazia, é retornado nulo
void * remove_first_list_gen(ListGen* l);

//printa a lista generica de acordo com a especificação de impressao passada para cada ponteiro de cada elemento na funcao de callback
void print_list_gen(ListGen* l, void (*print_info)(void * info));

//libera toda a lista, inclusive os elementos armazenados dentro de seus nós
void free_info_plus_list_gen(ListGen * l, void (*free_info)(void * info));

//libera somente a lista, e nao os elementos armazenados
void free_list_gen(ListGen * l);

Iterator* get_iterator_list_gen(ListGen* l );

void advance_iterator(Iterator* t);

void free_iterator(Iterator* t);

void* get_current_by_iterator(Iterator* t);

int its_end_iterator(Iterator* t);


#endif 