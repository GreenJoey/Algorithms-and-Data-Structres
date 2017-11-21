#include <stdio.h>


void print(int *arr, int len) {
    printf("[");
    for(int i=0; i<len; ++i)
        printf("%d ", arr[i]);
    printf("]\n");
}


void sort(int *arr, int len) {
    for(int i=0; i<len; ++i) {
        for(int j=i+1; j<len; ++j) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            printf("i=%d\n", i);
            print(arr, len);
        }
    }
}


int main() {
    int arr[4] = {9, 7, 1, 3};
    int len = 4;

    print(arr, len);
    sort(arr, len);
    print(arr, len);

    return 0;
}
