#include <stdio.h>


void print(int *arr, int len) {
    printf("[");
    for(int i=0; i<len; ++i)
        printf("%d, ", arr[i]);
    printf("]\n");
}


void sort(int *arr, int len) {
    for(int i=0; i<len; ++i) {
        int j = i;
        int toInsert = arr[i];

        while((j>0) && (arr[j-1] > toInsert)) {
            arr[j] = arr[j-1];
            --j;
        }

        arr[j] = toInsert;
        print(arr, len);
    }
}


int main() {
    int arr[8] = {6, 5, 3, 1, 8, 7, 2, 4};
    int len = 8;

    print(arr, len);
    sort(arr, len);

    return 0;
}
