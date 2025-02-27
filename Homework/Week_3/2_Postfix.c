#include "../../inc/header.h"

DECLARE_STACK(double, Stack)

double postfix_Cal(char *c){
    Stack s;
    Stack_init(&s);

    double num = 0.0; // Store the current number (not the decimal part)
    double decimalFactor = 0.1; // Factor to accumulate the decimal factor
    int isNumber = 0; // Flag to indicate we are reading a number
    int isFloat = 0; // Flag to indicate we are reading decimal values

    for (int i = 0; c[i] != '\0'; i++) { // Duyệt qua mảng nhập
        char c2 = c[i];
        
        // If its a blank character -> push the number into the stack
        if (c[i] == ' ') {
            if (isNumber) {
                Stack_push(&s, num);
                num = 0.0;
                decimalFactor = 0.1;
                isNumber = 0;
                isFloat = 0;
            }
            continue;
        }

        // If the character is a digit, accumulate the number
        if (isdigit(c2)) { // The isdigit function check whether the character is a digit or not by checking the value of it in ASCII, it compares the ASCII value of the given character to the range of ASCII value of the characters that represent numeric digit [48, 57] 
            if (isFloat) {
                num += (c2 - '0') * decimalFactor;
                decimalFactor /= 10.0;
            } else {
                num = num * 10 + (c2 - '0');
            }
            isNumber = 1;
        }

        // If the character is a decimal point, set float flag
        else if (c2 == '.') {
            isFloat = 1;
        }

        else {
            // Push the last read number if necessary
            if (isNumber) {
                Stack_push(&s, num);
                num = 0.0;
                decimalFactor = 0.1;
                isNumber = 0;
                isFloat = 0;
            }

            // Pop two elements for operation
            double op2 = Stack_pop(&s);
            double op1 = Stack_pop(&s);
            double result;

            // Perform operation
            switch (c2) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator!\n");
                    return 0;
            }

            Stack_push(&s, result);  // Push result back to stack
        }
    }

    // If a number was still being read, push it to the stack
    if (isNumber) {
        Stack_push(&s, num);
    }

    return Stack_pop(&s); // The final result will be the last value in the stack
}

int main() {
    char str[MAX];

    printf("Enter postfix expression: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    double result = postfix_Cal(str);
    printf("Result: %.4lf\n", result);

    return 0;
}