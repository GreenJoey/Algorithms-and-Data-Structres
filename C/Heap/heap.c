#include <math.h>
#include "heap.h"


heap_t *new_heap(int size) {
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
    heap->length = size+1;
    heap->store = (int *)calloc(heap->length, sizeof(int));
    // We are using index 1 as the root of the tree.
    // So populate index 0 with something huge and
    // Set the next_free to 1 to insert the root element at index 1
    heap->store[0] = 9999999999;
    heap->next_free = 1;

    return heap;
}


void insert(heap_t *heap, int elem) {
    // Track the insertion point of the element and increment the heap's next free slot
    int ins = heap->next_free++;
#ifdef DEBUG
    printf("Inserting to open slot %d\n", ins);
#endif
    heap->store[ins] = elem;
    int pos = (int)ceil((ins-1)/2.0);  // Get the parent index of the inserted element
    int temp;

#ifdef DEBUG
    puts("Calculating final position");
#endif
    while(pos != 0) {
	if(heap->store[pos] > heap->store[ins] && pos != 0) {
	    temp = heap->store[ins];
	    heap->store[ins] = heap->store[pos];
	    heap->store[pos] = temp;
	}
	//else
	//    break;
	printf("%d\n", pos);
	pos = (int)ceil((pos - 1) / 2.0);
    }

#ifdef DEBUG
    printf("Done inserting\n\n");
#endif
}


int peek(heap_t *heap) {
    return heap->store[1];
}



