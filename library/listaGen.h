#ifndef LISTA_GEN_H
#define LISTA_GEN_H

#include <stdio.h>
#include <stdlib.h>


typedef struct listGen ListGen;

ListGen* init_list_gen(void);

void insert_list_gen(ListGen* l, void * info);

void * remove_list_gen(ListGen* l, void * key, int (*cmp)(void * info, void * key));

void * remove_first_list_gen(ListGen* l);

void print_list_gen(ListGen* l, void (*print_info)(void * info));

void free_info_plus_list_gen(ListGen * l, void (*free_info)(void * info));

void free_list_gen(ListGen * l);


#endif 