#include <stdio.h>


void print(int *arr, int len) {
    printf("[");
    for(int i=0; i<len; ++i)
        printf("%d ", arr[i]);
    printf("]\n");
}


void merge(int *arr, int low, int high, int mid) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int low[n1], high[n2];

    for(int i=0; i<n1; ++i)
        low[i] = arr[low+i];
    for(int j=0; j<n2; ++j)
        high[j] = arr[min+1+j];
}


void sort(int *arr, int low, int high) {
    if(low < high) {
        int mid = (low+high)/2;

        sort(arr, low, mid);
        sort(arr, mid+1, high);

        merge(arr, low, high, mid);
    }
}


int main() {
    int arr = {9, 7, 1, 6, 4, 8, 2, 5, 3};
    int len = 9;

    print(arr, len);
    sort(arr, 0, len-1);
    print(arr, len);

    return 0;
}
