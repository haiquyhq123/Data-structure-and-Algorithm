#include <stdio.h>
#include <stdlib.h>
int** initialize2DArrayByPointer(int row, int col){
    int** Use2DArray = (int**)malloc(row*sizeof(int*));
    if(Use2DArray==NULL){
     fprintf(stderr, "Memory allocation for matrix rows failed\n");
        return NULL;
    }
    for(int i =0; i<row; i++){
        Use2DArray[i] = (int*)malloc(col*sizeof(int));
    }
    return Use2DArray;
}
void freeMemory2DArray(int** Use2DArray, int row){
    for(int i =0; i<row;i++){
        free(Use2DArray[i]);
    }
}
void displayArray(int** Use2DArray, int row, int col){
    for(int i = 0; i<5; i++){
        for(int j =0; j<5;j++){
            printf("%d ",Use2DArray[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int** Use2DArray = initialize2DArrayByPointer(5,5);
    for(int i = 0; i<5; i++){
        for(int j =0; j<5;j++){
            Use2DArray[i][j] = 1;
        }
    }
    displayArray(Use2DArray,5,5);
    freeMemory2DArray(Use2DArray,5);
    return 0;
}