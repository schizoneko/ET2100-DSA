//Basic Sort Functions

#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > temp){
            arr[j] = arr[j - 1];
            j --;
        }
        arr[j] = temp;
        printArray(arr, n);
    }
}

void BubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
        printArray(arr, n);
    }
}

void SelectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int temp = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[temp]){
                temp = j;
            }
        }
        swap(&arr[temp], &arr[i]);
        printArray(arr, n);
    }
}

void QuickSort(int arr[], int start, int end){
    if (start >= end) return;
    int pivot = arr[start];
    int i = start;
    int j = end;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    QuickSort(arr, start, j);
    QuickSort(arr, i, end);
}

int main(){
    int n;
    printf("Nhap vao n phan tu: ");
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i <= n - 1; i++){
        printf("Nhap a[%d]: ",i);
        scanf("%d",&a[i]);
    }

    //BubbleSort(a, n);
    //printArray(a, n);

    //InsertionSort(a, n);
    //printArray(a, n);

    //SelectionSort(a, n); 
    //printArray(a, n);

    //QuickSort(a, 0, n - 1);
    //printArray(a, n);

    return 0;
}