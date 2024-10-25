#include <stdio.h>
#include <string.h>

void zero(int *a, int n){
    for (int i = 0; i < n; i++){
        if (a[i] == 0){
            printf("nam khong co nguoi duoc sinh ra la: %d\n", i + 1920);
        }
    }
}

void ten(int *a, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (a[i] < 10){
            count += 1;
        }
    }
    printf("so nam co so nguoi duoi 10 tuoi: %d\n", count);
}

void fifty(int *a, int n){
    for (int i = 0; i < n; i++){
        if (a[i] > 50){
            printf("nam co so nguoi tren 50 tuoi: %d\n", i + 1920);
        }
    }
}

int main(){
    int arr[]= {45, 44, 72, 5, 82, 77, 15, 56, 22, 27, 6, 91, 69, 59, 69, 16, 69, 1, 76, 58, 88, 45, 66, 5, 86, 38, 100, 3, 80, 34, 99, 0, 29, 45, 16, 36, 29, 78, 75, 12, 60, 70, 63, 13, 95, 32, 56, 13, 51, 5, 99};
    int n = sizeof(arr)/sizeof(arr[0]);

    zero(arr, n);
    ten(arr, n);
}