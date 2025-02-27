#include "../../inc/header.h"

DECLARE_STACK(char, Stack)

bool validParenthesis(char *c) {
    // We declare the stack inside the function because this stack is like a buffer, we only care about the result (empty or not after pop and push) not the content in it
    Stack s;
    Stack_init(&s);

    // Here we use a for loop to loop through the string input from the user, if the character is "(", push it onto the stack and do the pop with ")" 
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == '(') {
            Stack_push(&s, '('); // Nếu là tạo hàm mà truyền vào có con trỏ Stack *s, thì các hàm bên trong không cần dùng tới biến địa chỉ & mà sẽ dùng thẳng luôn s, nhưng lúc đấy Stack của mình sẽ phải khai báo trong hàm main
        } 
        else if (c[i] == ')') {
            if (Stack_empty(&s)) {
                return false;
            } // Always check if the stack is empty or not first before pop
            Stack_pop(&s);
        }
    }

    return Stack_empty(&s); // Hàm bool trả kết quả true or false, và cái mình quan tâm sẽ là việc cái stack chứa "(" có empty hay k
}

int main() {
    char buf[MAX];

    printf("Enter the string:\n");
    scanf("%s", buf);

    // Check the buf
    if (validParenthesis(buf)) {
        printf("Valid!");
    }
    else printf("Invalid!");

    return 0;
}