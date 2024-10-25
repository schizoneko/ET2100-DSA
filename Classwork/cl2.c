#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = n - 1; j > i; j--){
            if (arr[j] < arr[j - 1]){
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}



void print_array(int arr[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
}