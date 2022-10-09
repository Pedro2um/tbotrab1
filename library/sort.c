//
// Created by user on 10/7/2022.
//
#include "sort.h"
#include <stdlib.h>
#include <string.h>


// Used for generic array
#define     element(arr, size, i)                                 (arr + (size*i) )

// Used for heap
#define     property(arr, size, i, j, compare)                    ( compare(element(arr, size, i),element(arr, size, j) ) )

// Used for max heap
#define     max_property_satisfied(arr, size, i, j, compare)      ( property(arr, size, i, j, compare) > 0 )

// Used for min heap
#define     min_property_satisfied(arr, size, i, j, compare)      ( property(arr, size, i, j, compare) < 0 )



// from
// https://www.mygreatlearning.com/blog/heap-sort/

static void sift_down(long long idx, void* arr, size_t data_size, size_t element_size, int(*compare)(void* x, void* y)){
    size_t n = data_size/element_size;
    long long i = idx, j = 0;
    while( 2*i + 1 < n ){
        //troublesome child
        j = 2*i + 1;

        if(2*i + 2 < n && !max_property_satisfied(arr, element_size, j, (2*i + 2), compare)  ){
            j = 2*i + 2;
        }
        if(max_property_satisfied(arr, element_size, i, j, compare)){
            break;
        }
        else{
            gen_swap( element(arr, element_size, i), element(arr, element_size, j) , element_size);
            i = j;
        }
    }
}

static void heapify(void *arr, size_t data_size, size_t element_size, int(*compare)(void * x, void * y)){
    long long n = data_size/element_size;
    long long start = ((n-2)/2);
    while(start >= 0){
        sift_down(start, arr, data_size, element_size, compare);
        start--;
    }
}



// from:
// https://rosettacode.org/wiki/Generic_swap
// swaps bytes
void gen_swap(void* a, void* b, size_t size){
    char* t = malloc(size);
    memcpy(t, a, size);
    memcpy(a, b, size);
    memcpy(b, t, size);
    free(t);
}


// from:
// https://www.geeksforgeeks.org/insertion-sort/
void insertion_sort(void *arr, size_t data_size, size_t element_size, int(*compare)(void * x, void * y)){

    int i , j;
    char* key = malloc(element_size);
    int n = data_size/element_size;
    for(i = 1; i < n; i++){
        memcpy(key, element(arr, i, element_size), element_size);
        //int idx_key = i;
        //key ?
        j = i - 1;
        while (j >= 0 && compare(element(arr, element_size, j), key) > 0 ){
            memcpy(element(arr, (j+1), element_size), element(arr, j, element_size), element_size);
            j--;
        }
        memcpy(element(arr, (j+1), element_size), key, element_size);
    }
    free(key);
}

void heap_sort(void *arr, size_t data_size, size_t element_size, int(*compare)(void * x, void * y)){
    size_t n = data_size/element_size;

    heapify(arr, data_size, element_size, compare);

    long long end = n-1;
    int flag = 0;
    while(end > 0){
        if(!max_property_satisfied(arr, element_size, 0, end, compare)) {
            gen_swap(element(arr, element_size, 0), element(arr, element_size, end), element_size);
            flag = 1;
        }
        end--;
        if(flag == 1) {
            sift_down(0, arr, data_size, element_size, compare);
            flag = 0;
        }

    }

}

void sort(void* arr, size_t data_size, size_t element_size, int(*compare)(void* x, void* y)){
    if(data_size/element_size < 16){
        insertion_sort(arr, data_size, element_size, compare);
    }
    else {
        heap_sort(arr, data_size, element_size, compare);
    }
}