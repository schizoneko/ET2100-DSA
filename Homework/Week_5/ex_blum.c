#include <stdio.h>
#include <math.h>

int songuyento(int n) {
    if (n < 2) return 0;
    if (n % 4 != 3) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int mangcacsoblum(int b[], int N) {
    int count = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (songuyento(i)) {
            for (int j = i; j <= sqrt(N); j++) {
                if (songuyento(j)) {
                    int blum = i * j;
                    if (blum < N) {
                        b[count++] = blum;
                    }
                }
            }
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (b[i] > b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    int uniqueCount = 1;
    for (int i = 1; i < count; i++) {
        if (b[i] != b[uniqueCount - 1]) {
            b[uniqueCount++] = b[i];
        }
    }
    return uniqueCount;
}

void timkiem(int b[], int size, int N) {
    printf("Các cặp số Blum có tổng cũng là số Blum nhỏ hơn %d:\n", N);
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = b[i] + b[j];
            if (sum < N) {
                int found = 0;
                for (int k = 0; k < size; k++) {
                    if (b[k] == sum) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("(%d, %d) ", b[i], b[j]);
                }
            }
        }
    }
    printf("\n");
}

int kiemtra(int b[], int size, int M) {
    for (int i = 0; i < size; i++) {
        if (b[i] == M) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int N, M;
    printf("Nhập số N: ");
    scanf("%d", &N);
    printf("Nhập số Blum: ");
    scanf("%d", &M);

    int b[1000];  
    int size = mangcacsoblum(b, N);

    printf("Các số Blum nhỏ hơn %d là:\n", N);
    for (int i = 0; i < size; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    timkiem(b, size, N);

    if (kiemtra(b, size, M)) {
        printf("Số Blum %d có tồn tại trong mảng.\n", M);
    } else {
        printf("Số Blum %d không tồn tại trong mảng.\n", M);
    }

    return 0;
}