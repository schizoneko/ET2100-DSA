#include <stdio.h>
#include <stdlib.h>

void SortColor(int arr[], int n){
    int countRed = 0;
    int countWhite = 0;
    int countBlue = 0;

    for (int i = 0; i <n; i++){
        if (arr[i] == 0){
            countRed++;
        }
        else if (arr[i] == 1){
            countWhite++;
        }
        else
            countBlue++;
    }

    int i = 0;
    while (countRed > 0) {
        arr[i++] = 0;
        countRed--;
    }

    while (countWhite > 0) {
        arr[i++] = 1;
        countWhite--;
    }

    while (countBlue > 0) {
        arr[i++] = 2;
        countBlue--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("NHAP VAO N PHAN TU: ");
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i <= n - 1; i++){
        printf("NHAP A[%d]: ",i);
        scanf("%d",&a[i]);
    }
    
    SortColor(a, n);
    printArray(a, n);

    return 0;
}