using namespace std;

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int size_matrix;

int **genRandMatrix(int size, int maxValue){
    int **arr = new int*[size];

    srand(time(NULL));
    for (int i=0; i<size; i++){
        int row_size = rand()%10;
        arr[i] = new int[row_size + 1];
        arr[i][0] = row_size;

        for (int j=1; j<row_size + 1; j++){
            arr[i][j] = rand()%maxValue;
        }
    }
    return arr;
}

void print(int **matrix){
    printf("%d\n", size_matrix);
    for (int j=0; j<size_matrix; j++){
        printf("%d: ", matrix[j][0]);
        for (int i=1; i<matrix[j][0] + 1; i++){
            if (i + 1 == matrix[j][0] + 1) {
                printf("%d", matrix[j][i]);
            }
            else {
                printf("%d ", matrix[j][i]);
            }
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    int size = rand()%10;
    size_matrix = size;

    int maxValue = 100;
    int **matrix = genRandMatrix(size, maxValue);
    print(matrix);

    for (int i=0; i<size_matrix; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}