#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define DECLARE_LINKED_LIST(type, typename) \
typedef struct {                            \
    type data[MAX];                         \
    typename##* next;                       \
} typename;                                 \
                                            \


#endif