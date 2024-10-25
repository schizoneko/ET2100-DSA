#include <stdio.h>
#include <string.h>

void MergeArrays(int a[], int m, int n, int p){
    int i = m;
    int j = n + 1;
    while (i < j && j <= p){
        if (a[i] <= a[j]) i++;
        else {
            int x = a[j];
            for (int k = j - 1; k >= i; k--) {
                a[k + 1] = a[k];
            }
            a[i] = x;
            i++;
            j++;
        }
    }
}

void Split(int a[], int first, int last) {
    if (first >= last) return;
    int m = (first + last)/2;
    Split(a, first, m);
    Split(a, m + 1, last);
    MergeArrays(a, first, m, last); 
}

void MergeSort(int a[], int n){
    if (n < 2) return;
    Split(a, 0, n - 1);
}

int main(){
    int a[] = {15, 30, 201, 303};
    int b[] = {5, 7, 10, 27, 98, 121, 204, 308};

    int i;
    int size_a = sizeof(a)/sizeof(a[0]);
    int size_b = sizeof(b)/sizeof(b[0]);

    int arr[size_a + size_b];
    int index = 0;

    for (i = 0; i < size_a; i++){
        arr[index] = a[i];
        index++;
    }

    for (i = 0; i < size_b; i++){
        arr[index] = b[i];
        index++;
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, n);
    print_array(arr, n);

    return 0;
}