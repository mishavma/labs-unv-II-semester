using namespace std;

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* genRandArray(int size, int maxValue){
    int *arr = new int[size + 1];
    
    arr[0] = size;

    srand(time(NULL));
    for (int i = 1; i<size + 1; i++)
    {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void print(int* arr){
    printf("%d: ", arr[0]);
    for (int i=1; i<arr[0] + 1; i++){
        if (i + 1 == arr[0] + 1) {
            printf("%d", arr[i]);
        }
        else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int size = rand()%10;
    int maxValue = 100;

    int* arr = genRandArray(size, maxValue);
    print(arr);

    delete[] arr;
    return 0;
}