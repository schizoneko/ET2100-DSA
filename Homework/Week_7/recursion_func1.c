#include "recursion_utils.h"

int sum_of_squares(int n) {
    if (n == 1) return 1;
    return n * n + sum_of_squares(n - 1);
}

int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

int count_digits(int n) {
    if (n < 10) return 1;
    return 1 + count_digits(n / 10);
}

bool is_palindrome(const char *str, int left, int right) {
    if (left >= right) return true;
    if (str[left] != str[right]) return false;
    return is_palindrome(str, left + 1, right - 1);
}
