//
// Created by user on 10/7/2022.
//

#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
void sort(void* arr, int left, int right, int size, size_t element_size, int(*compare)(void* x, void* y));
void insertion_sort(void *arr, int size, size_t element_size, int(*compare)(void * x, void * y));
void heap_sort(void *arr, int size, size_t element_size, int(*compare)(void * x, void * y));
//void quick_sort(void *arr, int size, size_t element_size, int(*compare)(void * x, void * y));
void gen_swap(void* aa, void* bb, size_t s);
#endif //SORT_H
