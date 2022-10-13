//
// Created by user on 10/7/2022.
//
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Used for generic array
#define     element(arr, size, i)                                 (arr + (size*i) )

// Used for heap
#define     property(arr, size, i, j, compare)                    ( compare(element(arr, size, i),element(arr, size, j) ) )

// Used for max heap
#define     max_property_satisfied(arr, size, i, j, compare)      ( property(arr, size, i, j, compare) > 0 )

// Used for min heap
#define     min_property_satisfied(arr, size, i, j, compare)      ( property(arr, size, i, j, compare) < 0 )


static long long fast_log2(long long n){
    /*long long cnt = 0;
    if(n == 1){
        return 0;
    }
    else if(n == 0){
        return (long long)INFINITY;
    }
    while(n > 0){
        n >>= 1LL;
        cnt++;
    }
    return cnt;
    */
   return floor(log2(n));
}


// from:
// https://www.programmingalgorithms.com/algorithm/intro-sort/c/
static long long partition(long long left, long long right, void* arr, int size, size_t element_size, int(*compare)(void* x, void* y)){
    char* pivot = malloc(element_size);
    if(pivot == NULL){
        perror("PIVOT IS NULL");
        exit(1);
    }
    memcpy(pivot, element(arr, element_size, right), element_size);

    char* temp = malloc(element_size);
    if(temp == NULL){
        perror("PIVOT IS NULL");
        exit(1);
    }

    char* temp2 = malloc(element_size);
    if(temp2 == NULL){
        perror("TEMP2 IS NULL");
        exit(1);
    }
    long long i = left;

    /*char* data = malloc(element_size);
    if(data == NULL){
        perror("DATA IS NULL");
        exit(1);
    }
    */
    for(long long j = left; j < right; ++j){
        memcpy(temp2, element(arr, element_size, j), element_size);
        if(compare(temp2, pivot) <= 0){
            gen_swap(element(arr, element_size, i), element(arr, element_size, j), element_size);
            i++;
        }
    }

    memcpy(element(arr, element_size, right), element(arr, element_size, i), element_size);
    memcpy(element(arr, element_size, i), pivot, element_size);

    free(pivot);
    free(temp);
    free(temp2);

    return i;
}


// from
// https://www.mygreatlearning.com/blog/heap-sort/
static void sift_down(long long idx, long long end, void* arr, int size, size_t element_size, int(*compare)(void* x, void* y)){
    size_t n = end+1;
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

// from:
// https://rosettacode.org/wiki/Sorting_algorithms/Heapsort
static void heapify(void *arr, int size, size_t element_size, int(*compare)(void * x, void * y)){
    long long n = size;
    long long start = ((n-2)/2);
    while(start >= 0){
        sift_down(start, n-1, arr, size, element_size, compare);
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
void insertion_sort(void *arr, int size, size_t element_size, int(*compare)(void * x, void * y)){

    int i , j;
    char* key = malloc(element_size);
    int n = size;
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

// from:
// https://www.youtube.com/watch?v=JNQmKZE7blY
void heap_sort(void *arr, int size, size_t element_size, int(*compare)(void * x, void * y)){
    //size_t n = data_size/element_size;
    long long n = size;
    heapify(arr, size, element_size, compare);
    long long end = n-1;
    while(end > 0){
        gen_swap(element(arr, element_size, 0), element(arr, element_size, end), element_size);
        end--;
        sift_down(0, end, arr, size, element_size, compare);
    }
}

// from:
// https://www.programmingalgorithms.com/algorithm/intro-sort/c/
// TODO: Make a iterative version instead
void rec_quick_sort(long long left, long long right, void* arr, int size, size_t element_size, int(*compare)(void* x, void* y)){
    if(left < right){
        long long q = partition(left, right, arr, size, element_size, compare);
        rec_quick_sort(left, q - 1, arr, size, element_size, compare);
        rec_quick_sort(q+1, right, arr, size, element_size, compare);
    }
}

// TODO:    MEXER NESSA MERDA!
// from:
// https://www.programmingalgorithms.com/algorithm/intro-sort/c/
void sort(void* arr, int left, int right, int size, size_t element_size, int(*compare)(void* x, void* y)){
    long long n = size/element_size;
    //long long last = n - 1;
    long long partition_size = partition(left, right, arr, size, element_size, compare);
    if( partition_size < 16){
        fprintf(stdout, "INSERTION SORT:\n");
        insertion_sort(arr, size, element_size, compare);
    }
    else if(partition_size > (2LL * fast_log2(n) )) {
        fprintf(stdout, "HEAP SORT:\n");
        heap_sort(arr, size, element_size, compare);
    }
    else{
        fprintf(stdout, "RECURSAO:\n");
        int mid = left + (right-left)/2;
        //pivot =
        sort(arr, left, mid, size, element_size, compare);
        sort(arr, mid+1, right, size, element_size, compare);
        //fprintf(stdout, "QUICK SORT:\n");
        //rec_quick_sort(0, last, arr, size, element_size, compare);
    }
}