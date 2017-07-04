#include <stdio.h>


int swap(int *pos1, int *pos2) {
    int temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}


int print(int *arr, int len) {
    for(int i=0; i<len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low-1);

    for(int j=low; j<high; ++j) {
        if(arr[j] <= pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[++i], &arr[high]);

    return i;
}


void sort(int *arr, int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        sort(arr, low, p-1);
        sort(arr, p+1, high);
    }
}


int main() {
    int arr[6] = {10, 7, 8, 9, 1, 5};
    int len = 6;

    sort(arr, 0, len-1);
    print(arr, len);
}
