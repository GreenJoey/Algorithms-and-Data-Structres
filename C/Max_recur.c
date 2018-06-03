#include <stdio.h>


int max(int *arr, int index) {
    // If the index is 0, the we can trivally 
    // say the max element is in the 0 index
    if(index==0)
        return arr[0];

    // Get the local max in the `index-1` subarray
    int m = max(arr, index-1);

    // Check and return the max between the current `index`
    // and the `index-1` subarray
    return (arr[index] > m) ? arr[index] : m;
}


int main() {
    // Driver program to find the recursively 
    // find the maximum in the array
    int len;
    scanf("%d", &len);

    int arr[len];
    for(int i=0; i<len; ++i)
        scanf("%d", &arr[i]);

    printf("%d\n", max(arr, len-1));

    return 0;
}
