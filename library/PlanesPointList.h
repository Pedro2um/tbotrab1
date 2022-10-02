#ifndef PPLIST_H
#define PPLIST_H

#include "ListaGen.h"
#include "PlanesPoint.h"

typedef ListGen PlanesPointList;

PlanesPointList *pp_list_init();

void pp_list_insert(PlanesPointList *l, PlanesPoint *pp);

void pp_list_print(PlanesPointList *l);

void pp_list_free(PlanesPointList *l);

#endif