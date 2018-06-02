#include <stdio.h>
#include "heap.h"
#define DEBUG

int main() {
    puts("Creating a 10-element heap");
    heap_t *heap = new_heap(10);
    int arr[] = {10, 2, 25, 5, 6};//, 4, 7, 65, 14, 0};
    for(int pos=0; pos<=4; ++pos) {
      printf("Inserting %d\n", arr[pos]);
      insert(heap, arr[pos]);
    }

    for(int pos=1; pos<heap->next_free; ++pos)
      printf("%d ", heap->store[pos]);

    printf("\nPeeked element %d\n", peek(heap));

    printf("\nPopped element %d\n", pop(heap));
    for(int pos=1; pos<heap->next_free; ++pos)
      printf("%d ", heap->store[pos]);

    return 0;
}
