//
// Created by user on 10/7/2022.
//
#include "sort.h"
#include "Edge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Used for generic array
#define     element(arr, size, i)                                 (arr + (size*i) )

// Used for heap
#define     property(arr, size, i, j, compare)                    ( compare(element(arr, size, i),element(arr, size, j) ) )

// Used for max heap
#define     max_property_satisfied(arr, size, i, j, compare)      ( property(arr, size, i, j, compare) > 0 )

// Used for min heap
#define     min_property_satisfied(arr, size, i, j, compare)      ( property(arr, size, i, j, compare) < 0 )

struct binary_heap{
    EdgesArray* h;
    int n;
    int MAX;
};

typedef struct binary_heap binary_heap;

//size should be a power of two >= original array
static binary_heap* new_binary_heap(int size){
    binary_heap* new_heap = calloc(1, sizeof(binary_heap));
    if(new_heap==NULL) {
        fprintf(stderr,"ERROR, NEW HEAP IS NOT ALLOCATED\n");
        exit(1);
    }
    new_heap->n = 0;
    new_heap->MAX = size;
    //new_heap->h = malloc(size*sizeof(Edge*));
    new_heap->h = init_edges_array(size);
    if(new_heap->h == NULL){
        fprintf(stderr, "ERROR, H IS NOT ALLOCATED\n");
        exit(1);
    }
    /*for(int i = 0; i < size; i++){
        new_heap->h[i] = NULL;
    }
     */
    return new_heap;
}

static void swap(EdgesArray* h,  int i, int j){
    //evitar BO
   EdgesArray* temp = get_edges_array(h, i);
   unsigned short ida = get_id_a_edge(temp);
   unsigned short idb = get_id_b_edge(temp);
   float w = get_weight_edge(temp);

   EdgesArray* temp2 = get_edges_array(h, j);
   set_edges_array(h, i, get_id_a_edge(temp2), get_id_b_edge(temp2), get_weight_edge(temp2));
   set_edges_array(h, j, ida, idb, w);
}

static void insert(binary_heap* a, EdgesArray* x){

    set_edges_array(a->h, a->n, get_id_a_edge(x), get_id_b_edge(x), get_weight_edge(x));
    //a->h[a->n]=x;
    a->n++;
    if(a->n >= a->MAX) {
        fprintf(stderr, "ERROR, HEAP IS FULL!\n");
        exit(1);
    }

    int i = (a->n)-1;
    while(i > 0 && get_weight_edge(get_edges_array(a->h, i)) < get_weight_edge(get_edges_array(a->h, (i-1)/2 ))){
        swap(a->h, i, (i-1)/2);
        i = (i-1)/2;
    }
}

static EdgesArray* remove_min(binary_heap* a){


    swap(a->h, a->n-1, 0);
    a->n--;

    int i = 0, j= 0;

    //1 >= child
    while( 2*i + 1 < a->n){

        //min between two children
        j = 2*i + 1;
        if( (2*i + 2) < (a->n) &&
        get_weight_edge(get_edges_array(a->h, 2*i+2)) < get_weight_edge(get_edges_array(a->h,j))){
            j = 2*i + 2;
        }
        //keeps the property
        if( get_weight_edge(get_edges_array(a->h, j)) >= get_weight_edge(get_edges_array(a->h, i))){
            break;
        }
        else {

            swap(a->h, j, i);
            i = j;
        }

    }

    return get_edges_array(a->h,a->n);
}


static void delete_binary_heap(binary_heap* a){
    free(a->h);
    free(a);
}

//from:
// https://www.geeksforgeeks.org/smallest-power-of-2-greater-than-or-equal-to-n/
static int nextPowerOf2(int n){
    int count = 0;

    // First n in the below condition
    // is for the case where n is 0
    if (n && !(n & (n - 1)))
        return n;

    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }

    return 1 << count;

}

void sort(EdgesArray * arr, int total_edges){
    int size = nextPowerOf2(total_edges);
    binary_heap* heap = new_binary_heap(size);
    for(int i = 0; i < total_edges; i++){
        insert(heap, get_edges_array(arr, i)); // EdgesArray == edge
    }
    for(int i = 0; i < total_edges; i++){
        EdgesArray* temp = remove_min(heap);
        set_edges_array(arr, i, get_id_a_edge(temp), get_id_b_edge(temp), get_weight_edge(temp));
    }
    delete_binary_heap(heap);

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

static long long maxIdx(void* arr, size_t data_size, size_t element_size, long long idx, long long left, long long right, int(*compare)(void* x, void* y)){

    long long n = (long long)(data_size/element_size);

    if(idx >= n || left >= n){
        return LLONG_MAX;
    }
    char* temp1 = malloc(element_size);
    if(temp1 == NULL){
        perror("DEU RUIM PRO TEMP1!\n");
        exit(1);
    }
    memcpy(temp1, element(arr, idx, element_size), element_size);

    char *temp2 = malloc(element_size);
    if(temp2 == NULL){
        perror("DEU RUIM PRO TEMP2!\n");
        exit(1);
    }
    memcpy(temp2, element(arr, left, element_size), element_size);

    char* temp3 = NULL;

    int flag = 0;

    if(right >= n ) {
        temp3 = malloc(element_size);
        if(temp3 == NULL){
            perror("DEU RUIM PRO TEMP3!\n");
            exit(1);
        }
        memcpy(temp3, element(arr, right, element_size), element_size);
    }
    else flag = 1;

    long long ans = -1;

    if(compare(temp1, temp2) >= 0){
        if( (flag == 1) && compare(temp1, temp3) >= 0){
            ans = idx;
            //return idx;
        }
        else if(flag == 1){
            ans = right;
            //return right;
        }
        else{
            ans = idx;
            //return idx;
        }
    }
    else{
        if( (flag == 1) && compare(temp2, temp3) >= 0){
            ans = left;
            //return left;
        }
        else if(flag == 1){
            ans = right;
            //return  right;
        }
        else{
            ans = left;
            //return left;
        }
    }

    free(temp1);
    free(temp2);
    if(temp3 != NULL) free(temp3);
    return ans;
}





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

void heap_sort(void *arr, size_t data_size, size_t element_size, int(*compare)(void * x, void * y)){
    size_t n = data_size/element_size;

    heapify(arr, data_size, element_size, compare);
    //puts("AQUI DEU BOM!");
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
