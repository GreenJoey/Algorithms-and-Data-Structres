#include <stdio.h>
#include <malloc.h>


typedef struct {
	int *arr;
	int top_right;
	int top_left;
} deque_t;


void push_right(deque_t *deque, int data) {
	deque->arr[--deque->top_right] = data;
}

void push_left(deque_t *deque, int data) {
	deque->arr[++deque->top_left] = data;
}

int pop_right(deque_t *deque) {
	return deque->arr[deque->top_right++];
}

int pop_left(deque_t *deque) {
	return deque->arr[deque->top_left--];
}


int main() {
	deque_t deque;
	int length;
	printf("Enter deque length: ");
	scanf("%d", &length);
	deque.arr = (int *)calloc(length, sizeof(int));
	deque.top_left = -1;
	deque.top_right = length;

	int op, data;
	while (1) {
		printf("Operations\n\t1 Push Left\n\t2 Push Rigth\n\t3 Pop Left\n\t4 Pop Right\nChoice: ");
		scanf("%d", &op);

		switch(op) {
			case 1:
				printf("Enter data: ");
				scanf("%d", &data);
				push_left(&deque, data);
				break;
			case 2:
				printf("Enter data: ");
				scanf("%d", &data);
				push_right(&deque, data);
				break;
			case 3:
				printf("Popped data %d\n", pop_left(&deque));
				break;
			case 4:
				printf("Popped data %d\n", pop_right(&deque));
				break;
			default:
				return 0;
		}
	}

	return 0;
}