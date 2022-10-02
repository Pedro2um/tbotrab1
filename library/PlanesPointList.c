#include "PlanesPointList.h"

static void _print_planes_point(void *p);

static void _free_planes_point(void *p);

PlanesPointList* pp_list_init(){
    return init_list_gen();
}

void pp_list_insert(PlanesPointList* l, PlanesPoint *pp){
    insert_list_gen(l, pp);
}

void pp_list_print(PlanesPointList* l){
    print_list_gen(l, &_print_planes_point);
}

void pp_list_free(PlanesPointList * l){
    free_info_plus_list_gen(l, &_free_planes_point);
}

static void _print_planes_point(void *p){
    print_planes_point(p);
}

static void _free_planes_point(void *p){
    free_planes_point(p);
}