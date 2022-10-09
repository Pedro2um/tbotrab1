//
// Created by user on 10/7/2022.
//

#ifndef SORT_H
#define SORT_H
#include "Edge.h"
#include <stdlib.h>
void sort(EdgesArray* arr, int total_edges);
void insertion_sort(void *arr, size_t data_size, size_t element_size, int(*compare)(void * x, void * y));
void heap_sort(void *arr, size_t data_size, size_t element_size, int(*compare)(void * x, void * y));
//void quick_sort(void *arr, size_t data_size, size_t element_size, int(*compare)(void * x, void * y));
void gen_swap(void* aa, void* bb, size_t s);
#endif //SORT_H
