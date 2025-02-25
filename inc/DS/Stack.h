#ifndef STACK_H
#define STACK_H

#define DECLARE_STACK(type, typename)            \
typedef struct {                                 \
    type data[MAX];                              \
    int top;                                     \
} typename;                                      \
                                                 \
void typename##_init(typename *s) {              \
    s->top = -1;                                 \
}                                                \
                                                 \
bool typename##_full(typename *s) {              \
    return s->top == MAX - 1;                    \
}                                                \
                                                 \
bool typename##_empty(typename *s) {             \
    return s->top == -1;                         \
}                                                \
                                                 \
bool typename##_push(typename *s, type value) {  \
    if (typename##_full(s)) return false;        \
    s->data[++(s->top)] = value;                 \
    return true;                                 \
}                                                \
                                                 \
type typename##_pop(typename *s) {               \
    if (typename##_empty(s)) {                   \
        printf("Stack underflow!\n");            \
        exit(1);                                 \
    }                                            \
    return s->data[(s->top)--];                  \
}                                                \
                                                 \
type typename##_peek(typename *s) {              \
    if (typename##_empty(s)) {                   \
        printf("Stack is empty!\n");             \
        exit(1);                                 \
    }                                            \
    return s->data[s->top];                      \
}

#endif // STACK_H