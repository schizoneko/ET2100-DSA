#include "../../inc/header.h"

DECLARE_STACK(char, Stack)

bool check_Palindrome(char *str) {
    int len = strlen(str);
    Stack s;
    Stack_init(&s);

    // Push first half of the string into the stack
    for (int i = 0; i < len / 2; i++) {
        Stack_push(&s, str[i]);
    }

    // Determine starting index for comparison in the second half
    int start = (len % 2 == 0) ? len / 2 : (len / 2) + 1;

    // Compare second half with s values
    for (int i = start; i < len; i++) {
        if (Stack_pop(&s) != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX];

    printf("Enter a word: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    if (check_Palindrome(str)) {
        printf("The word \"%s\" is a palindrome. Aura++\n", str);
    } else {
        printf("The word \"%s\" is NOT a palindrome! Go KYS\n", str);
    }

    return 0;
}