#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

#include "ListaGen.h"

struct listGen{
    node * begin;
    node * end;
    int size;
};

struct node {
    void * info;
    node * next;
};


ListGen* init_list_gen(void){
    ListGen* l = (ListGen*)malloc(sizeof(ListGen));
    l->begin = NULL;
    l->end = NULL;

    l->size =0;

    return l;
}

void insert_list_gen(ListGen* l, void * info){
    node * n = (node*)malloc(sizeof(node));

    n->info = info;
    n->next = l->begin;
    l->begin = n;

    if(l->end == NULL){
        l->end = n;
    }

    l->size ++;

    return;

}

void * remove_list_gen(ListGen* l, void * key, int (*cmp)(void * info, void * key)){
    if(l->size ==0) return NULL;
    node* p = l->begin, * ant = NULL;

    while(p){
        if(cmp(p->info, key) ==0 ){
            break;
        }
        ant = p;
        p = p->next;
    }

    if(p == NULL){
        return NULL;
    }

    void * ret = p->info;

    if(p == l->begin && p == l->end){
        l->begin = l->end = NULL;
    }else if (p == l->begin){
        l->begin = l->begin->next;
    }else if(p == l->end){
        l->end = ant;
        ant->next = NULL;
    }else {
        ant->next = p->next;
    }

    free(p);

    l->size --;

    return ret;


}


void print_list_gen(ListGen* l, void (*print_info)(void * info)){
    node* p = l->begin;
    printf("[ ");
    while(p){
        print_info(p->info);
        p = p->next;
    }
    printf("]");
    return;
}


void * remove_first_list_gen(ListGen* l){
    if(l->size ==0) return NULL;
    node * p = l->begin;

    l->begin =l->begin->next;

    if(p == l->end){
        l->end = NULL;
    }

    l->size --;

    void * ret = p->info;
    free(p);
    return ret;

}


void free_list_gen(ListGen * l){
    node * p = l->begin, *ant = NULL;
    while(p){
        ant = p;
        p = p->next;
        free(ant);
    }

    free(l);

    return ;
}

void free_info_plus_list_gen(ListGen * l, void (*free_info)(void * info)){
    node * p = l->begin, *ant = NULL;
    
    while(p){
        ant = p;
        p = p->next;
        free_info(ant->info);
        free(ant);
    }

    free(l);

    return ;
}