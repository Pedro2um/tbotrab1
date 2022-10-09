/*#include <stdio.h>
#include <stdlib.h>

#define swap(x, y) if(1){int aux = x; x = y; y = aux;}

int * init_matrix(int N){
    int new_tam = N*(N-1);
    new_tam/=2;

    return (int*)calloc(sizeof(int)*new_tam, 1);
}

int get_matrix(int * matrix, int i , int j, int N){
    if(i == j) return 0;
    if(i > j){
        swap(i, j);
    }

    int index = (i*(2*N - (i+1)))/2 + (j - 1 - i);

    return matrix[index];


}

void printa_matrix(int * matrix, int N){
   

    for (int i =0; i < N -1; i ++){

        int index = (i*(2*N - (i+1)))/2;
        printf("[ ");
        for(int j = 1 + i; j < N; j++){
            printf("%d ", matrix[index]);
            index += 1;
        }
        printf("]\n");
        
        for(int k =0; (k < i + 1) && i < N -2; k ++){
            printf("--");
        }
    }
}

void libera_matrix(int * matrix){
    free(matrix);
    return;
}

void insert_matrix(int * matrix, int i, int j, int value,int N){
    if(i == j) return;
    if(i > j){
        swap(i, j);
    }
    int index = (i*(2*N - (i+1)))/2 + (j - 1 - i);
    matrix[index] = value;
    return;
}


int main(void){
    int * minhaMatrix = init_matrix(10);

    //int ret = get_matrix(minhaMatrix, 4 , 3, 5);
    //printf("%d", ret);
    
    insert_matrix(minhaMatrix, 9, 0, 1, 10); // 9 0 troca pra => 0 9

    printa_matrix(minhaMatrix, 10);


    libera_matrix(minhaMatrix);
    return 0;
}
 */