#include <stdio.h>


void print(int *arr, int len) {
    printf("[");
    for(int i=0; i<len; ++i)
        printf("%d ", arr[i]);
    printf("]\n");
}


void sort(int *arr, int len) {
    int min = 0;

    for(int i=0; i<len-1; ++i) {
        min = i;
        for(int j=i+1; j<=len; ++j) {
            if(arr[j] < arr[min])
                min = j;
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;


        print(arr, len+1);
    }
}


int main() {
    int arr[9] = {9, 7, 1, 3, 2, 8, 4, 6, 5};
    int len = 9;

    print(arr, len);
    sort(arr, len-1);
    print(arr, len);

    return 0;
}
