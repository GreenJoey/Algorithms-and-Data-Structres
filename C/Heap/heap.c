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


int smallest(heap_t *heap, int pos) {
  int right = 2*pos + 1;  // Calculate the right child index
  int left = 2*pos;  // Calculate the left child index

  if(right > heap->length && left > heap->length)
    return 0;

#ifdef DEBUG
  printf("Right child %d. Left Child %d\n", heap->store[right], heap->store[left]);
#endif

  // Check if the right child is the smaller one, return if true
  if(heap->store[right] < heap->store[left] && heap->store[right] < heap->store[pos])
    return right;

  // Check if the left child is the smaller one, return if true
  else if(heap->store[left] < heap->store[right] && heap->store[left] < heap->store[pos])
    return left;

  // This node is in correct position, return `EXIT` code
  else
    return 0;
}


int pop(heap_t *heap) {
  // In this implementation we track only the next free slot in the heap
  // So the rightmost element can be trivally found from it
  int rightmost_elem = heap->next_free - 1;
#ifdef DEBUG
  printf("The current righmost elemet is %d\n", rightmost_elem);
#endif

  // Popping the smallest element and replacing it with the rightmost one
  int popped_elem = heap->store[1];
#ifdef DEBUG
  printf("Element popped is %d\n", popped_elem);
  printf("Setting temporary root as %d\n", heap->store[rightmost_elem]);
#endif
  heap->store[1] = heap->store[rightmost_elem];  // Set the temporary root
  int pos = 1;

  // Trickling down the element to correct position
#ifdef DEBUG
  puts("Trickling down the temporary root");
#endif
  while(true) {
    int next_pos = smallest(heap, pos);  // Get the smallest child index

    // Check if the returned value is the `EXIT` code
    if(next_pos == 0)
      break;
    else {
#ifdef DEBUG
      printf("Moving %d[%d] to %d[%d]\n", pos, heap->store[pos], next_pos, heap->store[next_pos]);
#endif
      
      // Bubble up the smaller child and trickle down the larger parent
      int temp = heap->store[next_pos];
      heap->store[next_pos] = heap->store[pos];
      heap->store[pos] = temp;
#ifdef DEBUG
      for(int i=1; i<heap->next_free; ++i)
        printf("%d ", heap->store[i]);
#endif
    }
    pos = next_pos;  // Update the current node's index
  }

  return popped_elem;
}
