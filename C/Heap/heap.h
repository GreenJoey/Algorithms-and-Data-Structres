#ifndef HEAP_H
#define HEAP_H

#define DEBUG
#include <stdlib.h>
#include <stdbool.h>


typedef struct _heap {
    int length;
    int *store;
    int next_free;
} heap_t;


heap_t *new_heap(int initial_size);
void insert(heap_t *heap, int data);
int pop(heap_t *heap);
int peek(heap_t *heap);


#endif
