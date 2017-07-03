#include <stdio.h>
#include <stdbool.h>


bool is_sorted(int *arr, int len) {
    for(int i=0; i<len-1; ++i) {
        if(arr[i] > arr[i+1])
            return false;
    }

    return true;
}


void print(int *arr, int len) {
    printf("Array: ");
    for(int i=0; i<len; ++i)
        printf("%d ", arr[i]);
    printf(". Sorted? %s\n", (is_sorted(arr, len)?"Yes": "No"));
}


void bubble_sort(int *arr, int len) {
    bool done = false;

    while(!done) {
        done = true;

        for(int i=0; i<len-1; ++i) {
            if(arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                done = false;
            }
        }
    }
}


int main() {
    int arr[] = {5, 3, 4, 7, 2, 1};
    int len = 6;
    print(arr, len);
    bubble_sort(arr, len);
    print(arr, len);

    return 0;
}
