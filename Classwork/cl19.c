#include <stdio.h>
#include <stdlib.h>

void hanoi_tower(int a, char A, char B, char C) {
    if (a == 1) {
        printf("Move disk 1 from %c to %c\n", A, B);
        return;
    }

    hanoi_tower(a - 1, A, C, B);  
    printf("Move disk %d from %c to %c\n", a, A, B);
    hanoi_tower(a - 1, C, B, A);
}

int sum(int n) {
    if (n == 1)
        return n;
    return n + sum(n - 1);
}

int find_smallest(int arr[], int n) {
    if (n == 1)
        return arr[0];

    int smallest_rest = find_smallest(arr, n - 1);
    return (arr[n - 1] < smallest_rest) ? arr[n - 1] : smallest_rest;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int sum_number(int n) {
    if (n < 10)
        return n;
    return (n % 10) + sum_number(n / 10);
}

void reverse_string(char *str, int left, int right) {
    if (left >= right) return;

    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    reverse_string(str, left + 1, right - 1);
}

void reverse_string2(char *str) {
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Assign names to the rods
    char A = 'A', B = 'B', C = 'C';

    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    hanoi_tower(n, A, B, C);

    return 0;
}