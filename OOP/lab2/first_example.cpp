using namespace std;

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_VALUE 100

int **genRandMatrix(int size){
    int **matrix = new int*[size];

    srand(time(NULL));
    for (int i=0; i<size; i++){
        matrix[i] = new int[size];
        for (int j=0; j<size; j++){
            matrix[i][j] = rand() % MAX_VALUE;
        }
    }
    return matrix;
}

void get_n(int *n){
    scanf("%d", n);
}

void destroy_matrix(int **matrix, int n){
    for (int i=0; i<n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

// 0 1 2 3
// 1 1 2 3
// 2 1 2 3
// 3 1 2 3


// k step = 1, 2, 3, 4
// 

void add_element_to_arr(int **matrix, int y, int x, int *step_index, int *arr){
    arr[(*step_index)] = matrix[y][x];
    (*step_index)++;
}

void add_el_right_diag(int **matrix, int n, int *result_arr, int *step_index){
    int y = 0; int x = n - 1;
    int k = 1;
    
    int y_help;
    int x_help;

    for (; x != 0; x--){
        x_help = x;
        y_help = y;

        for (int i=0; i<k; i++){
            result_arr[(*step_index)] = matrix[y_help][x_help];
            (*step_index)++;
            x_help++;
            y_help++;
        }
        k++;
    }

    y = 0; x = 0;
    k = n;

    for (; y != n; y++){
        x_help = x;
        y_help = y;

        for (int i=0; i<k; i++){
            result_arr[(*step_index)] = matrix[y_help][x_help];
            (*step_index)++;
            y_help++;
            x_help++;
        }
        k--;
    }
}

void add_el_left_diag(int **matrix, int n, int *result_arr, int *step_index){
    int y = 0; int x = 0;
    int x_step;
    int y_step;

    int k = 1;
    
    for (; x != n - 1; x++){
        x_step = x;
        y_step = y;

        for (int i=0; i<k; i++){
            add_element_to_arr(matrix, y_step, x_step, step_index, result_arr);
            x_step--;
            y_step++;
        }
        k++;
    }
    
    x = n - 1; y = 0;
    k = n;

    for (; y != n; y++){
        x_step = x;
        y_step = y;

        for (int i=0; i<k; i++){
            add_element_to_arr(matrix, y_step, x_step, step_index, result_arr);
            x_step--;
            y_step++;
        }
        k--;
    }

}

void add_el_center_spiral(int **matrix, int n, int *result_arr, int *step_index){
    int y = n / 2; int x = n / 2;
    
    int step = 1;
    int k = 0;

    int kol_step = 0;
    // u - up
    // l - left
    // r - right
    // d - down
    char orient = 'u';

    while (kol_step != n * n){
        if (orient == 'u'){
            for (int i=0; i<step; i++){
                add_element_to_arr(matrix, y, x, step_index, result_arr);
                kol_step++;
                y--;
            }
            if (kol_step == n * n){
                break;
            }
            orient = 'l';
        }
        else if (orient == 'l'){
            for (int i=0; i<step; i++){
                add_element_to_arr(matrix, y, x, step_index, result_arr);
                kol_step++;
                x--;
            }
            if (kol_step == n * n){
                break;
            }
            orient = 'd';
        }
        else if (orient == 'd'){
            for (int i=0; i<step; i++){
                add_element_to_arr(matrix, y, x, step_index, result_arr);
                kol_step++;
                y++;
            }
            if (kol_step == n * n){
                break;
            }
            orient = 'r';
        }
        else if (orient == 'r'){
            for (int i=0; i<step; i++){
                add_element_to_arr(matrix, y, x, step_index, result_arr);
                kol_step++;
                x++;
            }
            if (kol_step == n * n){
                break;
            }
            orient = 'u';
        }
        k++;
        if (k % 2 == 0){
            step++;
        }
    }
}

void add_el_left_spiral(int **matrix, int n, int *result_arr, int *step_index){
    int y = 0;
    int step = 1;

    int y_step; int x_step;
    for (; y<n; y++){
        for (int x=0; x<step; x++){
            add_element_to_arr(matrix, y, x, step_index, result_arr);
        }
        y_step = y - 1;
        x_step = step - 1;
        for (; y_step!=-1; y_step--){
            add_element_to_arr(matrix, y_step, x_step, step_index, result_arr);
        }
        step++;
    }
}

void print_matrix(int **matrix, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int n;
    get_n(&n);

    int **matrix = genRandMatrix(n);
    int *result_arr = new int[n * n * 4];
    int step_index = 0;

    add_el_right_diag(matrix, n, result_arr, &step_index);
    add_el_left_diag(matrix, n, result_arr, &step_index);
    add_el_center_spiral(matrix, n, result_arr, &step_index);
    add_el_left_spiral(matrix, n, result_arr, &step_index);

    print_matrix(matrix, n);
    printf("\n");

    int k = 1;
    for (int i=0; i<n*n*4; i++){
        if (i == n*n*k) {
            printf("\n");
            k++;
        }
        printf("%d ", result_arr[i]);
    }
    printf("\n");

    destroy_matrix(matrix, n);
    delete[] result_arr;
    return 0;
}